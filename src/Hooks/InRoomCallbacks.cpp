#include "beatsaber-hook/shared/utils/utils.h"
#include "beatsaber-hook/shared/utils/il2cpp-utils.hpp"
#include "beatsaber-hook/shared/utils/hooking.hpp"

#include "modloader/shared/modloader.hpp"

#include "Callbacks/InRoomCallbacksInternal.hpp"

#include "Photon/Realtime/InRoomCallbacksContainer.hpp"
#include "Photon/Realtime/Player.hpp"
#include "ExitGames/Client/Photon/Hashtable.hpp"

using Player = Photon::Realtime::Player;
using Hashtable = ExitGames::Client::Photon::Hashtable;

using InRoomCallbacksContainer = Photon::Realtime::InRoomCallbacksContainer;

using namespace GorillaUtils;

extern Logger& getLogger();

// InRoomCallbacksContainer Hooks
MAKE_HOOK_MATCH(InRoomCallbacksContainer_OnPlayerEnteredRoom, &InRoomCallbacksContainer::OnPlayerEnteredRoom, void, InRoomCallbacksContainer* self, Player* newPlayer)
{
    InRoomCallbacksContainer_OnPlayerEnteredRoom(self, newPlayer);
    InRoomCallbacks::OnPlayerEnteredRoom(newPlayer);
}

MAKE_HOOK_MATCH(InRoomCallbacksContainer_OnPlayerLeftRoom, &InRoomCallbacksContainer::OnPlayerLeftRoom, void, InRoomCallbacksContainer* self, Player* otherPlayer)
{
    InRoomCallbacksContainer_OnPlayerLeftRoom(self, otherPlayer);
    InRoomCallbacks::OnPlayerLeftRoom(otherPlayer);
}

MAKE_HOOK_MATCH(InRoomCallbacksContainer_OnRoomPropertiesUpdate, &InRoomCallbacksContainer::OnRoomPropertiesUpdate, void, InRoomCallbacksContainer* self, Hashtable* propertiesThatChanged)
{
    InRoomCallbacksContainer_OnRoomPropertiesUpdate(self, propertiesThatChanged);
    InRoomCallbacks::OnRoomPropertiesUpdate(propertiesThatChanged);
}

MAKE_HOOK_MATCH(InRoomCallbacksContainer_OnPlayerPropertiesUpdate, &InRoomCallbacksContainer::OnPlayerPropertiesUpdate, void, InRoomCallbacksContainer* self, Player* targetPlayer, Hashtable* changedProp)
{
    InRoomCallbacksContainer_OnPlayerPropertiesUpdate(self, targetPlayer, changedProp);
    InRoomCallbacks::OnPlayerPropertiesUpdate(targetPlayer, changedProp);
}

MAKE_HOOK_MATCH(InRoomCallbacksContainer_OnMasterClientSwitched, &InRoomCallbacksContainer::OnMasterClientSwitched, void, InRoomCallbacksContainer* self, Player* newMasterClient)
{
    InRoomCallbacksContainer_OnMasterClientSwitched(self, newMasterClient);
    InRoomCallbacks::OnMasterClientSwitched(newMasterClient);
}

void installInRoomCallbackHooks(Logger& logger)
{
    INSTALL_HOOK(logger, InRoomCallbacksContainer_OnPlayerEnteredRoom);
    INSTALL_HOOK(logger, InRoomCallbacksContainer_OnPlayerLeftRoom);
    INSTALL_HOOK(logger, InRoomCallbacksContainer_OnRoomPropertiesUpdate);
    INSTALL_HOOK(logger, InRoomCallbacksContainer_OnPlayerPropertiesUpdate);
    INSTALL_HOOK(logger, InRoomCallbacksContainer_OnMasterClientSwitched);
}
