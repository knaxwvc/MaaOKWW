#pragma once
#include "OfficialArray.h"
#include <iostream>

namespace official {
struct Namespace:Object {
    std::string name;std::map<std::string,V> members;std::vector<std::string> order;
    std::function<V(const std::string&)> dynamic_get;
    std::function<V(const Args&)> callable;
    explicit Namespace(std::string n):name(std::move(n)){}
    V get(const std::string& key)override{if(key=="__name__")return V(name);const auto found=members.find(key);if(found!=members.end())return found->second;if(dynamic_get)return dynamic_get(key);return Object::get(key);}
    void set(const std::string& key,V value)override{if(!members.count(key))order.push_back(key);members[key]=std::move(value);}
    V call(const Args& args)override{if(callable)return callable(args);return Object::call(args);}
    std::string text()const override{return name;}
    Iterator iterate()override{if(name!="CharType"&&name!="SwitchPriority"&&name!="Elements"&&name!="State")return Object::iterate();V values=V::list();for(const auto& key:order)values.sequence->push_back(members.at(key));return official::iterate(values);}
    V comparison(const std::string& op,const V& other)override{const bool same=other.kind==V::Kind::object&&other.object.get()==this;if(op=="==")return V(same);if(op=="!=")return V(!same);return Object::comparison(op,other);}
    V value(){return V(std::static_pointer_cast<Object>(std::shared_ptr<Namespace>(this,[](Namespace*){})));}
};
struct EnumValue final:Object {
    std::string enum_name,name;V underlying;
    EnumValue(std::string e,std::string n,V v):enum_name(std::move(e)),name(std::move(n)),underlying(std::move(v)){}
    V get(const std::string& key)override{if(key=="name")return V(name);if(key=="value")return underlying;return Object::get(key);}
    std::string text()const override{return enum_name+"."+name;}
    V comparison(const std::string& op,const V& other)override{const bool same=other.kind==V::Kind::object&&other.object.get()==this;if(op=="==")return V(same);if(op=="!=")return V(!same);return Object::comparison(op,other);}
};
inline V make_namespace(const std::string& name,std::initializer_list<std::pair<std::string,V>> members={}){
    auto object=std::make_shared<Namespace>(name);
    for(const auto& field:members)object->set(field.first,name=="State"?V(std::make_shared<EnumValue>(name,field.first,field.second)):field.second);
    if(name=="CharType")object->callable=[weak=std::weak_ptr<Namespace>(object)](const Args& args){const auto current=weak.lock();const V value=args.get(0,"value");for(const auto& x:current->members)if(equal(value,x.second))return x.second;throw ValueError("invalid CharType: "+value.text());};
    return V(object);
}
struct ClassToken final:Namespace {
    explicit ClassToken(std::string n):Namespace(std::move(n)){}
};
struct DecimalValue final:Object {
    std::string representation;
    explicit DecimalValue(std::string value):representation(std::move(value)){}
    double numeric()const override{return std::stod(representation);}
    std::string text()const override{return representation;}
    static std::string quantized(std::string number,int decimals,const std::string& rounding){
        bool negative=!number.empty()&&number[0]=='-';if(negative)number.erase(number.begin());
        const auto exponent_at=number.find_first_of("eE");int exponent=0;if(exponent_at!=std::string::npos){exponent=std::stoi(number.substr(exponent_at+1));number.resize(exponent_at);}
        const auto dot=number.find('.');int point=static_cast<int>(dot==std::string::npos?number.size():dot)+exponent;if(dot!=std::string::npos)number.erase(dot,1);
        if(point<=0){number=std::string(static_cast<size_t>(1-point),'0')+number;point=1;}
        const size_t cut=static_cast<size_t>(point+decimals);if(number.size()<=cut)number.append(cut+1-number.size(),'0');
        bool round_up=false;
        if(rounding=="ROUND_HALF_UP")round_up=number[cut]>='5';
        else if(rounding=="ROUND_UP")round_up=std::any_of(number.begin()+static_cast<ptrdiff_t>(cut),number.end(),[](char c){return c!='0';});
        else if(rounding!="ROUND_DOWN")throw ValueError("unsupported Decimal rounding "+rounding);
        number.resize(cut);
        if(round_up){size_t i=number.size();while(i>0&&number[i-1]=='9'){number[--i]='0';}if(i>0)++number[i-1];else{number.insert(number.begin(),'1');++point;}}
        if(decimals>0)number.insert(static_cast<size_t>(point),1,'.');if(negative)number.insert(number.begin(),'-');return number;
    }
    V get(const std::string& name)override{
        if(name=="quantize")return V::function([number=representation](const Args& args){const std::string quantum=args.get(0,"exp").text();const auto dot=quantum.find('.');const int digits=dot==std::string::npos?0:static_cast<int>(quantum.size()-dot-1);const auto rounded=quantized(number,digits,args.get(1,"rounding",V("ROUND_HALF_UP")).text());return V(std::make_shared<DecimalValue>(rounded));});
        return Object::get(name);
    }
    V comparison(const std::string& op,const V& other)override{return compare_value(op,V(numeric()),V(other.numeric()));}
    V binary(const std::string& op,const V& other,bool reverse)override{return official::binary(op,reverse?V(other.numeric()):V(numeric()),reverse?V(numeric()):V(other.numeric()));}
};
inline long long length(const V& value){if(value.sequence)return static_cast<long long>(value.sequence->size());if(value.mapping)return static_cast<long long>(value.mapping->size());if(value.kind==V::Kind::string)return static_cast<long long>(value.string->size());if(value.kind==V::Kind::object)if(auto a=std::dynamic_pointer_cast<Array>(value.object)){if(a->shape.empty())throw TypeError("len of scalar array");return a->shape[0];}throw TypeError("value has no length");}
inline std::map<std::string,V> standard_globals(){
    std::map<std::string,V> globals;
    globals["bool"]=V::function([](const Args& a){return V(a.get(0,"x",V(false)).truth());});
    globals["int"]=V::function([](const Args& a){return V(a.get(0,"x",V(0)).integral());});
    globals["float"]=V::function([](const Args& a){return V(a.get(0,"x",V(0)).numeric());});
    globals["str"]=V::function([](const Args& a){return V(a.get(0,"x",V("")).text());});
    globals["len"]=V::function([](const Args& a){return V(length(a.get(0,"obj")));});
    globals["list"]=V::function([](const Args& a){V result=V::list();if(!a.positional.empty())extend(result,a.get(0,"iterable"));return result;});
    globals["tuple"]=V::function([](const Args& a){V result=V::tuple();if(!a.positional.empty())extend(result,a.get(0,"iterable"));return result;});
    globals["range"]=V::function([](const Args& a){const long long start=a.positional.size()>1?a.get(0,"start").integral():0,stop=a.get(a.positional.size()>1?1:0,"stop").integral(),step=a.get(2,"step",V(1)).integral();if(!step)throw ValueError("zero range step");V result=V::list();for(long long i=start;step>0?i<stop:i>stop;i+=step)result.sequence->push_back(V(i));return result;});
    globals["enumerate"]=V::function([](const Args& a){auto it=iterate(a.get(0,"iterable"));long long i=a.get(1,"start",V(0)).integral();V x,result=V::list();while(it.next(x))result.sequence->push_back(V::tuple({V(i++),x}));return result;});
    globals["getattr"]=V::function([](const Args& a){try{return attr(a.get(0,"object"),a.get(1,"name").text());}catch(const AttributeError&){if(a.positional.size()>2)return a.get(2,"default");throw;}});
    globals["hasattr"]=V::function([](const Args& a){try{attr(a.get(0,"object"),a.get(1,"name").text());return V(true);}catch(const AttributeError&){return V(false);}});
    globals["type"]=V::function([](const Args& a){return attr(a.get(0,"object"),"__class__");});
    globals["isinstance"]=V::function([](const Args& a){const V object=a.get(0,"object"),type=a.get(1,"classinfo");if(object.is_none()||object.kind!=V::Kind::object)return V(false);const std::vector<V> types=type.sequence?*type.sequence:std::vector<V>{type};for(const auto& candidate:types){if(candidate.kind!=V::Kind::object)throw TypeError("isinstance requires a class token");const auto cls=std::dynamic_pointer_cast<ClassToken>(candidate.object);if(!cls)throw TypeError("isinstance requires a class token");try{const V identity=attr(object,"__class__");const auto actual=std::dynamic_pointer_cast<ClassToken>(identity.object);if(actual&&(actual->name==cls->name||(cls->name=="BaseChar"&&actual->name!="AutoCombatTask")))return V(true);}catch(const AttributeError&){}}return V(false);});
    for(const std::string name:{"any","all"})globals[name]=V::function([name](const Args& a){auto it=iterate(a.get(0,"iterable"));V x;while(it.next(x)){if(name=="any"&&x.truth())return V(true);if(name=="all"&&!x.truth())return V(false);}return V(name=="all");});
    for(const std::string name:{"min","max"})globals[name]=V::function([name](const Args& a){V values=a.positional.size()==1?a.positional[0]:V::list();if(a.positional.size()!=1)*values.sequence=a.positional;auto it=iterate(values);V x,best;if(!it.next(best))throw ValueError("empty "+name);V key;for(const auto& kw:a.keywords)if(kw.first=="key")key=kw.second;V best_key=key.is_none()?best:invoke(key,{best});while(it.next(x)){V x_key=key.is_none()?x:invoke(key,{x});if(compare(name=="min"?"<":">",x_key,best_key)){best=x;best_key=x_key;}}return best;});
    for(const std::string name:{"RuntimeError","ValueError"})globals[name]=V::function([](const Args& a){return a.get(0,"message",V("official error"));});
    globals["Decimal"]=V::function([](const Args& a){return V(std::make_shared<DecimalValue>(a.get(0,"value").text()));});
    for(const std::string name:{"ROUND_UP","ROUND_HALF_UP","ROUND_DOWN"})globals[name]=V(name);
    auto numpy=std::make_shared<Namespace>("np");numpy->dynamic_get=[](const std::string& name){if(name=="uint8"||name=="float32"||name=="float64")return V(name);if(name=="fft"){auto fft=std::make_shared<Namespace>("np.fft");fft->members["fft"]=V::function([](const Args& a){return numpy_call("fft",a);});return V(fft);}if(name=="ndarray")return V(std::make_shared<ClassToken>("ndarray"));return V::function([name](const Args& a){return numpy_call(name,a);});};globals["np"]=V(numpy);
    auto cv=std::make_shared<Namespace>("cv2");cv->dynamic_get=[](const std::string& name){if(name=="COLOR_BGR2GRAY")return V(6);return V::function([name](const Args& a){return cv_call(name,a);});};globals["cv2"]=V(cv);
    auto math=std::make_shared<Namespace>("math");math->members["floor"]=V::function([](const Args& a){return V(static_cast<long long>(std::floor(a.get(0,"x").numeric())));});math->members["ceil"]=V::function([](const Args& a){return V(static_cast<long long>(std::ceil(a.get(0,"x").numeric())));});globals["math"]=V(math);
    globals["color_range_to_bound"]=V::function([](const Args& a){const V color=a.get(0,"color_range");V low=V::list(),high=V::list();for(const std::string channel:{"b","g","r"}){const V range=item(color,V(channel));low.sequence->push_back(item(range,V(0)));high.sequence->push_back(item(range,V(1)));}return V::tuple({array_from_value(low,"uint8")->value(),array_from_value(high,"uint8")->value()});});
    globals["text_white_color"]=V::dict();for(const std::string channel:{"b","g","r"})set_item(globals["text_white_color"],V(channel),V::tuple({V(244),V(255)}));
    globals["get_default_buff_time"]=V::function([](const Args& a){const V type=a.get(0,"char_type",V("MainDps"));return V(type.text()=="Healer"?28:type.text()=="SubDps"||type.text()=="MainDps"?14:0);});
    return globals;
}
} // namespace official
