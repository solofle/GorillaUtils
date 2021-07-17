#include "Callbacks/LobbyCallbacksInternal.hpp"
#include "Callbacks/LobbyCallbacks.hpp"
#include "CallbackUtils.hpp"

using RoomInfo = Photon::Realtime::RoomInfo;
using RoomList = List<RoomInfo>;

using TypedLobbyInfo = Photon::Realtime::TypedLobbyInfo;
using LobbyList = List<TypedLobbyInfo>;

namespace GorillaUtils::LobbyCallbacks
{
    EVENT(OnJoinedLobbyEvent, onJoinedLobbyEvent);
    EVENT(OnLeftLobbyEvent, onLeftLobbyEvent);
    EVENT(OnRoomListUpdateEvent, onRoomListUpdateEvent);
    EVENT(OnLobbyStatisticsUpdateEvent, onLobbyStatisticsUpdateEvent);

    void OnJoinedLobby() { RUNCALLBACKS(OnJoinedLobbyEvent); }
    void OnLeftLobby() { RUNCALLBACKS(OnLeftLobbyEvent); }
    void OnRoomListUpdate(RoomList* roomList) { RUNCALLBACKS(OnRoomListUpdateEvent, roomList); }
    void OnLobbyStatisticsUpdate(LobbyList* lobbyList) { RUNCALLBACKS(OnLobbyStatisticsUpdateEvent, lobbyList); }
}