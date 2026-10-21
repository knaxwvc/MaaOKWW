"""Offline reference execution of unchanged, pinned OKWW role source.

Python is used only by this developer comparison; the shipped BOT is native C++.
No game, window, process memory or real input is accessed by this script.
"""
import ast
import collections
import copy
import importlib
import json
import pathlib
import sys
import types
import numpy as np

ROOT=pathlib.Path(__file__).resolve().parent.parent
SOURCE=ROOT/'.cache/official-0b37b5b'
if not (SOURCE/'src/char/BaseChar.py').exists():
    from prepare_official_reference import prepare
    prepare()
sys.path.insert(0,str(SOURCE))

class Log:
    def __getattr__(self,name):return lambda *a,**k:None
class Logger:
    @staticmethod
    def get_logger(*args):return Log()
class Config(dict):
    def __init__(self,name,values=None,*a,**k):super().__init__(values or {})
ok=types.ModuleType('ok');ok.Config=Config;ok.Logger=Logger
ok.color_range_to_bound=lambda color:tuple(np.array([color[c][i] for c in ('b','g','r')],np.uint8) for i in (0,1))
sys.modules['ok']=ok

manifest=json.loads((ROOT/'SOURCES.json').read_text(encoding='utf-8-sig'))
classes={row['character']:getattr(importlib.import_module('src.char.'+row['character']),row['character']) for row in manifest['characters']}
base=importlib.import_module('src.char.BaseChar')
labels=importlib.import_module('src.Labels').Labels
factory=ast.parse((SOURCE/'src/char/CharFactory.py').read_text(encoding='utf-8-sig'))
registry_node=next(n.value for n in factory.body if isinstance(n,ast.Assign) and any(isinstance(t,ast.Name) and t.id=='_char_dict_raw' for t in n.targets))
registry=eval(compile(ast.Expression(registry_node),'official CharFactory metadata','eval'),dict(classes,Labels=labels,CharType=base.CharType,Elements=base.Elements))
by_class={info['cls'].__name__:(name,info) for name,info in registry.items()}

class Box:
    def __init__(self,x,y,width,height,name='',confidence=0):self.x=x;self.y=y;self.width=width;self.height=height;self.name=name;self.confidence=confidence
    def copy(self):return copy.copy(self)
    def crop_frame(self,frame):return frame[self.y:self.y+self.height,self.x:self.x+self.width]
    def __str__(self):return self.name

coco=json.loads((SOURCE/'assets/coco_annotations.json').read_text(encoding='utf-8'))
category={c['id']:c['name'] for c in coco['categories']};images={i['id']:i for i in coco['images']}
boxes={}
for annotation in coco['annotations']:
    name=category[annotation['category_id']]
    if name in boxes:continue
    image=images[annotation['image_id']];boxes[name]=(image['width'],image['height'],*annotation['bbox'])
config_tree=ast.parse((SOURCE/'config.py').read_text(encoding='utf-8-sig'))
config_node=next(n.value for n in config_tree.body if isinstance(n,ast.Assign) and any(isinstance(t,ast.Name) and t.id=='config' for t in n.targets))
matching=next(v for k,v in zip(config_node.keys,config_node.values) if ast.literal_eval(k)=='template_matching')
centering={ast.literal_eval(k):ast.literal_eval(v) for k,v in zip(matching.keys,matching.values) if isinstance(k,ast.Constant) and k.value in ('hcenter_features','vcenter_features')}
def anchor(value,source,screen,scale,center=False):
    if center:return round(screen*.5+(value-source*.5)*scale)
    return screen-round((source-value)*scale) if value>source/2 else round(value*scale)
def scaled_box(name):
    w,h,x,y,bw,bh=boxes[name];scale=min(1280/w,720/h)
    return Box(anchor(x,w,1280,scale,'hcenter' in name or name in centering['hcenter_features']),anchor(y,h,720,scale,'vcenter' in name or name in centering['vcenter_features']),round(bw*scale),round(bh*scale),name)

class FakeClock:
    value=100
    def time(self):self.value+=.001;return self.value
    def sleep(self,duration):task.event('raw_sleep',duration);self.value+=max(0,duration)
clock=FakeClock()
for name,module in list(sys.modules.items()):
    if name.startswith('src.char.') and hasattr(module,'time'):module.time=clock

class AutoCombatTask:
    debug=False;name='AutoCombatTask';use_liberation=True;has_lavitator=False
    skip_combat_check=False;in_liberation=False;can_break=False;combat_start=100
    switch_char_time_out=5
    char_config={'Chisa DPS':False,'Iuno C6':False}
    key_config={'Tool Key':'T','Resonance Key':'E','Echo Key':'Q','Liberation Key':'R'}
    def __init__(self,name,scenario,count=3):
        self.count=count;self.scenario=scenario;self.active=0;self.hidden=0;self.trace=[];self.cds=[0,0,0];self.freeze=[];self.constructing=True;self.reads=0
        self._frame=np.zeros((720,1280,3),np.uint8)
        if scenario>0:
            for roi in ('box_resonance','box_echo','box_liberation'):
                box=scaled_box(roi);self._frame[box.y:box.y+box.height,box.x:box.x+box.width]=255
        self.chars=[]
        names=[name,'Mortefi' if name=='Sanhua' else 'Sanhua','ShoreKeeper' if name=='Verina' else 'Verina']
        for index,role in enumerate(names[:count]):
            canonical,info=by_class[role]
            self.chars.append(classes[role](self,index,char_name=canonical,confidence=1,ring_index=info.get('ring_index',-1),char_type=info['char_type'],buff_time=info.get('buff_time',base.get_default_buff_time(info['char_type']))))
            self.chars[-1].target_box_short_combat_check=info.get('target_box_short_combat_check',False)
        for index,char in enumerate(self.chars):
            char.reset_state();char.is_current_char=index==0;char.has_intro=index==0 and scenario==2;char.last_buff_time=99 if index>0 and scenario==2 else -1
        clock.value=100;self.constructing=False
    def event(self,*values):
        if not self.constructing:self.trace.append(list(values))
        if len(self.trace)>6000:raise RuntimeError('fixture operation budget')
    @property
    def frame(self):
        self.reads+=1
        if self.reads>50000:raise RuntimeError('fixture observation budget')
        return self._frame
    def next_frame(self):
        self.event('frame');clock.value+=.05;self.hidden=max(0,self.hidden-1);return self.frame
    def sleep(self,duration):self.event('sleep',duration);clock.value+=max(0,duration);return True
    def send_key(self,key,down_time=.02,interval=-1,after_sleep=0):
        key=str(key).upper();self.event('key',key,down_time,interval,after_sleep);clock.value+=down_time
        if key in ('1','2','3'):self.active=int(key)-1
        if key in ('E','Q','R'):
            self.cds['EQR'.index(key)]=clock.value+10
            if key=='R':self.hidden=3
        if after_sleep>0:self.sleep(after_sleep)
        return True
    def send_key_down(self,key,after_sleep=0):
        self.event('key_down',str(key).upper())
        if after_sleep>0:self.sleep(after_sleep)
    def send_key_up(self,key,after_sleep=0):
        self.event('key_up',str(key).upper())
        if after_sleep>0:self.sleep(after_sleep)
    def click(self,x=-1,y=-1,move_back=False,name=None,interval=-1,move=False,down_time=.01,after_sleep=0,key='left'):
        assert x==y==-1
        self.event('click',{'left':0,'right':1,'middle':2}[key],interval,after_sleep);clock.value+=.01
        if after_sleep>0:self.sleep(after_sleep)
        return True
    def middle_click_relative(self,x,y,move_back=False,down_time=.01):return self.click(key='middle')
    def mouse_down(self):self.event('mouse_down')
    def mouse_up(self):self.event('mouse_up')
    def jump(self,after_sleep=.01):self.send_key(' ',after_sleep=after_sleep)
    def get_resonance_key(self):return 'E'
    def get_echo_key(self):return 'Q'
    def get_liberation_key(self):return 'R'
    def in_team(self):return (False,-1,self.count) if self.hidden else (True,self.active,self.count)
    def in_team_and_world(self):return self.in_team()[0]
    def is_open_world_auto_combat(self):return True
    def has_target(self):return True
    def check_combat(self):pass
    def raise_not_in_combat(self,reason):raise RuntimeError(reason)
    def get_current_char(self,raise_exception=False):return next((char for char in self.chars if char.is_current_char),None)
    def has_char(self,cls):return next((char for char in self.chars if isinstance(char,cls)),None)
    def load_chars(self):pass
    def _ensure_ring_index(self):
        char=self.get_current_char()
        if char is None:return -1
        if char.ring_index<0:char.ring_index=0
        return char.ring_index
    def get_current_con(self):return 1 if self.scenario==2 else 0
    def is_con_full(self):return self.scenario==2
    def get_cd(self,box_name,char_index=None):return 10.0 if self.scenario==0 else max(0,self.cds[{'resonance':0,'echo':1,'liberation':2}[box_name]]-clock.value)
    def has_cd(self,box_name,char_index=None):return self.get_cd(box_name,char_index)>.2
    def get_box_by_name(self,name):return name if isinstance(name,Box) else scaled_box(name)
    def box_of_screen_scaled(self,original_width,original_height,x,y,to_x,to_y,name='',hcenter=False,vcenter=False):
        scale=min(1280/original_width,720/original_height)
        return Box(anchor(x,original_width,1280,scale,hcenter),anchor(y,original_height,720,scale,vcenter),round((to_x-x)*scale),round((to_y-y)*scale),name)
    def calculate_color_percentage(self,color,box):
        import cv2
        roi=self.get_box_by_name(box);pixels=roi.crop_frame(self.frame)
        return float(np.count_nonzero(cv2.inRange(pixels,tuple(color[c][0] for c in 'bgr'),tuple(color[c][1] for c in 'bgr')))/(pixels.size/3)) if pixels.size else 0.0
    def box_highlighted(self,name):return 1 if self.calculate_color_percentage({c:(244,255) for c in 'bgr'},'box_'+name)>0 else 0
    def available(self,name,check_color=True,check_cd=True):
        highlighted=self.box_highlighted(name) if check_color else 1
        if highlighted>0 and (not check_cd or not self.has_cd(name)):return True
    def find_one(self,*a,**k):return None
    def find_best_match_in_box(self,*a,**k):return None
    def find_feature(self,*a,**k):return []
    def get_feature_by_name(self,name):return types.SimpleNamespace(mat=np.zeros((48,48,3),np.uint8))
    def get_target_names(self):return 'has_target','no_target'
    def has_short_action(self):return None
    def find_mouse_forte(self):return False
    def find_e_forte(self):return False
    def check_f_break(self):return False
    def f_break(self):return None
    def add_freeze_duration(self,start,duration=-1,freeze_time=.1):
        now=clock.time()
        if duration<0:duration=now-start
        if start>0 and duration>freeze_time:self.freeze.append((start,duration,freeze_time))
        self.freeze=[event for event in self.freeze if now-event[0]<=60]
    def time_elapsed_accounting_for_freeze(self,start,intro_motion_freeze=False):
        now=clock.time()
        if start<0:return 10000
        duration=now-start
        for frozen_start,frozen_duration,minimum in self.freeze:
            if start<frozen_start and (intro_motion_freeze or minimum!=-100):duration-=frozen_duration-(0 if minimum==-100 else minimum)
        return duration
    def wait_until(self,condition,time_out=0,pre_action=None,post_action=None,settle_time=-1,raise_if_not_found=False):
        start=clock.time();time_out=time_out or 10;settled=0
        while True:
            if pre_action is not None:pre_action()
            self.next_frame();result=condition()
            if result:
                if settle_time==-1:settle_time=0
                if settle_time>0:
                    now=clock.time()
                    if settled>0 and now-settled>settle_time:return result
                    if settled==0:settled=now
                    continue
                return result
            settled=0
            if post_action is not None:post_action()
            if clock.time()-start>time_out:break
        if raise_if_not_found:raise RuntimeError('official WaitFailedException')
    def wait_in_team_and_world(self,time_out=10,raise_if_not_found=True,esc=False):
        success=self.wait_until(self.in_team_and_world,time_out=time_out,raise_if_not_found=raise_if_not_found)
        if success:self.sleep(.5)
        return success
    def screenshot(self,*a,**k):pass
    def draw_boxes(self,*a,**k):pass
    def info_set(self,*a,**k):pass
    def log_debug(self,*a,**k):pass
    def log_error(self,*a,**k):pass
    def tr(self,text):return text

auto_module=types.ModuleType('src.task.AutoCombatTask');auto_module.AutoCombatTask=AutoCombatTask;sys.modules[auto_module.__name__]=auto_module
task_tree=ast.parse((SOURCE/'src/task/BaseCombatTask.py').read_text(encoding='utf-8-sig'))
coverage=json.loads((ROOT/'.cache/official-task-translation-coverage.json').read_text(encoding='utf-8'))
names={entry['name'] for entry in coverage['methods']}
task_cls=next(node for node in task_tree.body if isinstance(node,ast.ClassDef) and node.name=='BaseCombatTask')
scope={'time':clock,'logger':Log(),'SwitchPriority':base.SwitchPriority}
for node in task_tree.body:
    if isinstance(node,ast.Assign) and any(isinstance(t,ast.Name) and t.id=='lib_ready_templates' for t in node.targets):exec(compile(ast.Module([node],type_ignores=[]),'official task globals','exec'),scope)
for node in task_cls.body:
    if isinstance(node,ast.FunctionDef) and node.name in names:
        exec(compile(ast.Module([node],type_ignores=[]),'official BaseCombatTask.py','exec'),scope)
        setattr(AutoCombatTask,node.name,scope[node.name])

def main():
    global task
    if '--sleep-contract' in sys.argv:
        cases=[]
        for previous in (False,True):
            for check in (False,True):
                observed=[]
                task=types.SimpleNamespace(skip_combat_check=previous)
                def interrupt(seconds):
                    observed.append(task.skip_combat_check)
                    raise RuntimeError('fixture disabled')
                task.sleep=interrupt;actor=base.BaseChar(task,0);raised=False
                try:actor.sleep(.1,check_combat=check)
                except RuntimeError:raised=True
                assert observed==[previous or not check] and task.skip_combat_check==previous and raised
                cases.append(dict(previous=previous,check_combat=check,during=observed[0],after=task.skip_combat_check,interruption_propagated=raised))
        task=types.SimpleNamespace(skip_combat_check=False);actor=base.BaseChar(task,0);depth=0;observed=[]
        def nested(seconds):
            nonlocal depth
            observed.append(task.skip_combat_check)
            if depth==0:
                depth+=1;actor.sleep(.05);observed.append(task.skip_combat_check)
        task.sleep=nested;actor.sleep(.1,check_combat=False)
        assert observed==[True,True,True] and task.skip_combat_check is False
        (ROOT/'.cache/python-sleep-contract.json').write_text(json.dumps(dict(cases=cases,nested_observed=observed,nested_restored=not task.skip_combat_check)),encoding='utf-8')
        print('official sleep restoration cases 5');return
    if '--team-size' in sys.argv:
        with (ROOT/'.cache/python-teams.jsonl').open('w',encoding='utf-8') as stream:
            for name in ('Aemeath','Qingxiao','Camellya','Hsin','Rover'):
                for count in (1,2):
                    task=AutoCombatTask(name,1,count);error=None
                    try:task.chars[0].perform()
                    except Exception as exception:error=str(exception)
                    row=dict(role=name,scenario=1,team_size=count,error=error,trace=task.trace,state={key:getattr(task.chars[0],key) for key in ('last_res','last_echo','last_liberation','current_con','has_intro','is_current_char')})
                    stream.write(json.dumps(row,ensure_ascii=False)+'\n')
        print('official team size reference cases 10');return
    if '--vision' in sys.argv:
        with (ROOT/'.cache/python-vision.jsonl').open('w',encoding='utf-8') as stream:
            for width in (64,128,512):
                for pattern in range(5):
                    task=AutoCombatTask('Camellya',0);gray=np.zeros((12,width),np.uint8)
                    for y in range(12):
                        for x in range(width):
                            white=pattern==1 or pattern==2 and x%8<4 or pattern==3 and x<width/2 and x%12<6 or pattern==4 and (x*17+y*31)%11<3
                            gray[y,x]=255 if white else 0
                    stream.write(json.dumps(dict(width=width,pattern=pattern,result=task.chars[0].detect_stripe_region(gray)))+'\n')
            for pattern in range(3):
                task=AutoCombatTask('Camellya',0)
                for y in range(64):
                    for x in range(64):task._frame[y,x]=(0,0,0) if pattern==0 else (60 if x%3==0 else 10,70,80)
                color={'b':(50,65),'g':(60,80),'r':(70,90)}
                result=task.chars[0].calculate_color_percentage_in_masked(color,Box(0,0,64,64),.395 if pattern==2 else .1,.496)
                stream.write(json.dumps(dict(mask_pattern=pattern,result=result))+'\n')
        print('official vision reference cases 18');return
    output=ROOT/'.cache/python-traces.jsonl'
    with output.open('w',encoding='utf-8') as stream:
        for name in classes:
            for scenario in range(3):
                task=AutoCombatTask(name,scenario);error=None
                try:task.chars[0].perform()
                except Exception as exception:error=str(exception)
                row=dict(role=name,scenario=scenario,error=error,trace=task.trace,state={key:getattr(task.chars[0],key) for key in ('last_res','last_echo','last_liberation','current_con','has_intro','is_current_char')})
                stream.write(json.dumps(row,ensure_ascii=False)+'\n');stream.flush()
    rows=[json.loads(line) for line in output.read_text(encoding='utf-8').splitlines()]
    print('official reference cases',len(rows),'errors',dict(collections.Counter(row['error'] for row in rows if row['error'])))

if __name__=='__main__':main()
