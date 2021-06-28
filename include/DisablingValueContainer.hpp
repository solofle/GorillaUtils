#pragma once

#include <vector>
#include <string>

namespace GorillaUtils
{
    class DisablingValueContainer
    {
        public:
            DisablingValueContainer(bool& value, bool allowLocal, std::vector<std::string> queues) : value(value), allowLocal(allowLocal), queues(queues) {};

            void set_ifLocal()
            {
                value = allowLocal;
            }

            void set_value(bool value)
            {
                this->value = value;
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
            
        private:
            bool& value;
            bool allowLocal;
            std::vector<std::string> queues = {};
    };
}