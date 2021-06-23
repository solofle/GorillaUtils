#include "Callbacks/LobbyCallbacksInternal.hpp"
#include "Callbacks/LobbyCallbacks.hpp"
#include "CallbackUtils.hpp"

using RoomInfo = Photon::Realtime::RoomInfo;
using RoomList = List<RoomInfo>;

using TypedLobbyInfo = Photon::Realtime::TypedLobbyInfo;
using LobbyList = List<TypedLobbyInfo>;

namespace GorillaUtils::LobbyCallbacks
{
    OnJoinedLobbyCallbackContainer onJoinedLobbyCallbackContainer;
    OnLeftLobbyCallbackContainer onLeftLobbyCallbackContainer;
    OnRoomListUpdateCallbackContainer onRoomListUpdateCallbackContainer;
    OnLobbyStatisticsUpdateCallbackContainer onLobbyStatisticsUpdateCallbackContainer;

    void OnJoinedLobby() { RUNCALLBACKS(onJoinedLobbyCallbackContainer); }
    void OnLeftLobby() { RUNCALLBACKS(onLeftLobbyCallbackContainer); }
    void OnRoomListUpdate(RoomList* roomList) { RUNCALLBACKS(onRoomListUpdateCallbackContainer, roomList); }
    void OnLobbyStatisticsUpdate(LobbyList* lobbyList) { RUNCALLBACKS(onLobbyStatisticsUpdateCallbackContainer, lobbyList); }

    int add_OnJoinedLobby(OnJoinedLobbyCallback callback) { return ADD(onJoinedLobbyCallbackContainer); }
    int add_OnLeftLobby(OnLeftLobbyCallback callback) { return ADD(onLeftLobbyCallbackContainer); }
    int add_OnRoomListUpdate(OnRoomListUpdateCallback callback) { return ADD(onRoomListUpdateCallbackContainer); }
    int add_OnLobbyStatisticsUpdate(OnLobbyStatisticsUpdateCallback callback) { return ADD(onLobbyStatisticsUpdateCallbackContainer); }

    void remove_OnJoinedLobby(int identifier) { REMOVE(onJoinedLobbyCallbackContainer); }
    void remove_OnLeftLobby(int identifier) { REMOVE(onLeftLobbyCallbackContainer); }
    void remove_OnRoomListUpdate(int identifier) { REMOVE(onRoomListUpdateCallbackContainer); }
    void remove_OnLobbyStatisticsUpdate(int identifier) { REMOVE(onLobbyStatisticsUpdateCallbackContainer); }

}