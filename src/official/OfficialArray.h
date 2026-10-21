#pragma once
#include "OfficialValue.h"
#include <complex>
#include <numeric>
#include <limits>
#include "../combat/CombatCheck.h"
#define POCKETFFT_NO_MULTITHREADING
#include "vendor/pocketfft_hdronly.h"

namespace official {
struct Array final:Object,std::enable_shared_from_this<Array>{
    std::vector<int> shape;
    std::vector<size_t> strides;
    std::shared_ptr<std::vector<double>> data;
    std::shared_ptr<std::vector<std::complex<double>>> complex_data;
    std::shared_ptr<std::vector<unsigned char>> raw;
    size_t offset=0;
    std::string dtype="float64";
    explicit Array(std::vector<int> dimensions={},std::string type="float64"):shape(std::move(dimensions)),dtype(std::move(type)){
        size_t size=1;strides.resize(shape.size());for(size_t axis=shape.size();axis>0;--axis){strides[axis-1]=size;size*=static_cast<size_t>(shape[axis-1]);}data=std::make_shared<std::vector<double>>(size,0);
    }
    size_t size()const{size_t out=1;for(int dimension:shape)out*=static_cast<size_t>(dimension);return out;}
    size_t address(size_t index)const{size_t address=offset;for(size_t axis=shape.size();axis>0;--axis){const auto length=static_cast<size_t>(shape[axis-1]);if(!length)return offset;address+=(index%length)*strides[axis-1];index/=length;}return address;}
    double number_at(size_t index)const{const auto address_=address(index);return raw?(*raw)[address_]:(*data)[address_];}
    void number_put(size_t index,double value){const auto address_=address(index);if(raw)(*raw)[address_]=static_cast<unsigned char>(value);else (*data)[address_]=dtype=="uint8"?static_cast<unsigned char>(value):dtype=="float32"?static_cast<float>(value):value;}
    V scalar(size_t index)const{return dtype=="float32"?V::float32(number_at(index)):dtype=="uint8"||dtype=="bool"||dtype=="int64"?V(static_cast<long long>(number_at(index))):V(number_at(index));}
    std::complex<double> complex_at(size_t index)const{return complex_data?(*complex_data)[address(index)]:std::complex<double>(number_at(index),0);}
    std::shared_ptr<Array> copy()const{auto out=std::make_shared<Array>(shape,dtype);if(complex_data){out->complex_data=std::make_shared<std::vector<std::complex<double>>>(size());for(size_t i=0;i<size();++i)(*out->complex_data)[i]=complex_at(i);}else for(size_t i=0;i<size();++i)out->number_put(i,number_at(i));return out;}
    V value(){return V(std::static_pointer_cast<Object>(shared_from_this()));}
    bool truth()const override{if(size()!=1)throw ValueError("truth of an array with multiple elements is ambiguous");return complex_data?complex_at(0)!=std::complex<double>{}:number_at(0)!=0;}
    double numeric()const override{if(size()!=1)throw TypeError("array must have one element for numeric conversion");return number_at(0);}
    std::string text()const override{return "<native array>";}
    Iterator iterate()override{auto self=shared_from_this();return {[self,index=0](V& out)mutable{if(self->shape.empty()||index>=self->shape[0])return false;out=self->at(V(index++));return true;}};}
    V get(const std::string& name)override{
        if(name=="ndim")return V(static_cast<int>(shape.size()));
        if(name=="shape"){V out=V::tuple();for(int n:shape)out.sequence->push_back(V(n));return out;}
        if(name=="size")return V(static_cast<long long>(size()));
        if(name=="dtype")return V(dtype);
        if(name=="copy")return V::function([self=shared_from_this()](const Args&){return self->copy()->value();});
        if(name=="astype")return V::function([self=shared_from_this()](const Args& a){auto out=self->copy();out->dtype=a.get(0,"dtype").text();for(size_t i=0;i<out->size();++i)out->number_put(i,out->number_at(i));return out->value();});
        if(name=="sum")return V::function([self=shared_from_this()](const Args& a){return self->reduce("sum",a.get(0,"axis",V{}));});
        if(name=="max")return V::function([self=shared_from_this()](const Args& a){return self->reduce("max",a.get(0,"axis",V{}));});
        return Object::get(name);
    }
    std::shared_ptr<Array> select(const V& index)const{
        std::vector<V> indices=index.kind==V::Kind::tuple?*index.sequence:std::vector<V>{index};
        if(indices.size()>shape.size())throw ValueError("too many array indices");
        auto out=std::make_shared<Array>();out->shape.clear();out->strides.clear();out->offset=offset;out->data=data;out->raw=raw;out->complex_data=complex_data;out->dtype=dtype;
        for(size_t axis=0;axis<shape.size();++axis){
            const V key=axis<indices.size()?indices[axis]:V::slice(V{},V{},V{});
            if(key.kind==V::Kind::slice){const auto positions=slice_indices(key,static_cast<size_t>(shape[axis]));out->shape.push_back(static_cast<int>(positions.size()));const long long step=(*key.sequence)[2].is_none()?1:(*key.sequence)[2].integral();if(step<0)throw ValueError("negative native array stride is not used by pinned source");out->strides.push_back(strides[axis]*static_cast<size_t>(step));if(!positions.empty())out->offset+=positions[0]*strides[axis];}
            else out->offset+=static_cast<size_t>(index_number(key,static_cast<size_t>(shape[axis])))*strides[axis];
        }
        return out;
    }
    V at(const V& index)override{auto selected=select(index);return selected->shape.empty()?selected->scalar(0):selected->value();}
    void put(const V& index,V value_)override{
        auto selected=select(index);auto source=value_.kind==V::Kind::object?std::dynamic_pointer_cast<Array>(value_.object):nullptr;
        if(source&&source->size()!=selected->size())throw ValueError("array assignment shape mismatch");
        for(size_t i=0;i<selected->size();++i)selected->number_put(i,source?source->number_at(i):value_.numeric());
    }
    V binary(const std::string& op,const V& right,bool reverse)override{
        auto other=right.kind==V::Kind::object?std::dynamic_pointer_cast<Array>(right.object):nullptr;
        if(other&&other->shape!=shape&&other->size()!=1&&size()!=1)throw ValueError("unsupported array broadcast");
        const auto dimensions=other&&size()==1?other->shape:shape;auto out=std::make_shared<Array>(dimensions,dtype);
        for(size_t i=0;i<out->size();++i){const double x=number_at(size()==1?0:i),y=other?other->number_at(other->size()==1?0:i):right.is_none()?0:right.numeric();
            if(op=="unary-")out->number_put(i,-x);else{const V a(reverse?y:x),b(reverse?x:y);out->number_put(i,official::binary(op,a,b).numeric());}}
        return out->value();
    }
    V comparison(const std::string& op,const V& right)override{
        auto other=right.kind==V::Kind::object?std::dynamic_pointer_cast<Array>(right.object):nullptr;
        if(other&&other->shape!=shape&&other->size()!=1)throw ValueError("array comparison shape mismatch");
        auto out=std::make_shared<Array>(shape,"bool");for(size_t i=0;i<size();++i)out->number_put(i,compare(op,V(number_at(i)),other?V(other->number_at(other->size()==1?0:i)):right)?1:0);return out->value();
    }
    V reduce(const std::string& operation,const V& axis)const{
        if(axis.is_none()){
            if(operation=="any"||operation=="all"){bool result=operation=="all";for(size_t i=0;i<size();++i){if(operation=="any"&&number_at(i)!=0)return V(true);if(operation=="all"&&number_at(i)==0)return V(false);}return V(result);}
            double result=operation=="max"?-std::numeric_limits<double>::infinity():0;for(size_t i=0;i<size();++i)result=operation=="max"?std::max(result,number_at(i)):result+number_at(i);
            if(dtype=="float32"&&(operation=="sum"||operation=="mean")){
                // NumPy v2.5.2 FLOAT_pairwise_sum ordering (BSD-3-Clause).
                std::function<float(size_t,size_t)> sum=[&](size_t start,size_t n)->float{
                    if(n<8){float result=-0.0f;for(size_t i=0;i<n;++i)result+=static_cast<float>(number_at(start+i));return result;}
                    if(n<=128){float accumulators[8];for(size_t k=0;k<8;++k)accumulators[k]=static_cast<float>(number_at(start+k));size_t i=8;for(;i<n-n%8;i+=8)for(size_t k=0;k<8;++k)accumulators[k]+=static_cast<float>(number_at(start+i+k));float result=((accumulators[0]+accumulators[1])+(accumulators[2]+accumulators[3]))+((accumulators[4]+accumulators[5])+(accumulators[6]+accumulators[7]));for(;i<n;++i)result+=static_cast<float>(number_at(start+i));return result;}
                    size_t half=n/2;half-=half%8;return sum(start,half)+sum(start+half,n-half);
                };result=sum(0,size());if(operation=="mean")return V::float32(static_cast<float>(result)/static_cast<float>(size()));
            }
            if(operation=="mean")result/=static_cast<double>(size());
            if(operation=="std"){const double mean=result/static_cast<double>(size());result=0;for(size_t i=0;i<size();++i){const double d=number_at(i)-mean;result+=d*d;}result=std::sqrt(result/static_cast<double>(size()));}
            return dtype=="float32"?V::float32(result):V(result);
        }
        int ax=static_cast<int>(axis.integral());if(ax<0)ax+=static_cast<int>(shape.size());if(ax<0||ax>=static_cast<int>(shape.size()))throw ValueError("array axis out of range");
        auto dimensions=shape;const int reduced=dimensions[static_cast<size_t>(ax)];dimensions.erase(dimensions.begin()+ax);auto out=std::make_shared<Array>(dimensions,operation=="any"||operation=="all"?"bool":(operation=="sum"&&(dtype=="bool"||dtype=="uint8"))?"int64":dtype);
        for(size_t target=0;target<out->size();++target){
            std::vector<size_t> coords(dimensions.size());size_t flat=target;for(size_t k=dimensions.size();k>0;--k){coords[k-1]=flat%static_cast<size_t>(dimensions[k-1]);flat/=static_cast<size_t>(dimensions[k-1]);}
            double result=operation=="all"?1:0;
            for(int r=0;r<reduced;++r){size_t source=0,c=0;for(size_t d=0;d<shape.size();++d)source=source*static_cast<size_t>(shape[d])+(d==static_cast<size_t>(ax)?static_cast<size_t>(r):coords[c++]);const double x=number_at(source);if(operation=="all")result=result!=0&&x!=0?1:0;else if(operation=="any")result=result!=0||x!=0?1:0;else result+=x;}
            out->number_put(target,result);
        }
        return out->shape.empty()?out->scalar(0):out->value();
    }
};
inline std::shared_ptr<Array> array(const V& value){
    if(value.kind==V::Kind::object)if(auto out=std::dynamic_pointer_cast<Array>(value.object))return out;
    throw TypeError("expected native array");
}
inline std::shared_ptr<Array> array_from_frame(const FrameState& frame){auto out=std::make_shared<Array>();out->shape={frame.height,frame.width,frame.channels};out->strides={static_cast<size_t>(frame.width)*frame.channels,static_cast<size_t>(frame.channels),1};out->dtype="uint8";out->data.reset();out->raw=frame.pixels.bytes;return out;}
inline std::shared_ptr<Array> array_from_value(const V& value,std::string dtype=""){
    if(value.kind==V::Kind::object){auto out=array(value)->copy();out->dtype=std::move(dtype);return out;}
    std::vector<int> shape;V dimension=value;while(dimension.sequence){shape.push_back(static_cast<int>(dimension.sequence->size()));if(dimension.sequence->empty())break;dimension=(*dimension.sequence)[0];}
    if(dtype.empty()){bool single=true,any=false;std::function<void(const V&)> inspect=[&](const V& x){if(x.sequence)for(const auto& y:*x.sequence)inspect(y);else{any=true;single=single&&x.kind==V::Kind::real32;}};inspect(value);dtype=any&&single?"float32":"float64";}
    auto out=std::make_shared<Array>(shape,std::move(dtype));size_t index=0;std::function<void(const V&)> fill=[&](const V& x){if(x.sequence)for(const auto& y:*x.sequence)fill(y);else out->number_put(index++,x.numeric());};fill(value);if(index!=out->size())throw ValueError("nonrectangular native array");return out;
}
inline V numpy_call(const std::string& method,const Args& args){
    if(method=="array")return array_from_value(args.get(0,"object"),args.get(1,"dtype",V("")).text())->value();
    if(method=="zeros"){std::vector<int> dims;auto it=iterate(args.get(0,"shape"));V x;while(it.next(x))dims.push_back(static_cast<int>(x.integral()));return std::make_shared<Array>(dims,args.get(1,"dtype",V("float64")).text())->value();}
    auto data=array(args.get(0,"a"));
    if(method=="sum"||method=="mean"||method=="std"||method=="max"||method=="any"||method=="all")return data->reduce(method,args.get(1,"axis",V{}));
    if(method=="count_nonzero"){long long count=0;for(size_t i=0;i<data->size();++i)if(data->number_at(i)!=0)++count;return V(count);}
    if(method=="unique"){std::vector<double> values;for(size_t i=0;i<data->size();++i)values.push_back(data->number_at(i));std::sort(values.begin(),values.end());values.erase(std::unique(values.begin(),values.end()),values.end());auto out=std::make_shared<Array>(std::vector<int>{static_cast<int>(values.size())},data->dtype);*out->data=std::move(values);return out->value();}
    if(method=="array_equal"){const V other=args.get(1,"a2");auto b=other.kind==V::Kind::object?array(other):array_from_value(other);if(data->shape!=b->shape)return V(false);for(size_t i=0;i<data->size();++i)if(data->number_at(i)!=b->number_at(i))return V(false);return V(true);}
    if(method=="abs"){auto out=std::make_shared<Array>(data->shape,data->dtype=="complex64"||data->dtype=="float32"?"float32":"float64");for(size_t i=0;i<data->size();++i){const auto x=data->complex_at(i);out->number_put(i,data->complex_data?(data->dtype=="complex64"?std::abs(std::complex<float>(static_cast<float>(x.real()),static_cast<float>(x.imag()))):std::abs(x)):std::abs(data->number_at(i)));}return out->value();}
    if(method=="fft"){
        if(data->shape.size()!=1)throw ValueError("pinned FFT requires a 1D profile");
        auto out=std::make_shared<Array>(data->shape,data->dtype=="float32"?"complex64":"complex128");out->complex_data=std::make_shared<std::vector<std::complex<double>>>(data->size());
        if(data->dtype=="float32"){
            std::vector<std::complex<float>> input(data->size()),output(data->size());for(size_t i=0;i<data->size();++i)input[i]=std::complex<float>(static_cast<float>(data->number_at(i)),0);
            pocketfft::c2c<float>({data->size()},{static_cast<ptrdiff_t>(sizeof(std::complex<float>))},{static_cast<ptrdiff_t>(sizeof(std::complex<float>))},{0},pocketfft::FORWARD,input.data(),output.data(),1.0f,1);
            for(size_t i=0;i<data->size();++i)(*out->complex_data)[i]=output[i];return out->value();
        }
        std::vector<std::complex<double>> input(data->size());for(size_t i=0;i<data->size();++i)input[i]=data->complex_at(i);
        pocketfft::c2c<double>({data->size()},{static_cast<ptrdiff_t>(sizeof(std::complex<double>))},{static_cast<ptrdiff_t>(sizeof(std::complex<double>))},{0},pocketfft::FORWARD,input.data(),out->complex_data->data(),1.0,1);return out->value();
    }
    throw AttributeError("unmapped NumPy operation: "+method);
}
inline V cv_call(const std::string& method,const Args& args){
    const auto source=array(args.get(0,"src"));
    if(method=="countNonZero"){Args values;values.pos(args.get(0,"src"));return numpy_call("count_nonzero",values);}
    if(method=="inRange"){
        const auto lower=args.get(1,"lowerb"),upper=args.get(2,"upperb");const auto lo=lower.kind==V::Kind::object?array(lower):array_from_value(lower),hi=upper.kind==V::Kind::object?array(upper):array_from_value(upper);
        if(source->shape.size()!=3)throw ValueError("inRange requires a channel dimension");const int channels=source->shape.back();auto dimensions=source->shape;dimensions.pop_back();auto out=std::make_shared<Array>(dimensions,"uint8");
        for(size_t i=0;i<out->size();++i){bool hit=true;for(int c=0;c<channels;++c){const auto x=source->number_at(i*static_cast<size_t>(channels)+static_cast<size_t>(c));if(x<lo->number_at(static_cast<size_t>(c))||x>hi->number_at(static_cast<size_t>(c)))hit=false;}out->number_put(i,hit?255:0);}return out->value();
    }
    if(method=="bitwise_and"){
        const auto other=array(args.get(1,"src2"));const V mask_value=args.get(2,"mask",V{});const auto mask=mask_value.is_none()?nullptr:array(mask_value);auto out=std::make_shared<Array>(source->shape,"uint8");const int channels=source->shape.size()==3?source->shape[2]:1;
        for(size_t i=0;i<source->size();++i)out->number_put(i,mask&&mask->number_at(i/static_cast<size_t>(channels))==0?0:static_cast<int>(source->number_at(i))&static_cast<int>(other->number_at(i)));return out->value();
    }
    const auto module=GetModuleHandleW(L"opencv_world4_maa.dll");if(!module)throw std::runtime_error("Maa OpenCV runtime unavailable");
    using Create=void*(__cdecl*)(int,int,int);using Set=void(__cdecl*)(void*,void*,int);using Release=void(__cdecl*)(void**);
    const auto create=api<Create>(module,"cvCreateMatHeader");const auto set=api<Set>(module,"cvSetData");const auto release=api<Release>(module,"cvReleaseMat");
    if(!create||!set||!release)throw std::runtime_error("Maa OpenCV C API missing");
    if(method=="cvtColor"){
        using Convert=void(__cdecl*)(const void*,void*,int);const auto convert=api<Convert>(module,"cvCvtColor");if(!convert)throw std::runtime_error("Maa cvCvtColor missing");
        if(source->shape.size()!=3||source->shape[2]!=3)throw ValueError("BGR conversion requires 3 channels");
        const int h=source->shape[0],w=source->shape[1];std::vector<unsigned char> bytes(source->size()),gray(static_cast<size_t>(h)*w);for(size_t i=0;i<bytes.size();++i)bytes[i]=static_cast<unsigned char>(source->number_at(i));
        void* input=create(h,w,16);void* output=create(h,w,0);set(input,bytes.data(),w*3);set(output,gray.data(),w);convert(input,output,static_cast<int>(args.get(1,"code").integral()));release(&input);release(&output);
        auto out=std::make_shared<Array>(std::vector<int>{h,w},"uint8");for(size_t i=0;i<gray.size();++i)out->number_put(i,gray[i]);return out->value();
    }
    if(method=="circle"){
        struct Point{int x,y;};struct Scalar{double values[4];};using Circle=void(__cdecl*)(void*,Point,int,Scalar,int,int,int);const auto circle=api<Circle>(module,"cvCircle");if(!circle)throw std::runtime_error("Maa cvCircle missing");
        if(source->shape.size()!=2)throw ValueError("circle mask must have 2 dimensions");const auto center=args.get(1,"center");const int h=source->shape[0],w=source->shape[1];std::vector<unsigned char> mask(source->size());for(size_t i=0;i<mask.size();++i)mask[i]=static_cast<unsigned char>(source->number_at(i));
        void* mat=create(h,w,0);set(mat,mask.data(),w);circle(mat,{static_cast<int>(item(center,V(0)).integral()),static_cast<int>(item(center,V(1)).integral())},static_cast<int>(args.get(2,"radius").integral()),{{args.get(3,"color").numeric(),0,0,0}},static_cast<int>(args.get(4,"thickness",V(1)).integral()),static_cast<int>(args.get(5,"lineType",V(8)).integral()),static_cast<int>(args.get(6,"shift",V(0)).integral()));release(&mat);for(size_t i=0;i<mask.size();++i)source->number_put(i,mask[i]);return args.get(0,"src");
    }
    throw AttributeError("unmapped OpenCV operation: "+method);
}
} // namespace official
