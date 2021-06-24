#pragma once
#include <type_traits>

namespace GorillaUtils::ArrayUtils
{
    template<typename T>
    void box_array(Array<Il2CppObject*>* arr, int index, T val) 
    {
        if constexpr (std::is_pointer_v<T>) arr->values[index] = val;
        else arr->values[index] = il2cpp_functions::value_box(classof(T), &val);
    }
    
    template <typename First, typename... Rest>
    void box_array(Array<Il2CppObject*>* arr, int index, First& first, Rest&... rest)
    {
        if constexpr (std::is_pointer_v<First>) arr->values[index] = first;
        else arr->values[index] = il2cpp_functions::value_box(classof(First), &first);

        box_array(arr, ++index, rest...);
    }
    
    template <typename First, typename... Rest>
    void box_array(Array<Il2CppObject*>* arr, First& first, Rest&... rest)
    {
        box_array(arr, 0, first, rest...);
    }
}