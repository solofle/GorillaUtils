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

            void set_ifLocal();
            void set_value(bool value);

            /// @brief checks if the queue contains any of the allowed queues
            /// @return true for valid queue, false for not found
            bool checkQueue(std::string queue);
            bool get_value();
            ModInfo get_info();
            
        private:
            ModInfo info;
            bool* value;
            bool allowLocal;
            std::vector<std::string> queues = {};
    };
}