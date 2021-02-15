#include "solid_exemple_lib/Reflect.h"

namespace reflect {

//--------------------------------------------------------
// A type descriptor for int
//--------------------------------------------------------

struct TypeDescriptor_Int : TypeDescriptor {
    TypeDescriptor_Int() : TypeDescriptor{"int", sizeof(int)} {
    }
    virtual std::string GetDebugOutput(const void* obj, int /* unused */) const override {
        std::ostringstream   output;
        output << *(const int*)obj << " {int}";
        return output.str();
    }
};

template <>
TypeDescriptor* getPrimitiveDescriptor<int>() {
    static TypeDescriptor_Int typeDesc;
    return &typeDesc;
}


//--------------------------------------------------------
// A type descriptor for int
//--------------------------------------------------------

struct TypeDescriptor_Float: TypeDescriptor {
    TypeDescriptor_Float() : TypeDescriptor{ "float", sizeof(float) } {
    }
    virtual std::string GetDebugOutput(const void* obj, int /* unused */) const override {
        std::ostringstream   output;
        output << *(const float*)obj << " {float}";
        return output.str();
    }
};

template <>
TypeDescriptor* getPrimitiveDescriptor<float>() {
    static TypeDescriptor_Float typeDesc;
    return &typeDesc;
}

//--------------------------------------------------------
// A type descriptor for std::string
//--------------------------------------------------------

struct TypeDescriptor_StdString : TypeDescriptor {
    TypeDescriptor_StdString() : TypeDescriptor{"std::string", sizeof(std::string)} {
    }
    virtual std::string GetDebugOutput(const void* obj, int /* unused */) const override {
        std::ostringstream   output;
        output << "\"" << *(const std::string*)obj << "\"" << " {string}";
        return output.str();
    }
};

template <>
TypeDescriptor* getPrimitiveDescriptor<std::string>() {
    static TypeDescriptor_StdString typeDesc;
    return &typeDesc;
}

} // namespace reflect
