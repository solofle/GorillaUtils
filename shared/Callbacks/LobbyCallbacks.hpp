#pragma once

#include <functional>
#include "Photon/Realtime/RoomInfo.hpp"
#include "Photon/Realtime/TypedLobbyInfo.hpp"

namespace GorillaUtils::LobbyCallbacks
{
    using RoomInfo = Photon::Realtime::RoomInfo;
    using RoomList = List<RoomInfo*>;

    using TypedLobbyInfo = Photon::Realtime::TypedLobbyInfo;
    using LobbyList = List<TypedLobbyInfo*>;

    typedef std::function<void(void)> OnJoinedLobbyCallback;
    typedef std::function<void(void)> OnLeftLobbyCallback;
    typedef std::function<void(RoomList*)> OnRoomListUpdateCallback;
    typedef std::function<void(LobbyList*)> OnLobbyStatisticsUpdateCallback;

    int add_OnJoinedLobby(OnJoinedLobbyCallback callback);
    int add_OnLeftLobby(OnLeftLobbyCallback callback);
    int add_OnRoomListUpdate(OnRoomListUpdateCallback callback);
    int add_OnLobbyStatisticsUpdate(OnLobbyStatisticsUpdateCallback callback);

    void remove_OnJoinedLobby(int identifier);
    void remove_OnLeftLobby(int identifier);
    void remove_OnRoomListUpdate(int identifier);
    void remove_OnLobbyStatisticsUpdate(int identifier);
}