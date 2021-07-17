#pragma once

#include "beatsaber-hook/shared/utils/typedefs-wrappers.hpp"
#include <functional>
#include "Photon/Realtime/RoomInfo.hpp"
#include "Photon/Realtime/TypedLobbyInfo.hpp"

namespace GorillaUtils::LobbyCallbacks
{
    using RoomInfo = Photon::Realtime::RoomInfo;
    using RoomList = List<RoomInfo*>;

    using TypedLobbyInfo = Photon::Realtime::TypedLobbyInfo;
    using LobbyList = List<TypedLobbyInfo*>;

    typedef UnorderedEventCallback<> OnJoinedLobbyEvent;
    typedef UnorderedEventCallback<> OnLeftLobbyEvent;
    typedef UnorderedEventCallback<RoomList*> OnRoomListUpdateEvent;
    typedef UnorderedEventCallback<LobbyList*> OnLobbyStatisticsUpdateEvent;

    OnJoinedLobbyEvent& onJoinedLobbyEvent();
    OnLeftLobbyEvent& onLeftLobbyEvent();
    OnRoomListUpdateEvent& onRoomListUpdateEvent();
    OnLobbyStatisticsUpdateEvent& onLobbyStatisticsUpdateEvent();
}