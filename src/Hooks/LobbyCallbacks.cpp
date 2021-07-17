#include "beatsaber-hook/shared/utils/utils.h"
#include "beatsaber-hook/shared/utils/il2cpp-utils.hpp"
#include "beatsaber-hook/shared/utils/hooking.hpp"

#include "modloader/shared/modloader.hpp"

#include "Photon/Realtime/LobbyCallbacksContainer.hpp"
#include "Photon/Realtime/RoomInfo.hpp"
#include "Photon/Realtime/TypedLobbyInfo.hpp"

#include "Callbacks/LobbyCallbacksInternal.hpp"

using RoomInfo = Photon::Realtime::RoomInfo;
using RoomList = List<RoomInfo*>;

using TypedLobbyInfo = Photon::Realtime::TypedLobbyInfo;
using LobbyList = List<TypedLobbyInfo*>;

using LobbyCallbacksContainer = Photon::Realtime::LobbyCallbacksContainer;

using namespace GorillaUtils;

// LobbyCallbacksContianer hooks
MAKE_HOOK_MATCH(LobbyCallbacksContainer_OnJoinedLobby, &LobbyCallbacksContainer::OnJoinedLobby, void, LobbyCallbacksContainer* self)
{
    LobbyCallbacksContainer_OnJoinedLobby(self);
    LobbyCallbacks::OnJoinedLobby();
}

MAKE_HOOK_MATCH(LobbyCallbacksContainer_OnLeftLobby, &LobbyCallbacksContainer::OnLeftLobby, void, LobbyCallbacksContainer* self)
{
    LobbyCallbacksContainer_OnLeftLobby(self);
    LobbyCallbacks::OnLeftLobby();
}

MAKE_HOOK_MATCH(LobbyCallbacksContainer_OnRoomListUpdate, &LobbyCallbacksContainer::OnRoomListUpdate, void, LobbyCallbacksContainer* self, RoomList* roomList)
{
    LobbyCallbacksContainer_OnRoomListUpdate(self, roomList);
    LobbyCallbacks::OnRoomListUpdate(roomList);
}

MAKE_HOOK_MATCH(LobbyCallbacksContainer_OnLobbyStatisticsUpdate, &LobbyCallbacksContainer::OnLobbyStatisticsUpdate, void, LobbyCallbacksContainer* self, LobbyList* lobbyList)
{
    LobbyCallbacksContainer_OnLobbyStatisticsUpdate(self, lobbyList);
    LobbyCallbacks::OnLobbyStatisticsUpdate(lobbyList);
}

void installLobbyCallbackHooks(Logger& logger)
{
    INSTALL_HOOK(logger, LobbyCallbacksContainer_OnJoinedLobby);
    INSTALL_HOOK(logger, LobbyCallbacksContainer_OnLeftLobby);
    INSTALL_HOOK(logger, LobbyCallbacksContainer_OnRoomListUpdate);
    INSTALL_HOOK(logger, LobbyCallbacksContainer_OnLobbyStatisticsUpdate);
}