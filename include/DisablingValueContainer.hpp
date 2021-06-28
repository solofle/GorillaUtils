#pragma once

#include <vector>
#include <string>
#include "modloader/shared/modloader.hpp"

namespace GorillaUtils
{
    class DisablingValueContainer
    {
        public:
            DisablingValueContainer(ModInfo info, bool& value, bool allowLocal, std::vector<std::string> queues) : info(info), value(&value), allowLocal(allowLocal), queues(queues) {};

            void set_ifLocal()
            {
                if (value)
                    *value = allowLocal;
            }

            void set_value(bool value)
            {
                if (this->value) *this->value = value;
            }

            /// @brief checks if the queue contains any of the allowed queues
            /// @return true for valid queue, false for not found
            bool checkQueue(std::string queue)
            {
                // if this entry has no allowedqueues then just tell it not to work
                if (queues.size() == 0 || queue == "") return false;
                else for (auto q : queues)
                {
                    if (queue.find(q) != std::string::npos) return true;
                }
                return false;
            }
            
            bool get_value()
            {
                if (value) return *value;
                else return false;
            }

            ModInfo get_info()
            {
                return info;
            }
            
        private:
            ModInfo info;
            bool* value;
            bool allowLocal;
            std::vector<std::string> queues = {};
    };
}