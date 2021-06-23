#include "beatsaber-hook/shared/utils/utils.h"
#include "beatsaber-hook/shared/utils/il2cpp-utils.hpp"

#include "modloader/shared/modloader.hpp"

#include "Photon/Realtime/RoomInfo.hpp"
#include "Photon/Realtime/TypedLobbyInfo.hpp"

#include "Callbacks/LobbyCallbacksInternal.hpp"

namespace Photon::Realtime {
    class LobbyCallbacksContainer;
}

using RoomInfo = Photon::Realtime::RoomInfo;
using RoomList = List<RoomInfo*>;

using TypedLobbyInfo = Photon::Realtime::TypedLobbyInfo;
using LobbyList = List<TypedLobbyInfo*>;

using LobbyCallbacksContainer = Photon::Realtime::LobbyCallbacksContainer;

using namespace GorillaUtils;

// LobbyCallbacksContianer hooks
MAKE_HOOK_OFFSETLESS(LobbyCallbacksContainer_OnJoinedLobby, void, LobbyCallbacksContainer* self)
{
    LobbyCallbacksContainer_OnJoinedLobby(self);
    LobbyCallbacks::OnJoinedLobby();
}

MAKE_HOOK_OFFSETLESS(LobbyCallbacksContainer_OnLeftLobby, void, LobbyCallbacksContainer* self)
{
    LobbyCallbacksContainer_OnLeftLobby(self);
    LobbyCallbacks::OnLeftLobby();
}

MAKE_HOOK_OFFSETLESS(LobbyCallbacksContainer_OnRoomListUpdate, void, LobbyCallbacksContainer* self, RoomList* roomList)
{
    LobbyCallbacksContainer_OnRoomListUpdate(self, roomList);
    LobbyCallbacks::OnRoomListUpdate(roomList);
}

MAKE_HOOK_OFFSETLESS(LobbyCallbacksContainer_OnLobbyStatisticsUpdate, void, LobbyCallbacksContainer* self, LobbyList* lobbyList)
{
    LobbyCallbacksContainer_OnLobbyStatisticsUpdate(self, lobbyList);
    LobbyCallbacks::OnLobbyStatisticsUpdate(lobbyList);
}

void installLobbyCallbackHooks(Logger& logger)
{
    INSTALL_HOOK_OFFSETLESS(logger, LobbyCallbacksContainer_OnJoinedLobby, il2cpp_utils::FindMethodUnsafe("Photon.Realtime", "LobbyCallbacksContainer", "OnJoinedLobby", 0));
    INSTALL_HOOK_OFFSETLESS(logger, LobbyCallbacksContainer_OnLeftLobby, il2cpp_utils::FindMethodUnsafe("Photon.Realtime", "LobbyCallbacksContainer", "OnLeftLobby", 0));
    INSTALL_HOOK_OFFSETLESS(logger, LobbyCallbacksContainer_OnRoomListUpdate, il2cpp_utils::FindMethodUnsafe("Photon.Realtime", "LobbyCallbacksContainer", "OnRoomListUpdate", 1));
    INSTALL_HOOK_OFFSETLESS(logger, LobbyCallbacksContainer_OnLobbyStatisticsUpdate, il2cpp_utils::FindMethodUnsafe("Photon.Realtime", "LobbyCallbacksContainer", "OnLobbyStatisticsUpdate", 1));
}