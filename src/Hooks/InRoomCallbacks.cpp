#include "beatsaber-hook/shared/utils/utils.h"
#include "beatsaber-hook/shared/utils/il2cpp-utils.hpp"

#include "modloader/shared/modloader.hpp"

#include "Callbacks/InRoomCallbacksInternal.hpp"

namespace Photon::Realtime {
    class InRoomCallbacksContainer;
}

using Player = Photon::Realtime::Player;
using Hashtable = ExitGames::Client::Photon::Hashtable;

using InRoomCallbacksContainer = Photon::Realtime::InRoomCallbacksContainer;

using namespace GorillaUtils;

// InRoomCallbacksContainer Hooks
MAKE_HOOK_OFFSETLESS(InRoomCallbacksContainer_OnPlayerEnteredRoom, void, InRoomCallbacksContainer* self, Player* newPlayer)
{
    InRoomCallbacksContainer_OnPlayerEnteredRoom(self, newPlayer);
    InRoomCallbacks::OnPlayerEnteredRoom(newPlayer);
}

MAKE_HOOK_OFFSETLESS(InRoomCallbacksContainer_OnPlayerLeftRoom, void, InRoomCallbacksContainer* self, Player* otherPlayer)
{
    InRoomCallbacksContainer_OnPlayerLeftRoom(self, otherPlayer);
    InRoomCallbacks::OnPlayerLeftRoom(otherPlayer);
}

MAKE_HOOK_OFFSETLESS(InRoomCallbacksContainer_OnRoomPropertiesUpdate, void, InRoomCallbacksContainer* self, Hashtable* propertiesThatChanged)
{
    InRoomCallbacksContainer_OnRoomPropertiesUpdate(self, propertiesThatChanged);
    InRoomCallbacks::OnRoomPropertiesUpdate(propertiesThatChanged);
}

MAKE_HOOK_OFFSETLESS(InRoomCallbacksContainer_OnPlayerPropertiesUpdate, void, InRoomCallbacksContainer* self, Player* targetPlayer, Hashtable* changedProp)
{
    InRoomCallbacksContainer_OnPlayerPropertiesUpdate(self, targetPlayer, changedProp);
    InRoomCallbacks::OnPlayerPropertiesUpdate(targetPlayer, changedProp);
}

MAKE_HOOK_OFFSETLESS(InRoomCallbacksContainer_OnMasterClientSwitched, void, InRoomCallbacksContainer* self, Player* newMasterClient)
{
    InRoomCallbacksContainer_OnMasterClientSwitched(self, newMasterClient);
    InRoomCallbacks::OnMasterClientSwitched(newMasterClient);
}

void installInRoomCallbackHooks(Logger& logger)
{
    INSTALL_HOOK_OFFSETLESS(logger, InRoomCallbacksContainer_OnPlayerEnteredRoom, il2cpp_utils::FindMethodUnsafe("Photon.Realtime", "InRoomCallbacksContainer", "OnPlayerEnteredRoom", 1));
    INSTALL_HOOK_OFFSETLESS(logger, InRoomCallbacksContainer_OnPlayerLeftRoom, il2cpp_utils::FindMethodUnsafe("Photon.Realtime", "InRoomCallbacksContainer", "OnPlayerLeftRoom", 1));
    INSTALL_HOOK_OFFSETLESS(logger, InRoomCallbacksContainer_OnPlayerEnteredRoom, il2cpp_utils::FindMethodUnsafe("Photon.Realtime", "InRoomCallbacksContainer", "OnRoomPropertiesUpdate", 1));
    INSTALL_HOOK_OFFSETLESS(logger, InRoomCallbacksContainer_OnPlayerEnteredRoom, il2cpp_utils::FindMethodUnsafe("Photon.Realtime", "InRoomCallbacksContainer", "OnPlayerPropertiesUpdate", 2));
    INSTALL_HOOK_OFFSETLESS(logger, InRoomCallbacksContainer_OnPlayerEnteredRoom, il2cpp_utils::FindMethodUnsafe("Photon.Realtime", "InRoomCallbacksContainer", "OnMasterClientSwitched", 1));
}
