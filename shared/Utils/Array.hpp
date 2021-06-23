#pragma once

namespace GorillaUtils::ArrayUtils
{
    template<typename T>
    T* toPtr(T& val)
    {
        static_assert(is_value_type<T>());
        return &val;
    }
    
    template<typename T>
    T* toPtr(T* val)
    {
        static_assert(std::is_pointer<T>());
        return val;
    }
    
    template<typename T>
    void box_array(Array<Il2CppObject*>* arr, int index, T val) 
    {
        arr->values[index] = il2cpp_functions::value_box(classof(T), toPtr(val));
    }
    
    template <typename First, typename... Rest>
    void box_array(Array<Il2CppObject*>* arr, int index, First& first, Rest&... rest)
    {
        arr->values[index] = il2cpp_functions::value_box(classof(First), toPtr(first));
        box_array(arr, ++index, rest...);
    }
    
    template <typename First, typename... Rest>
    void box_array(Array<Il2CppObject*>* arr, First& first, Rest&... rest)
    {
        box_array(arr, 0, first, rest...);
    }
}