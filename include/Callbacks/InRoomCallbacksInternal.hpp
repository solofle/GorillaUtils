#pragma once

#include "CallbackContainer.hpp"
#include "Callbacks/InRoomCallbacks.hpp"

namespace GorillaUtils::InRoomCallbacks
{
    void OnPlayerEnteredRoom(Player* newPlayer);
    void OnPlayerLeftRoom(Player* otherPlayer);
    void OnRoomPropertiesUpdate(Hashtable* propertiesThatChanged);
    void OnPlayerPropertiesUpdate(Player* targetPlayer, Hashtable* changedProp);
    void OnMasterClientSwitched(Player* newMasterClient);
}