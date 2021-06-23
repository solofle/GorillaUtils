#pragma once

namespace Photon::Realtime {
    class Room;
}

namespace GlobalNamespace {
    class GorillaNetworkJoinTrigger;
}

#include <optional>
#include <string>

namespace GorillaUtils::Room
{
    using Room = Photon::Realtime::Room;
    using GorillaNetworkJoinTrigger = GlobalNamespace::GorillaNetworkJoinTrigger;

    /// @brief gets the room gameMode, contains both queue and gamemode
    /// @return optional string, nullopt if not in room
    std::optional<std::string> getRoomGameMode();
    
    /// @brief gets the room ID
    /// @return optional string, nullopt if not in room
    std::optional<std::string> get_roomID();

    /// @brief joins a room with roomID
    /// @param roomID the room id to join
    void joinRoom(std::string roomID);

    /// @brief joins a public room
    /// @param gameMode the gamemode to use
    void joinPublic(std::string gameMode);

    /// @brief joins a public room
    /// @param trigger the join trigger to use, this mostly translates to a gamemode that is used
    void joinPublic(GorillaNetworkJoinTrigger* trigger);

    /// @brief gets the gamemode from the current join trigger
    /// @return optional string, nullopt if trigger or string null
    std::optional<std::string> getGameMode();

    /// @brief gets if the current room is public
    /// @return optional bool true for public, false for not, nullopt for not in room
    std::optional<bool> getIsPublic();

    /// @brief opposite of getIsPublic
    /// @return optional bool true for private, false for not, nullopt for not in room
    std::optional<bool> getIsPrivate();
}