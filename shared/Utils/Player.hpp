#pragma once

#include <string>

namespace Photon::Realtime {
    class Player;
}

namespace GlobalNamespace {
    class VRRig;
}

struct Il2CppString;

namespace GorillaUtils::Player
{
    using Player = Photon::Realtime::Player;
    using VRRig = GlobalNamespace::VRRig;

    /// @brief checks if a player is tagged
    /// @param player the player that is checked
    /// @return bool true for tagged false for not tagged
    bool isPlayerTagged(Player* player);
    
    /// @brief finds the vrrig for the given player
    /// @param player the player to find the rig for
    /// @return VRRig* or nullptr if not found
    VRRig* findPlayerVRRig(Player* player);
    
    /// @brief finds the vrrig for the given player ID
    /// @param userID the userID of the player to find the rig for
    /// @return VRRig* or nullptr if not found
    VRRig* findPlayerVRRig(Il2CppString* userID);

    /// @brief finds the vrrig for the given player ID
    /// @param userID the userID of the player to find the rig for
    /// @return VRRig* or nullptr if not found
    VRRig* findPlayerVRRig(std::string userID);
}