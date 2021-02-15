#pragma once
// Author: Jeff Pershing
// Source: https://github.com/preshing/FlexibleReflection
#include <vector>
#include <sstream>
#include <iostream>
#include <string>
#include <cstddef>

namespace reflect {

//--------------------------------------------------------
// Base class of all type descriptors
//--------------------------------------------------------

struct TypeDescriptor {
    const char* name;
    size_t size;

    TypeDescriptor(const char* name, size_t size) : name{name}, size{size} {}
    virtual ~TypeDescriptor() {}
    virtual std::string getFullName() const { return name; }
    virtual std::string GetDebugOutput(const void* obj, int indentLevel = 0) const = 0;
};

//--------------------------------------------------------
// Finding type descriptors
//--------------------------------------------------------

// Declare the function template that handles primitive types such as int, std::string, etc.:
template <typename T>
TypeDescriptor* getPrimitiveDescriptor();

// A helper class to find TypeDescriptors in different ways:
struct DefaultResolver {
    template <typename T> static char func(decltype(&T::Reflection));
    template <typename T> static int func(...);
    template <typename T>
    struct IsReflected {
        enum { value = (sizeof(func<T>(nullptr)) == sizeof(char)) };
    };

    // This version is called if T has a static member named "Reflection":
    template <typename T, typename std::enable_if<IsReflected<T>::value, int>::type = 0>
    static TypeDescriptor* get() {
        return &T::Reflection;
    }

    // This version is called otherwise:
    template <typename T, typename std::enable_if<!IsReflected<T>::value, int>::type = 0>
    static TypeDescriptor* get() {
        return getPrimitiveDescriptor<T>();
    }
};

// This is the primary class template for finding all TypeDescriptors:
template <typename T>
struct TypeResolver {
    static TypeDescriptor* get() {
        return DefaultResolver::get<T>();
    }
};

//--------------------------------------------------------
// Type descriptors for user-defined structs/classes
//--------------------------------------------------------

struct TypeDescriptor_Struct : TypeDescriptor {
    struct Member {
        const char* name;
        size_t offset;
        TypeDescriptor* type;
    };

    std::vector<Member> members;

    TypeDescriptor_Struct(void (*init)(TypeDescriptor_Struct*)) : TypeDescriptor{nullptr, 0} {
        init(this);
    }
    TypeDescriptor_Struct(const char* name, size_t size, const std::initializer_list<Member>& init) : TypeDescriptor{nullptr, 0}, members{init} {
    }
    virtual std::string GetDebugOutput(const void* obj, int indentLevel) const override {
        std::ostringstream   output;
        output << name << " {" << std::endl;
        for (const Member& member : members) {
            output << std::string(4 * (indentLevel + 1), ' ') << member.name << ": ";
            output << member.type->GetDebugOutput((char*) obj + member.offset, indentLevel + 1) << std::endl;
        }
        output << std::string(4 * indentLevel, ' ') << "}";
        return output.str();
    }
};

#define REFLECT() \
    friend struct reflect::DefaultResolver; \
    static reflect::TypeDescriptor_Struct Reflection; \
    static void initReflection(reflect::TypeDescriptor_Struct*);

#define REFLECT_STRUCT_BEGIN(type) \
    reflect::TypeDescriptor_Struct type::Reflection{type::initReflection}; \
    void type::initReflection(reflect::TypeDescriptor_Struct* typeDesc) { \
        using T = type; \
        typeDesc->name = #type; \
        typeDesc->size = sizeof(T); \
        typeDesc->members = {

#define REFLECT_STRUCT_MEMBER(name) \
            {#name, offsetof(T, name), reflect::TypeResolver<decltype(T::name)>::get()},

#define REFLECT_STRUCT_END() \
        }; \
    }

//--------------------------------------------------------
// Type descriptors for std::vector
//--------------------------------------------------------

struct TypeDescriptor_StdVector : TypeDescriptor {
    TypeDescriptor* itemType;
    size_t (*getSize)(const void*);
    const void* (*getItem)(const void*, size_t);

    template <typename ItemType>
    TypeDescriptor_StdVector(ItemType*)
        : TypeDescriptor{"std::vector<>", sizeof(std::vector<ItemType>)},
                         itemType{TypeResolver<ItemType>::get()} {
        getSize = [](const void* vecPtr) -> size_t {
            const auto& vec = *(const std::vector<ItemType>*) vecPtr;
            return vec.size();
        };
        getItem = [](const void* vecPtr, size_t index) -> const void* {
            const auto& vec = *(const std::vector<ItemType>*) vecPtr;
            return &vec[index];
        };
    }
    virtual std::string getFullName() const override {
        return std::string("std::vector<") + itemType->getFullName() + ">";
    }
    virtual std::string GetDebugOutput(const void* obj, int indentLevel) const override {
        std::ostringstream   output;
        size_t numItems = getSize(obj);
        output << getFullName() << " ";
        if (numItems == 0) {
            output << "{}";
        } else {
            output << "{" << std::endl;
            for (size_t index = 0; index < numItems; index++) {
                output << std::string(4 * (indentLevel + 1), ' ') << "[" << index << "] ";
                output << itemType->GetDebugOutput(getItem(obj, index), indentLevel + 1) << std::endl;
                output ;
            }
            output << std::string(4 * indentLevel, ' ') << "}";
        }
        return output.str();
    }
};

// Partially specialize TypeResolver<> for std::vectors:
template <typename T>
class TypeResolver<std::vector<T>> {
public:
    static TypeDescriptor* get() {
        static TypeDescriptor_StdVector typeDesc{(T*) nullptr};
        return &typeDesc;
    }
};

} // namespace reflect
