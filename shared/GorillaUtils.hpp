#pragma once

#include "modloader/shared/modloader.hpp"
#include <vector>
#include <string>

namespace GorillaUtils
{
    /// @brief initializes the lib
    void Init();

    /// @brief innitializes the lib
    void Innit();

    /// @brief registers a boolean to be automatically updated upon joining lobbies, checks for queues too
    /// @param value boolean reference to the bool that will get updated
    /// @param allowedQueues vector of queues that set the bool to true
    /// @param name mod name registering
    /// @param version mod version
    void RegisterDisablingValue(std::string name, std::string version, bool& value, std::vector<std::string> queues = {});

    /// @brief registers a boolean to be automatically updated upon joining lobbies, checks for queues too
    /// @param value boolean reference to the bool that will get updated
    /// @param allowedQueues vector of queues that set the bool to true
    /// @param info registering mod info
    void RegisterDisablingValue(ModInfo info, bool& value, std::vector<std::string> queues = {});

    /// @brief registers a boolean to be automatically updated upon joining lobbies, checks for queues too
    /// @param value boolean reference to the bool that will get updated
    /// @param allowLocal if the user leaves a room, should the value be updated to be allowed?
    /// @param allowedQueues vector of queues that set the bool to true
    /// @param name mod name registering
    /// @param version mod version
    void RegisterDisablingValue(std::string name, std::string version, bool& value, bool allowLocal = false, std::vector<std::string> queues = {});

    /// @brief registers a boolean to be automatically updated upon joining lobbies, checks for queues too
    /// @param value boolean reference to the bool that will get updated
    /// @param allowLocal if the user leaves a room, should the value be updated to be allowed?
    /// @param allowedQueues vector of queues that set the bool to true
    /// @param info registering mod info
    void RegisterDisablingValue(ModInfo info, bool& value, bool allowLocal = false, std::vector<std::string> queues = {});
}