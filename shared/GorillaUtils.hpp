#pragma once

#include <vector>
#include <string>

namespace GorillaUtils
{
    void Init();
    void Innit();

    /// @brief registers a boolean to be automatically updated upon joining lobbies
    /// @param value boolean reference to the bool that will get updated
    void RegisterDisablingValue(bool& value);
    
    /// @brief registers a boolean to be automatically updated upon joining lobbies
    /// @param value boolean reference to the bool that will get updated
    /// @param allowLocal if the user leaves a room, should the value be updated to be allowed?
    void RegisterDisablingValue(bool& value, bool allowLocal);
    
    /// @brief registers a boolean to be automatically updated upon joining lobbies, checks for queues too
    /// @param value boolean reference to the bool that will get updated
    /// @param allowedQueues vector of queues that set the bool to true
    void RegisterDisablingValue(bool& value, std::vector<std::string> queues);

    /// @brief registers a boolean to be automatically updated upon joining lobbies, checks for queues too
    /// @param value boolean reference to the bool that will get updated
    /// @param allowLocal if the user leaves a room, should the value be updated to be allowed?
    /// @param allowedQueues vector of queues that set the bool to true
    void RegisterDisablingValue(bool& value, bool allowLocal, std::vector<std::string> queues);
}