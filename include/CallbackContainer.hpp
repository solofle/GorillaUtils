#pragma once

#include <map>

namespace GorillaUtils
{
    template<class T>
    class CallbackContainer
    {
        public:
            void remove(int identifier)
            {
                auto it = callbacks.find(identifier);
                if (it != callbacks.end()) callbacks.erase(it, it++);
            }
    
            int add(T callback)
            {
                callbacks[counter] = callback;
                counter++;
                return counter - 1;
            }
    
            std::map<int, T>& get()
            {
                return callbacks;
            }

        private:
            std::map<int, T> callbacks = {};
            int counter = 0;
    };
}