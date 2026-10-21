"""Translate pinned official character AST to native C++ control flow.

This is a build tool. Generated binaries do not load Python or source ASTs.
Unmapped syntax is a generation error, never a skipped statement.
"""
import ast
import hashlib
import json
import pathlib
import sys

def write_generated(path,text):
    if not path.exists() or path.read_text(encoding="utf-8")!=text:path.write_text(text,encoding="utf-8")

ROOT=pathlib.Path(__file__).resolve().parent.parent
COMMIT='0b37b5b79e771297536ff1155db1c23131297558'
SOURCE=ROOT/'source_reference/upstream/master-0b37b5b/src/char'
DEST=ROOT/'src/official/generated'

def quote(value):return json.dumps(value,ensure_ascii=False)

class TranslationError(Exception):pass

class Emitter:
    def __init__(self,name,text):
        self.name=name;self.text=text;self.scope='scope';self.local=set();self.nonlocal_names=set();self.serial=0
        self.methods=[];self.covered=[];self.loop_breaks=[]
    def fail(self,n):raise TranslationError(f'{self.name}:{getattr(n,"lineno",0)}: unmapped {ast.dump(n,include_attributes=False)}')
    def fresh(self,p='tmp'):
        self.serial+=1;return f'{p}_{self.serial}'
    def call(self,function,args=(),keywords=()):
        pack=self.fresh('args');fn=self.fresh('fn')
        parts=[f'auto {fn}={function};',f'Args {pack};']
        for arg in args:
            if isinstance(arg,ast.Starred):parts.append(f'{pack}.spread({self.expr(arg.value)});')
            else:parts.append(f'{pack}.pos({self.expr(arg)});')
        for key in keywords:
            parts.append(f'{pack}.kw({quote(key.arg)},{self.expr(key.value)});' if key.arg else f'{pack}.spread_keywords({self.expr(key.value)});')
        parts.append(f'return invoke({fn},{pack});')
        return '([&]()->V{'+''.join(parts)+'}())'
    def expr(self,n):
        if isinstance(n,ast.Constant):
            if n.value is None:return 'V{}'
            if isinstance(n.value,bool):return 'V(true)' if n.value else 'V(false)'
            if isinstance(n.value,str):return 'V('+quote(n.value)+')'
            if isinstance(n.value,int):return f'V({n.value}LL)'
            if isinstance(n.value,float):return 'V('+repr(n.value)+')'
            self.fail(n)
        if isinstance(n,ast.Name):
            if n.id=='self':return 'self_value()'
            if n.id in self.local or n.id in self.nonlocal_names:return f'{self.scope}->get({quote(n.id)})'
            return f'global({quote(n.id)},{quote(self.name)})'
        if isinstance(n,ast.Attribute):return f'attr({self.expr(n.value)},{quote(n.attr)})'
        if isinstance(n,ast.Subscript):return f'item({self.expr(n.value)},{self.expr(n.slice)})'
        if isinstance(n,ast.Slice):return 'V::slice('+','.join(self.expr(x) if x else 'V{}' for x in (n.lower,n.upper,n.step))+')'
        if isinstance(n,(ast.Tuple,ast.List,ast.Set)):
            factory={ast.Tuple:'tuple',ast.List:'list',ast.Set:'set'}[type(n)]
            if any(isinstance(x,ast.Starred) for x in n.elts):
                tmp=self.fresh('sequence');body=f'V {tmp}=V::{factory}({{}});'
                for x in n.elts:body+=f'extend({tmp},{self.expr(x.value)});' if isinstance(x,ast.Starred) else f'append({tmp},{self.expr(x)});'
                return '([&]()->V{'+body+f'return {tmp};'+'}())'
            return f'V::{factory}({{'+','.join(self.expr(x) for x in n.elts)+'})'
        if isinstance(n,ast.Dict):
            tmp=self.fresh('dictionary');body=f'V {tmp}=V::dict();'
            for k,v in zip(n.keys,n.values):body+=f'dict_update({tmp},{self.expr(v)});' if k is None else f'set_item({tmp},{self.expr(k)},{self.expr(v)});'
            return '([&]()->V{'+body+f'return {tmp};'+'}())'
        if isinstance(n,ast.UnaryOp):return f'unary({quote({ast.Not:"not",ast.USub:"-",ast.UAdd:"+",ast.Invert:"~"}[type(n.op)])},{self.expr(n.operand)})'
        if isinstance(n,ast.BinOp):
            op={ast.Add:'+',ast.Sub:'-',ast.Mult:'*',ast.Div:'/',ast.FloorDiv:'//',ast.Mod:'%',ast.Pow:'**',ast.BitOr:'|',ast.BitAnd:'&',ast.BitXor:'^'}.get(type(n.op))
            if not op:self.fail(n)
            left=self.fresh('left');right=self.fresh('right')
            return f'([&]()->V{{V {left}={self.expr(n.left)};V {right}={self.expr(n.right)};return official::binary({quote(op)},{left},{right});}}())'
        if isinstance(n,ast.BoolOp):
            temp=self.fresh('operand');body=f'V {temp};'
            for v in n.values[:-1]:
                body+=f'{temp}={self.expr(v)};if('+('!' if isinstance(n.op,ast.And) else '')+f'{temp}.truth())return {temp};'
            return '([&]()->V{'+body+f'return {self.expr(n.values[-1])};'+'}())'
        if isinstance(n,ast.Compare):
            a=self.fresh('compare');b=self.fresh('compare');body=f'V {a}={self.expr(n.left)};V {b};'
            names={ast.Eq:'==',ast.NotEq:'!=',ast.Lt:'<',ast.LtE:'<=',ast.Gt:'>',ast.GtE:'>=',ast.Is:'is',ast.IsNot:'is not',ast.In:'in',ast.NotIn:'not in'}
            result=self.fresh('comparison_result');body+=f'V {result};'
            for index,(op,right) in enumerate(zip(n.ops,n.comparators)):
                body+=f'{b}={self.expr(right)};{result}=compare_value({quote(names[type(op)])},{a},{b});'
                if index<len(n.ops)-1:body+=f'if(!{result}.truth())return {result};{a}={b};'
            return '([&]()->V{'+body+f'return {result};'+'}())'
        if isinstance(n,ast.IfExp):return f'({self.expr(n.test)}.truth()?{self.expr(n.body)}:{self.expr(n.orelse)})'
        if isinstance(n,ast.NamedExpr):
            value=self.fresh('assigned');return f'([&]()->V{{V {value}={self.expr(n.value)};{self.assign(n.target,value)}return {value};}}())'
        if isinstance(n,ast.Call):
            if isinstance(n.func,ast.Name) and n.func.id in ('any','all') and len(n.args)==1 and isinstance(n.args[0],ast.GeneratorExp):
                gen=n.args[0];is_all=n.func.id=='all';oldscope,oldlocal=self.scope,self.local
                self.scope=self.fresh('generator_scope');self.local=set(oldlocal)|self.target_names(gen.generators)
                body=f'auto {self.scope}=std::make_shared<Scope>({oldscope});'
                action=f'if({"!" if is_all else ""}{self.expr(gen.elt)}.truth())return V({"false" if is_all else "true"});'
                body+=self.comprehension_loops(gen.generators,action)+f'return V({"true" if is_all else "false"});'
                self.scope,self.local=oldscope,oldlocal
                return '([&]()->V{'+body+'}())'
            return self.call(self.expr(n.func),n.args,n.keywords)
        if isinstance(n,(ast.ListComp,ast.SetComp,ast.DictComp,ast.GeneratorExp)):
            oldscope,oldlocal=self.scope,self.local;self.scope=self.fresh('comprehension_scope');self.local=set(oldlocal)|self.target_names(n.generators)
            result=self.fresh('result');factory='dict' if isinstance(n,ast.DictComp) else 'set' if isinstance(n,ast.SetComp) else 'list'
            body=f'auto {self.scope}=std::make_shared<Scope>({oldscope});V {result}=V::{factory}();'
            action=f'set_item({result},{self.expr(n.key)},{self.expr(n.value)});' if isinstance(n,ast.DictComp) else f'append({result},{self.expr(n.elt)});'
            body+=self.comprehension_loops(n.generators,action)+f'return {result};';self.scope,self.local=oldscope,oldlocal
            return '([&]()->V{'+body+'}())'
        if isinstance(n,ast.Lambda):return self.function_value(n.args,n.body,expression=True)
        if isinstance(n,ast.JoinedStr):
            parts=[]
            for x in n.values:
                if isinstance(x,ast.Constant):parts.append(quote(x.value))
                else:parts.append(f'format_value({self.expr(x.value)},{self.expr(x.format_spec)}.text(),{x.conversion})' if x.format_spec else f'format_value({self.expr(x.value)},"",{x.conversion})')
            return 'V(std::string{}'+''.join('+'+p for p in parts)+')'
        self.fail(n)
    def target_names(self,generators):return {x.id for g in generators for x in ast.walk(g.target) if isinstance(x,ast.Name)}
    def comprehension_loops(self,generators,action):
        if not generators:return action
        g=generators[0];iterator=self.fresh('iterator');value=self.fresh('value')
        body=f'auto {iterator}=official::iterate({self.expr(g.iter)});V {value};while({iterator}.next({value}))'+'{'+self.assign(g.target,value)
        for condition in g.ifs:body+=f'if(!{self.expr(condition)}.truth())continue;'
        return body+self.comprehension_loops(generators[1:],action)+'}'
    def assign(self,target,value):
        if isinstance(target,ast.Name):return f'{self.scope}->{"set_nonlocal" if target.id in self.nonlocal_names else "set"}({quote(target.id)},{value});'
        if isinstance(target,ast.Attribute):return f'set_attr({self.expr(target.value)},{quote(target.attr)},{value});'
        if isinstance(target,ast.Subscript):return f'set_item({self.expr(target.value)},{self.expr(target.slice)},{value});'
        if isinstance(target,(ast.Tuple,ast.List)):
            temporary=self.fresh('unpack');body=f'auto {temporary}=unpack({value},{len(target.elts)});'
            for i,t in enumerate(target.elts):body+=self.assign(t,f'{temporary}[{i}]')
            return body
        self.fail(target)
    def statements(self,items,indent=0):return ''.join(self.statement(n,indent) for n in items)
    def statement(self,n,indent=0):
        pad='    '*indent;self.covered.append((n.lineno,n.end_lineno,type(n).__name__))
        prefix=f'{pad}// {self.name}.py:{n.lineno}\n'
        if isinstance(n,ast.Expr):return prefix+pad+self.expr(n.value)+';\n' if not isinstance(n.value,ast.Constant) else ''
        if isinstance(n,(ast.Assign,ast.AnnAssign)):
            if isinstance(n,ast.AnnAssign) and n.value is None:return ''
            value=self.fresh('value');targets=n.targets if isinstance(n,ast.Assign) else [n.target]
            return prefix+pad+'{V '+value+'='+self.expr(n.value)+';'+''.join(self.assign(t,value) for t in targets)+'}\n'
        if isinstance(n,ast.AugAssign):return prefix+pad+self.assign(n.target,f'official::binary({quote({ast.Add:"+",ast.Sub:"-",ast.Mult:"*",ast.Div:"/",ast.FloorDiv:"//",ast.Mod:"%",ast.BitOr:"|"}[type(n.op)])},{self.expr(n.target)},{self.expr(n.value)})')+'\n'
        if isinstance(n,ast.Return):return prefix+pad+'return '+(self.expr(n.value) if n.value else 'V{}')+';\n'
        if isinstance(n,ast.If):
            body=prefix+pad+'if('+self.expr(n.test)+'.truth()){\n'+self.statements(n.body,indent+1)+pad+'}'
            if n.orelse:body+='else{\n'+self.statements(n.orelse,indent+1)+pad+'}'
            return body+'\n'
        if isinstance(n,ast.While):
            flag=self.fresh('loop_completed') if n.orelse else None
            self.loop_breaks.append(flag);body=self.statements(n.body,indent+1);self.loop_breaks.pop()
            result=prefix+pad+('{bool '+flag+'=true;\n' if flag else '')+pad+'while('+self.expr(n.test)+'.truth()){\n'+body+pad+'}\n'
            if flag:result+=pad+'if('+flag+'){\n'+self.statements(n.orelse,indent+1)+pad+'}}\n'
            return result
        if isinstance(n,ast.For):
            iterator=self.fresh('iterator');value=self.fresh('item')
            flag=self.fresh('loop_completed') if n.orelse else None
            self.loop_breaks.append(flag);body=self.statements(n.body,indent+1);self.loop_breaks.pop()
            result=prefix+pad+'{'+('bool '+flag+'=true;' if flag else '')+'auto '+iterator+'=official::iterate('+self.expr(n.iter)+');V '+value+';while('+iterator+'.next('+value+')){\n'+pad+'    '+self.assign(n.target,value)+'\n'+body+pad+'}\n'
            if flag:result+=pad+'if('+flag+'){\n'+self.statements(n.orelse,indent+1)+pad+'}\n'
            return result+pad+'}\n'
        if isinstance(n,ast.Break):return prefix+pad+((self.loop_breaks[-1]+'=false;') if self.loop_breaks and self.loop_breaks[-1] else '')+'break;\n'
        if isinstance(n,ast.Continue):return prefix+pad+'continue;\n'
        if isinstance(n,(ast.Pass,ast.Nonlocal)):return ''
        if isinstance(n,ast.Raise):return prefix+pad+(f'throw RaisedValue({self.expr(n.exc)});' if n.exc else 'throw;')+'\n'
        if isinstance(n,ast.Assert):return prefix+pad+'if(!'+self.expr(n.test)+'.truth())throw RaisedValue(V("official assertion failed"));\n'
        if isinstance(n,ast.Try):
            if n.orelse:self.fail(n)
            result=prefix+pad+'{\n'
            if n.finalbody:result+=pad+'auto '+self.fresh('finally')+'=on_scope_exit([&](){\n'+self.statements(n.finalbody,indent+1)+pad+'});\n'
            if n.handlers:
                result+=pad+'try{\n'+self.statements(n.body,indent+1)+pad+'}'
                if len(n.handlers)!=1:self.fail(n)
                h=n.handlers[0]
                if h.type and ast.unparse(h.type) not in ('Exception','RuntimeError','BaseException'):self.fail(h)
                result+='catch(const std::exception& official_exception){\n'
                if not h.type or ast.unparse(h.type)!='BaseException':result+=pad+'    rethrow_control_exception(official_exception);\n'
                if h.name:result+=pad+'    '+self.assign(ast.Name(id=h.name,ctx=ast.Store()),'V(official_exception.what())')+'\n'
                result+=self.statements(h.body,indent+1)+pad+'}\n'
            else:result+=self.statements(n.body,indent+1)
            return result+pad+'}\n'
        if isinstance(n,ast.FunctionDef):return prefix+pad+self.assign(ast.Name(id=n.name,ctx=ast.Store()),self.function_value(n.args,n.body))+'\n'
        if isinstance(n,ast.ImportFrom):
            return prefix+''.join(pad+self.assign(ast.Name(id=a.asname or a.name,ctx=ast.Store()),'import_value('+quote(n.module)+','+quote(a.name)+')')+'\n' for a in n.names)
        self.fail(n)
    def function_value(self,args,body,expression=False):
        previous=(self.scope,self.local,self.nonlocal_names)
        outer=self.scope;self.scope=self.fresh('scope')
        nodes=[body] if expression else body
        def bindings(node):
            yield node
            if isinstance(node,(ast.FunctionDef,ast.Lambda)):return
            for child in ast.iter_child_nodes(node):yield from bindings(child)
        binding_nodes=[x for n in nodes for x in bindings(n)]
        nl={v for x in binding_nodes if isinstance(x,ast.Nonlocal) for v in x.names}
        assigned={x.id for x in binding_nodes if isinstance(x,ast.Name) and isinstance(x.ctx,ast.Store)}
        assigned|={x.name for x in binding_nodes if isinstance(x,ast.FunctionDef)}
        assigned|={a.asname or a.name for x in binding_nodes if isinstance(x,ast.ImportFrom) for a in x.names}
        assigned|={x.name for x in binding_nodes if isinstance(x,ast.ExceptHandler) and x.name}
        argnames=[x.arg for x in args.posonlyargs+args.args+args.kwonlyargs]
        if args.vararg:argnames.append(args.vararg.arg)
        if args.kwarg:argnames.append(args.kwarg.arg)
        owned=(assigned|set(argnames))-nl
        self.local=owned|previous[1];self.nonlocal_names=nl
        # Defaults are evaluated in the defining scope, as in the source.
        current_scope=self.scope;current_local=self.local;self.scope=outer;self.local=previous[1]
        positional=args.posonlyargs+args.args
        defaults=['V::missing()']*(len(positional)-len(args.defaults))+[self.expr(x) for x in args.defaults]
        signature='Signature({'+','.join('{'+quote(a.arg)+','+default+'}' for a,default in zip(positional,defaults))+'},'+quote(args.vararg.arg if args.vararg else '')+','+quote(args.kwarg.arg if args.kwarg else '')+',{' + ','.join('{'+quote(a.arg)+','+(self.expr(d) if d else 'V::missing()')+'}' for a,d in zip(args.kwonlyargs,args.kw_defaults))+'})'
        self.scope=current_scope;self.local=current_local
        content=f'auto {self.scope}=bind_arguments(official_args,signature,captured);\n'
        for local in sorted(owned-set(argnames)):content+=f'{self.scope}->set({quote(local)},V::missing());\n'
        content+=('return '+self.expr(body)+';\n') if expression else self.statements(body,1)+'return V{};\n'
        loaded={x.id for node in nodes for x in ast.walk(node) if isinstance(x,ast.Name) and isinstance(x.ctx,ast.Load)}
        free=(loaded & (previous[1]|previous[2]) - owned)|nl
        captured='capture_scope('+outer+',{'+','.join(quote(x) for x in sorted(free) if x!='self')+'})'
        value='V::function([this,captured='+captured+',signature='+signature+'](const Args& official_args)->V{\n'+content+'})'
        self.scope,self.local,self.nonlocal_names=previous
        return value
    def emit(self):
        tree=ast.parse(self.text)
        cls=next(n for n in tree.body if isinstance(n,ast.ClassDef) and n.name==self.name)
        lines=[f'// Generated from official {COMMIT}/src/char/{self.name}.py',f'// SHA256 {hashlib.sha256(self.text.encode()).hexdigest()}',f'void OfficialCharacter::install_{self.name}()'+'{','auto scope=std::make_shared<Scope>();']
        for n in tree.body:
            if isinstance(n,ast.FunctionDef):
                lines.append('// Official module function '+n.name+f', lines {n.lineno}-{n.end_lineno}')
                lines.append('set_global('+quote(n.name)+','+self.function_value(n.args,n.body)+');')
            if isinstance(n,ast.ClassDef) and n.name!=self.name:
                fields=[]
                for member in n.body:
                    if isinstance(member,ast.Assign) and len(member.targets)==1 and isinstance(member.targets[0],ast.Name):fields.append('{'+quote(member.targets[0].id)+','+self.expr(member.value)+'}')
                    elif isinstance(member,ast.Expr) and isinstance(member.value,ast.Constant):pass
                    else:self.fail(member)
                lines.append('set_global('+quote(n.name)+',make_namespace('+quote(n.name)+',{'+','.join(fields)+'}));')
            if isinstance(n,(ast.Assign,ast.AnnAssign)):
                targets=n.targets if isinstance(n,ast.Assign) else [n.target]
                for target in targets:
                    if not isinstance(target,ast.Name):self.fail(n)
                    lines.append('set_global('+quote(target.id)+','+self.expr(n.value)+');')
        for n in cls.body:
            if isinstance(n,ast.FunctionDef):
                key=n.name
                if n.decorator_list:
                    decorators=[ast.unparse(x) for x in n.decorator_list]
                    if decorators==['property']:key='@get:'+key
                    elif decorators==[key+'.setter']:key='@set:'+key
                    else:self.fail(n)
                start=len(self.covered)
                lines.append(f'// Official method {self.name}.{n.name}, lines {n.lineno}-{n.end_lineno}')
                body=self.function_value(n.args,n.body)
                lines.append('register_method('+quote(key)+','+body+','+('true' if self.name=='BaseChar' else 'false')+');')
                self.methods.append(dict(name=n.name,dispatch=key,official_line=n.lineno,official_end=n.end_lineno,statements=len(self.covered)-start))
            elif isinstance(n,(ast.Assign,ast.AnnAssign)):
                targets=n.targets if isinstance(n,ast.Assign) else [n.target]
                for target in targets:
                    if not isinstance(target,ast.Name):self.fail(n)
                    lines.append('set_class_attribute('+quote(target.id)+','+self.expr(n.value)+');')
            elif isinstance(n,ast.Expr) and isinstance(n.value,ast.Constant):pass
            else:self.fail(n)
        lines.append('}')
        return '\n'.join(lines)+'\n'

def main():
    manifest=json.loads((ROOT/'SOURCES.json').read_text(encoding='utf-8-sig'))
    names=['BaseChar']+[r['character'] for r in manifest['characters']]
    DEST.mkdir(parents=True,exist_ok=True)
    reports=[];errors=[]
    for name in names:
        text=(SOURCE/(name+'.py.txt')).read_text(encoding='utf-8-sig');emitter=Emitter(name,text)
        try:result=emitter.emit()
        except Exception as error:errors.append(str(error));continue
        write_generated(DEST/(name+'.inc'),result)
        write_generated(DEST/(name+'.cpp'),'#include "../OfficialCharacter.h"\nnamespace official {\n'+result+'}\n')
        reports.append(dict(character=name,source_sha256=hashlib.sha256(text.encode()).hexdigest(),methods=emitter.methods,statement_count=len(emitter.covered),generated_lines=len(result.splitlines())))
    (ROOT/'.cache/official-translation-coverage.json').write_text(json.dumps(dict(commit=COMMIT,files=reports,errors=errors),ensure_ascii=False,indent=2),encoding='utf-8')
    (DEST/'Declarations.inc').write_text(''.join(f'void install_{name}();\n' for name in names),encoding='utf-8')
    (DEST/'Install.inc').write_text(''.join(('if' if i==0 else 'else if')+f'(class_name_=={quote(name)})install_{name}();\n' for i,name in enumerate(names[1:])),encoding='utf-8')
    enums=[]
    for name in names:
        tree=ast.parse((SOURCE/(name+'.py.txt')).read_text(encoding='utf-8-sig'))
        for n in tree.body:
            if isinstance(n,ast.ClassDef) and n.name=='State':
                pairs=[]
                for x in n.body:
                    if isinstance(x,ast.Assign):pairs.append('{'+quote(x.targets[0].id)+',V('+str(ast.literal_eval(x.value))+'LL)}')
                enums.append('if(module=='+quote(name)+'&&name=="State"){static const V value=official::make_namespace("State",{'+','.join(pairs)+'});return value;}\n')
    (DEST/'ModuleEnums.inc').write_text(''.join(enums),encoding='utf-8')
    metadata=[]
    factory=ast.parse((SOURCE/'CharFactory.py.txt').read_text(encoding='utf-8-sig'))
    registry=next(x.value for x in factory.body if isinstance(x,ast.Assign) and any(isinstance(t,ast.Name) and t.id=='_char_dict_raw' for t in x.targets))
    elements=dict(SPECTRO=0,ELECTRIC=1,FIRE=2,ICE=3,WIND=4,HAVOC=5)
    roles=dict(MAIN_DPS='MainDps',SUB_DPS='SubDps',HEALER='Healer')
    for node in registry.values:
        values={ast.literal_eval(k):v for k,v in zip(node.keys,node.values)}
        name=values['cls'].id;role=roles[values['char_type'].attr];ring=elements[values['ring_index'].attr] if 'ring_index' in values else -1
        buff='V('+str(ast.literal_eval(values['buff_time']))+'LL)' if 'buff_time' in values else 'V{}'
        short=ast.literal_eval(values['target_box_short_combat_check']) if 'target_box_short_combat_check' in values else False
        metadata.append(f'if(class_name_=={quote(name)})'+'{'+f'role={quote(role)};ring={ring};buff={buff};short_target={"true" if short else "false"};'+'}\n')
    (DEST/'InitialMetadata.inc').write_text(''.join(metadata),encoding='utf-8')
    task_text=(SOURCE.parent/'task/BaseCombatTask.py.txt').read_text(encoding='utf-8-sig')
    task_tree=ast.parse(task_text)
    task_cls=next(n for n in task_tree.body if isinstance(n,ast.ClassDef) and n.name=='BaseCombatTask')
    task_names={'_oldest_switch_target','_unbuffed_support_target','_switch_rule_3_target',
        '_target_has_switch_cd','_log_switch_candidate','_log_switch_choice','_buff_remaining',
        '_lowest_buff_remaining_target','_unbuffed_non_main_target','_choose_intro_switch_target',
        '_choose_switch_target_by_buff_time','_choose_switch_target','_apply_intro_flags',
        'switch_next_char','update_lib_portrait_icon'}
    te=Emitter('BaseCombatTask',task_text)
    task_lines=['// Official '+COMMIT+'/src/task/BaseCombatTask.py',
        'void TaskObject::install_combat_methods(){auto scope=std::make_shared<Scope>();']
    for node in task_tree.body:
        if isinstance(node,ast.Assign) and any(isinstance(t,ast.Name) and t.id=='lib_ready_templates' for t in node.targets):
            task_lines.append('set_global("lib_ready_templates",'+te.expr(node.value)+');')
    task_report=[]
    for node in task_cls.body:
        if isinstance(node,ast.FunctionDef) and node.name in task_names:
            before=len(te.covered)
            task_lines.append('register_method('+quote(node.name)+','+te.function_value(node.args,node.body)+',false);')
            task_report.append(dict(name=node.name,official_line=node.lineno,official_end=node.end_lineno,statements=len(te.covered)-before))
    assert len(task_report)==len(task_names)
    task_lines.append('}')
    (DEST/'BaseCombatTask.cpp').write_text('#include "../OfficialTask.h"\nnamespace official {\n'+'\n'.join(task_lines)+'\n}\n',encoding='utf-8')
    (ROOT/'.cache/official-task-translation-coverage.json').write_text(json.dumps(dict(commit=COMMIT,source_sha256=hashlib.sha256(task_text.encode()).hexdigest(),methods=task_report,errors=[]),indent=2),encoding='utf-8')
    for error in errors:print(error[:1200])
    print('generated',len(reports),'of',len(names),'methods',sum(len(r['methods']) for r in reports),'errors',len(errors))
    if errors:sys.exit(1)

if __name__=='__main__':main()
