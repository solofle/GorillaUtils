#pragma once

#include "CallbackContainer.hpp"
#include "Callbacks/LobbyCallbacks.hpp"

namespace GorillaUtils::LobbyCallbacks
{
    typedef CallbackContainer<OnJoinedLobbyCallback> OnJoinedLobbyCallbackContainer;
    typedef CallbackContainer<OnLeftLobbyCallback> OnLeftLobbyCallbackContainer;
    typedef CallbackContainer<OnRoomListUpdateCallback> OnRoomListUpdateCallbackContainer;
    typedef CallbackContainer<OnLobbyStatisticsUpdateCallback> OnLobbyStatisticsUpdateCallbackContainer;
    
    void OnJoinedLobby();
    void OnLeftLobby();
    void OnRoomListUpdate(RoomList* roomList);
    void OnLobbyStatisticsUpdate(LobbyList* lobbyList);
}