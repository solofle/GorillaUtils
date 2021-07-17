#pragma once

#include "CallbackContainer.hpp"
#include "Callbacks/LobbyCallbacks.hpp"

namespace GorillaUtils::LobbyCallbacks
{
    void OnJoinedLobby();
    void OnLeftLobby();
    void OnRoomListUpdate(RoomList* roomList);
    void OnLobbyStatisticsUpdate(LobbyList* lobbyList);
}