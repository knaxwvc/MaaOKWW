#pragma once
#include <algorithm>
#include <cmath>
#include <charconv>
#include <cstdint>
#include <functional>
#include <iomanip>
#include <map>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

// Native value operations preserve source-language truth/tuple/callback rules.
// Character conditions and loops are compiled C++; no source interpreter is used.
namespace official {
struct Value;struct Object;struct Args;
using V=Value;using ObjectPtr=std::shared_ptr<Object>;
using Function=std::function<V(const Args&)>;
struct AttributeError:std::runtime_error{using std::runtime_error::runtime_error;};
struct TypeError:std::runtime_error{using std::runtime_error::runtime_error;};
struct ValueError:std::runtime_error{using std::runtime_error::runtime_error;};
struct Iterator {std::function<bool(V&)> next_function;bool next(V& value){return next_function(value);}};
struct Value {
    enum class Kind {none,missing,boolean,integer,real,real32,string,list,tuple,set,dictionary,object,function,slice};
    Kind kind=Kind::none;
    double number=0;std::int64_t integer=0;
    std::shared_ptr<std::string> string;
    std::shared_ptr<std::vector<V>> sequence;
    std::shared_ptr<std::vector<std::pair<V,V>>> mapping;
    ObjectPtr object;
    std::shared_ptr<Function> function_value;
    V()=default;
    V(bool x):kind(Kind::boolean),number(x?1:0),integer(x?1:0){}
    V(int x):V(static_cast<long long>(x)){}
    V(long long x):kind(Kind::integer),number(static_cast<double>(x)),integer(x){}
    V(double x):kind(Kind::real),number(x){}
    static V float32(double x){V value(static_cast<double>(static_cast<float>(x)));value.kind=Kind::real32;return value;}
    V(const char* x):V(std::string(x)){}
    V(std::string x):kind(Kind::string),string(std::make_shared<std::string>(std::move(x))){}
    explicit V(ObjectPtr x):kind(Kind::object),object(std::move(x)){}
    static V missing(){V v;v.kind=Kind::missing;return v;}
    static V list(std::initializer_list<V> x={}){V v;v.kind=Kind::list;v.sequence=std::make_shared<std::vector<V>>(x);return v;}
    static V tuple(std::initializer_list<V> x={}){V v=list(x);v.kind=Kind::tuple;return v;}
    static V set(std::initializer_list<V> x={});
    static V dict(){V v;v.kind=Kind::dictionary;v.mapping=std::make_shared<std::vector<std::pair<V,V>>>();return v;}
    static V function(Function x){V v;v.kind=Kind::function;v.function_value=std::make_shared<Function>(std::move(x));return v;}
    static V slice(V start,V stop,V step){V v=tuple({start,stop,step});v.kind=Kind::slice;return v;}
    bool is_none()const{return kind==Kind::none;}
    bool is_number()const{return kind==Kind::boolean||kind==Kind::integer||kind==Kind::real||kind==Kind::real32;}
    bool truth()const;
    double numeric()const;
    long long integral()const{return static_cast<long long>(numeric());}
    std::string text()const;
    std::string repr()const;
};
struct Args {
    std::vector<V> positional;std::vector<std::pair<std::string,V>> keywords;
    void pos(V value){positional.push_back(std::move(value));}
    void kw(std::string name,V value){for(const auto& item:keywords)if(item.first==name)throw TypeError("duplicate keyword: "+name);keywords.emplace_back(std::move(name),std::move(value));}
    void spread(const V& value);
    void spread_keywords(const V& value);
    V get(size_t position,const std::string& name,V default_value=V::missing())const{
        const bool present=position<positional.size();
        for(const auto& item:keywords)if(item.first==name){if(present)throw TypeError("multiple values for "+name);return item.second;}
        if(present)return positional[position];
        if(default_value.kind==V::Kind::missing)throw TypeError("missing argument: "+name);
        return default_value;
    }
};
struct Object {
    virtual ~Object()=default;
    virtual V get(const std::string& name){throw AttributeError("native object has no attribute: "+name);}
    virtual void set(const std::string& name,V){throw AttributeError("native object cannot set attribute: "+name);}
    virtual V at(const V&){throw TypeError("object is not subscriptable");}
    virtual void put(const V&,V){throw TypeError("object does not support indexed assignment");}
    virtual V call(const Args&){throw TypeError("object is not callable");}
    virtual bool truth()const{return true;}
    virtual double numeric()const{throw TypeError("native object is not numeric");}
    virtual Iterator iterate(){throw TypeError("object is not iterable");}
    virtual std::string text()const{return "<native object>";}
    virtual V binary(const std::string&,const V&,bool){throw TypeError("unsupported native object operation");}
    virtual V comparison(const std::string&,const V&){throw TypeError("unsupported native object comparison");}
};
inline bool Value::truth()const{
    switch(kind){
    case Kind::none:return false;
    case Kind::missing:throw TypeError("use of unbound value");
    case Kind::boolean:case Kind::integer:case Kind::real:case Kind::real32:return number!=0;
    case Kind::string:return !string->empty();
    case Kind::list:case Kind::tuple:case Kind::set:return !sequence->empty();
    case Kind::dictionary:return !mapping->empty();
    case Kind::object:return object->truth();
    default:return true;
    }
}
inline double Value::numeric()const{
    if(is_number())return number;
    if(kind==Kind::object)return object->numeric();
    if(kind==Kind::string){size_t consumed=0;const double n=std::stod(*string,&consumed);if(consumed==string->size())return n;}
    throw TypeError("expected numeric value: "+text());
}
inline std::string Value::text()const{
    switch(kind){
    case Kind::none:return "None";
    case Kind::missing:return "<unbound>";
    case Kind::boolean:return number!=0?"True":"False";
    case Kind::integer:return std::to_string(integer);
    case Kind::real32:{char buffer[64];const auto result=std::to_chars(buffer,buffer+64,static_cast<float>(number));std::string s(buffer,result.ptr);if(s.find_first_of(".eE")==std::string::npos)s+=".0";return s;}
    case Kind::real:{char buffer[64];const auto result=std::to_chars(buffer,buffer+64,number);std::string s(buffer,result.ptr);if(s.find_first_of(".eE")==std::string::npos)s+=".0";return s;}
    case Kind::string:return *string;
    case Kind::object:return object->text();
    case Kind::function:return "<native function>";
    case Kind::dictionary:{std::string s="{";for(size_t i=0;i<mapping->size();++i){if(i)s+=", ";s+=(*mapping)[i].first.repr()+": "+(*mapping)[i].second.repr();}return s+"}";}
    default:{std::string s=kind==Kind::list?"[":kind==Kind::set?"{":"(";for(size_t i=0;i<sequence->size();++i){if(i)s+=", ";s+=(*sequence)[i].repr();}if(kind==Kind::tuple&&sequence->size()==1)s+=",";return s+(kind==Kind::list?"]":kind==Kind::set?"}":")");}
    }
}
inline std::string Value::repr()const{return kind==Kind::string?"'"+*string+"'":text();}
inline bool equal(const V& a,const V& b){
    if(a.is_number()&&b.is_number())return a.number==b.number;
    if(a.kind!=b.kind)return false;
    switch(a.kind){
    case V::Kind::none:case V::Kind::missing:return true;
    case V::Kind::string:return *a.string==*b.string;
    case V::Kind::object:return a.object.get()==b.object.get();
    case V::Kind::function:return a.function_value==b.function_value;
    case V::Kind::dictionary:
        if(a.mapping->size()!=b.mapping->size())return false;
        for(const auto& x:*a.mapping){bool found=false;for(const auto& y:*b.mapping)if(equal(x.first,y.first)&&equal(x.second,y.second)){found=true;break;}if(!found)return false;}return true;
    default:
        if(!a.sequence||!b.sequence||a.sequence->size()!=b.sequence->size())return false;
        for(size_t i=0;i<a.sequence->size();++i)if(!equal((*a.sequence)[i],(*b.sequence)[i]))return false;return true;
    }
}
inline Iterator iterate(const V& value){
    if(value.kind==V::Kind::object)return value.object->iterate();
    if(value.sequence){auto data=value.sequence;return {[data,index=size_t(0)](V& out)mutable{if(index>=data->size())return false;out=(*data)[index++];return true;}};}
    if(value.mapping){auto data=value.mapping;return {[data,index=size_t(0)](V& out)mutable{if(index>=data->size())return false;out=(*data)[index++].first;return true;}};}
    if(value.kind==V::Kind::string){auto s=value.string;return {[s,index=size_t(0)](V& out)mutable{if(index>=s->size())return false;out=V(s->substr(index++,1));return true;}};}
    throw TypeError("value is not iterable: "+value.text());
}
inline bool contains(const V& container,const V& needle){
    if(container.kind==V::Kind::string)return container.string->find(needle.text())!=std::string::npos;
    auto it=iterate(container);V x;while(it.next(x))if(equal(x,needle))return true;return false;
}
inline V Value::set(std::initializer_list<V> values){V out=list();out.kind=Kind::set;for(const auto& v:values)if(!contains(out,v))out.sequence->push_back(v);return out;}
inline void append(V& target,V value){if(!target.sequence)throw TypeError("append to non-sequence");if(target.kind!=V::Kind::set||!contains(target,value))target.sequence->push_back(std::move(value));}
inline void extend(V& target,const V& source){auto it=iterate(source);V x;while(it.next(x))append(target,x);}
inline void Args::spread(const V& value){auto it=iterate(value);V x;while(it.next(x))pos(x);}
inline void Args::spread_keywords(const V& value){if(!value.mapping)throw TypeError("expected keyword mapping");for(const auto& x:*value.mapping)kw(x.first.text(),x.second);}
inline long long index_number(const V& index,size_t size){long long n=index.integral();if(n<0)n+=static_cast<long long>(size);if(n<0||n>=static_cast<long long>(size))throw ValueError("sequence index out of range");return n;}
inline std::vector<size_t> slice_indices(const V& slice,size_t size){
    const auto& parts=*slice.sequence;const long long step=parts[2].is_none()?1:parts[2].integral();if(!step)throw ValueError("zero slice step");
    auto bound=[&](const V& value,long long fallback){if(value.is_none())return fallback;long long n=value.integral();if(n<0)n+=static_cast<long long>(size);return std::clamp(n,step>0?0LL:-1LL,step>0?static_cast<long long>(size):static_cast<long long>(size)-1);};
    const long long start=bound(parts[0],step>0?0:static_cast<long long>(size)-1),stop=bound(parts[1],step>0?static_cast<long long>(size):-1);
    std::vector<size_t> out;for(long long i=start;step>0?i<stop:i>stop;i+=step)out.push_back(static_cast<size_t>(i));return out;
}
inline V item(const V& target,const V& index){
    if(target.kind==V::Kind::object)return target.object->at(index);
    if(target.mapping){for(const auto& x:*target.mapping)if(equal(x.first,index))return x.second;throw ValueError("missing dictionary key: "+index.text());}
    if(index.kind==V::Kind::slice){
        V out=target.kind==V::Kind::string?V(""):target.kind==V::Kind::tuple?V::tuple():V::list();
        const auto indices=slice_indices(index,target.kind==V::Kind::string?target.string->size():target.sequence->size());
        for(const size_t n:indices){if(target.kind==V::Kind::string)*out.string+=(*target.string)[n];else out.sequence->push_back((*target.sequence)[n]);}return out;
    }
    if(target.sequence)return (*target.sequence)[static_cast<size_t>(index_number(index,target.sequence->size()))];
    if(target.kind==V::Kind::string)return V(target.string->substr(static_cast<size_t>(index_number(index,target.string->size())),1));
    throw TypeError("value is not subscriptable");
}
inline void set_item(V target,const V& index,V value){
    if(target.kind==V::Kind::object){target.object->put(index,std::move(value));return;}
    if(target.mapping){for(auto& x:*target.mapping)if(equal(x.first,index)){x.second=std::move(value);return;}target.mapping->emplace_back(index,std::move(value));return;}
    if(target.kind==V::Kind::list){
        if(index.kind==V::Kind::slice){const auto indices=slice_indices(index,target.sequence->size());auto it=iterate(value);V x;size_t count=0;while(it.next(x)){if(count>=indices.size())throw ValueError("slice assignment size mismatch");(*target.sequence)[indices[count++]]=x;}if(count!=indices.size())throw ValueError("slice assignment size mismatch");return;}
        (*target.sequence)[static_cast<size_t>(index_number(index,target.sequence->size()))]=std::move(value);return;
    }
    throw TypeError("indexed assignment is not supported");
}
inline void dict_update(V target,const V& source){if(!target.mapping||!source.mapping)throw TypeError("dictionary update requires mappings");for(const auto& x:*source.mapping)set_item(target,x.first,x.second);}
inline V invoke(const V& callable,const Args& args){if(callable.kind==V::Kind::function)return (*callable.function_value)(args);if(callable.kind==V::Kind::object)return callable.object->call(args);throw TypeError("value is not callable: "+callable.text());}
inline V invoke(const V& callable,std::initializer_list<V> args={}){Args packed;packed.positional=args;return invoke(callable,packed);}
inline V attr(const V& target,const std::string& name){
    if(target.kind==V::Kind::object)return target.object->get(name);
    if(target.sequence){
        if(name=="append")return V::function([target](const Args& a)mutable{V copy=target;append(copy,a.get(0,"value"));return V{};});
        if(name=="clear")return V::function([target](const Args&){target.sequence->clear();return V{};});
        if(name=="pop")return V::function([target](const Args& a){const auto i=index_number(a.get(0,"index",V(-1)),target.sequence->size());V out=(*target.sequence)[static_cast<size_t>(i)];target.sequence->erase(target.sequence->begin()+i);return out;});
        if(name=="copy")return V::function([target](const Args&){V out=V::list();*out.sequence=*target.sequence;out.kind=target.kind;return out;});
    }
    if(target.mapping){
        if(name=="get")return V::function([target](const Args& a){const V key=a.get(0,"key");for(const auto& x:*target.mapping)if(equal(x.first,key))return x.second;return a.get(1,"default",V{});});
        if(name=="values"||name=="keys"||name=="items")return V::function([target,name](const Args&){V out=V::list();for(const auto& x:*target.mapping)out.sequence->push_back(name=="items"?V::tuple({x.first,x.second}):name=="keys"?x.first:x.second);return out;});
        if(name=="copy")return V::function([target](const Args&){V out=V::dict();*out.mapping=*target.mapping;return out;});
        if(name=="clear")return V::function([target](const Args&){target.mapping->clear();return V{};});
    }
    if(target.kind==V::Kind::string){
        if(name=="value"&&(target.text()=="MainDps"||target.text()=="SubDps"||target.text()=="Healer"))return target;
        if(name=="lower")return V::function([target](const Args&){std::string out=target.text();std::transform(out.begin(),out.end(),out.begin(),[](unsigned char c){return static_cast<char>(std::tolower(c));});return V(out);});
        if(name=="join")return V::function([target](const Args& a){auto it=iterate(a.get(0,"iterable"));V x;std::string out;bool first=true;while(it.next(x)){if(!first)out+=*target.string;first=false;out+=x.text();}return V(out);});
        if(name=="format")return V::function([target](const Args& a){std::string out=*target.string;size_t p=0,index=0;while((p=out.find("{}",p))!=std::string::npos){const auto s=a.get(index++,"").text();out.replace(p,2,s);p+=s.size();}return V(out);});
    }
    throw AttributeError("missing attribute "+name+" on "+target.text());
}
inline void set_attr(const V& target,const std::string& name,V value){if(target.kind!=V::Kind::object)throw AttributeError("attribute assignment requires an object");target.object->set(name,std::move(value));}
inline V unary(const std::string& op,const V& value){if(op=="not")return V(!value.truth());if(value.kind==V::Kind::object)return value.object->binary("unary"+op,V{},false);if(op=="-")return value.kind==V::Kind::integer?V(-value.integer):V(-value.numeric());if(op=="+")return value;if(op=="~")return V(~value.integral());throw TypeError("unknown unary operation "+op);}
inline V binary(const std::string& op,const V& a,const V& b){
    if(a.kind==V::Kind::object)return a.object->binary(op,b,false);
    if(b.kind==V::Kind::object)return b.object->binary(op,a,true);
    if(op=="+"&&a.kind==V::Kind::string&&b.kind==V::Kind::string)return V(a.text()+b.text());
    if(op=="+"&&a.sequence&&b.sequence){V out=V::list();out.kind=a.kind;*out.sequence=*a.sequence;out.sequence->insert(out.sequence->end(),b.sequence->begin(),b.sequence->end());return out;}
    if(op=="*"&&(a.sequence||b.sequence)){const auto& seq=a.sequence?a:b;const auto& count=a.sequence?b:a;V out=V::list();out.kind=seq.kind;for(long long n=0;n<count.integral();++n)out.sequence->insert(out.sequence->end(),seq.sequence->begin(),seq.sequence->end());return out;}
    const double x=a.numeric(),y=b.numeric();const bool single=a.kind==V::Kind::real32||b.kind==V::Kind::real32;
    const bool integer=!single&&a.kind!=V::Kind::real&&b.kind!=V::Kind::real;
    if(single){if(op=="+")return V::float32(x+y);if(op=="-")return V::float32(x-y);if(op=="*")return V::float32(x*y);if(op=="/"){if(y==0)throw ValueError("division by zero");return V::float32(x/y);}}
    if(op=="+")return integer?V(a.integral()+b.integral()):V(x+y);
    if(op=="-")return integer?V(a.integral()-b.integral()):V(x-y);
    if(op=="*")return integer?V(a.integral()*b.integral()):V(x*y);
    if(op=="/"){if(y==0)throw ValueError("division by zero");return V(x/y);}
    if(op=="//"){if(y==0)throw ValueError("division by zero");return integer?V(static_cast<long long>(std::floor(x/y))):V(std::floor(x/y));}
    if(op=="%"){if(y==0)throw ValueError("modulo by zero");const double r=x-std::floor(x/y)*y;return integer?V(static_cast<long long>(r)):V(r);}
    if(op=="**")return V(std::pow(x,y));
    if(op=="|")return V(a.integral()|b.integral());
    if(op=="&")return V(a.integral()&b.integral());
    if(op=="^")return V(a.integral()^b.integral());
    throw TypeError("unknown binary operation "+op);
}
inline V compare_value(const std::string& op,const V& a,const V& b){
    if(op=="is"||op=="is not"){const bool same=a.is_none()?b.is_none():a.kind==V::Kind::boolean&&b.kind==V::Kind::boolean?a.integer==b.integer:a.kind==V::Kind::object&&b.kind==V::Kind::object?a.object.get()==b.object.get():a.sequence&&b.sequence?a.sequence==b.sequence:a.mapping&&b.mapping?a.mapping==b.mapping:a.function_value&&b.function_value?a.function_value==b.function_value:false;return V(op=="is"?same:!same);}
    if(op=="in"||op=="not in"){const bool found=contains(b,a);return V(op=="in"?found:!found);}
    if(a.kind==V::Kind::object)return a.object->comparison(op,b);
    if(b.kind==V::Kind::object)return b.object->comparison(op=="<"?">":op==">"?"<":op=="<="?">=":op==">="?"<=":op,a);
    if(op=="==")return V(equal(a,b));if(op=="!=")return V(!equal(a,b));
    if(a.sequence&&b.sequence){const size_t common=std::min(a.sequence->size(),b.sequence->size());for(size_t i=0;i<common;++i)if(!equal((*a.sequence)[i],(*b.sequence)[i]))return compare_value(op,(*a.sequence)[i],(*b.sequence)[i]);return compare_value(op,V(static_cast<long long>(a.sequence->size())),V(static_cast<long long>(b.sequence->size())));}
    const bool strings=a.kind==V::Kind::string&&b.kind==V::Kind::string;
    if(op=="<")return V(strings?a.text()<b.text():a.numeric()<b.numeric());
    if(op=="<=")return V(strings?a.text()<=b.text():a.numeric()<=b.numeric());
    if(op==">")return V(strings?a.text()>b.text():a.numeric()>b.numeric());
    if(op==">=")return V(strings?a.text()>=b.text():a.numeric()>=b.numeric());
    throw TypeError("unknown comparison "+op);
}
inline bool compare(const std::string& op,const V& a,const V& b){return compare_value(op,a,b).truth();}
inline std::vector<V> unpack(const V& value,size_t size){std::vector<V> out;auto it=iterate(value);V x;while(it.next(x))out.push_back(x);if(out.size()!=size)throw ValueError("unpack size mismatch");return out;}
struct Scope:std::enable_shared_from_this<Scope>{
    std::map<std::string,std::shared_ptr<V>> values;std::shared_ptr<Scope> parent;
    explicit Scope(std::shared_ptr<Scope> p={}):parent(std::move(p)){}
    std::shared_ptr<V> cell(const std::string& name)const{auto found=values.find(name);if(found!=values.end())return found->second;if(parent)return parent->cell(name);throw ValueError("unbound local: "+name);}
    V get(const std::string& name)const{return *cell(name);}
    void set(std::string name,V value){const auto found=values.find(name);if(found!=values.end())*found->second=std::move(value);else values[std::move(name)]=std::make_shared<V>(std::move(value));}
    void set_nonlocal(const std::string& name,V value){if(!parent)throw ValueError("missing nonlocal "+name);*parent->cell(name)=std::move(value);}
};
inline std::shared_ptr<Scope> capture_scope(const std::shared_ptr<Scope>& source,std::initializer_list<std::string> names){auto result=std::make_shared<Scope>();for(const auto& name:names)result->values[name]=source->cell(name);return result;}
struct Parameter {std::string name;V default_value;};
struct Signature {
    std::vector<Parameter> positional;std::string varargs,kwargs;std::vector<Parameter> keyword_only;
    Signature(std::initializer_list<Parameter> p,std::string va,std::string kw,std::initializer_list<Parameter> ko):positional(p),varargs(std::move(va)),kwargs(std::move(kw)),keyword_only(ko){}
};
inline std::shared_ptr<Scope> bind_arguments(const Args& input,const Signature& signature,std::shared_ptr<Scope> parent){
    auto scope=std::make_shared<Scope>(std::move(parent));std::map<std::string,V> keys;
    for(const auto& key:input.keywords)keys.emplace(key.first,key.second);
    for(size_t i=0;i<signature.positional.size();++i){
        const auto& p=signature.positional[i];const auto key=keys.find(p.name);V value;
        if(i<input.positional.size()){if(key!=keys.end())throw TypeError("multiple values: "+p.name);value=input.positional[i];}
        else if(key!=keys.end()){value=key->second;keys.erase(key);}else if(p.default_value.kind!=V::Kind::missing)value=p.default_value;else throw TypeError("missing argument: "+p.name);
        scope->set(p.name,value);
    }
    if(signature.varargs.empty()&&input.positional.size()>signature.positional.size())throw TypeError("too many positional arguments");
    if(!signature.varargs.empty()){V extra=V::tuple();for(size_t i=signature.positional.size();i<input.positional.size();++i)extra.sequence->push_back(input.positional[i]);scope->set(signature.varargs,extra);}
    for(const auto& p:signature.keyword_only){const auto key=keys.find(p.name);if(key!=keys.end()){scope->set(p.name,key->second);keys.erase(key);}else if(p.default_value.kind!=V::Kind::missing)scope->set(p.name,p.default_value);else throw TypeError("missing keyword-only argument: "+p.name);}
    if(signature.kwargs.empty()&&!keys.empty())throw TypeError("unexpected keyword: "+keys.begin()->first);
    if(!signature.kwargs.empty()){V extra=V::dict();for(const auto& key:input.keywords)if(keys.count(key.first))set_item(extra,V(key.first),key.second);scope->set(signature.kwargs,extra);}
    return scope;
}
struct RaisedValue:std::runtime_error{explicit RaisedValue(const V& value):std::runtime_error(value.text()){}};
template<class F>struct ScopeExit{F action;~ScopeExit()noexcept(false){action();}};
template<class F>ScopeExit<F> on_scope_exit(F action){return {std::move(action)};}
inline std::string format_value(const V& value,const std::string& spec,int conversion=-1){
    if(spec.empty())return conversion==114?value.repr():value.text();
    std::ostringstream out;const auto dot=spec.find('.');if(dot!=std::string::npos&&spec.back()=='f')out<<std::fixed<<std::setprecision(std::stoi(spec.substr(dot+1)))<<value.numeric();else out<<value.text();return out.str();
}
} // namespace official
