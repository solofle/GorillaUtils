#pragma once
#include <type_traits>

namespace GorillaUtils::ArrayUtils
{
    template<typename T>
    void box_array(Array<Il2CppObject*>* arr, int index, T val) 
    {
        static_assert(std::is_convertible<T, Il2CppObject*>::value || std::is_arithmetic<T>::value, "Property type should be convertible to Il2CppObject*, or be an arithmetic type");
        if constexpr (std::is_pointer_v<T>) arr->values[index] = val;
        else arr->values[index] = il2cpp_functions::value_box(classof(T), &val);
    }
    
    template <typename First, typename... Rest>
    void box_array(Array<Il2CppObject*>* arr, int index, First& first, Rest&... rest)
    {
        static_assert(std::is_convertible<First, Il2CppObject*>::value || std::is_arithmetic<First>::value, "Property type should be convertible to Il2CppObject*, or be an arithmetic type");
        if constexpr (std::is_pointer_v<First>) arr->values[index] = first;
        else arr->values[index] = il2cpp_functions::value_box(classof(First), &first);

        box_array(arr, ++index, rest...);
    }
    
    template <typename First, typename... Rest>
    void box_array(Array<Il2CppObject*>* arr, First& first, Rest&... rest)
    {
        static_assert(std::is_convertible<First, Il2CppObject*>::value || std::is_arithmetic<First>::value, "Property type should be convertible to Il2CppObject*, or be an arithmetic type");
        box_array(arr, 0, first, rest...);
    }
}