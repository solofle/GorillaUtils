#include "DisablingValueContainer.hpp"
#include "beatsaber-hook/shared/utils/utils.h"

extern Logger& getLogger();

namespace GorillaUtils
{
    void DisablingValueContainer::set_ifLocal()
    {
        if (value)
            *value = allowLocal;
    }

    void DisablingValueContainer::set_value(bool value)
    {
        getLogger().info("Updating %s to %d", info.id.c_str(), value);
        if (this->value) *this->value = value;
    }

    bool DisablingValueContainer::checkQueue(std::string queue)
    {
        // if this entry has no allowedqueues then just tell it not to work
        if (queues.size() == 0 || queue == "") return false;
        else for (auto q : queues)
        {
            if (queue.find(q) != std::string::npos) return true;
        }
        return false;
    }
            
    bool DisablingValueContainer::get_value()
    {
        if (value) return *value;
        else return false;
    }

    ModInfo DisablingValueContainer::get_info()
    {
        return info;
    }
}