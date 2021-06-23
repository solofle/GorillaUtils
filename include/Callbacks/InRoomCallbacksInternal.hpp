#pragma once

#include "CallbackContainer.hpp"
#include "Callbacks/InRoomCallbacks.hpp"

namespace GorillaUtils::InRoomCallbacks
{
    typedef CallbackContainer<OnPlayerEnteredRoomCallback> OnPlayerEnteredRoomCallbackContainer;
    typedef CallbackContainer<OnPlayerLeftRoomCallback> OnPlayerLeftRoomCallbackContainer;
    typedef CallbackContainer<OnRoomPropertiesUpdateCallback> OnRoomPropertiesUpdateCallbackContainer;
    typedef CallbackContainer<OnPlayerPropertiesUpdateCallback> OnPlayerPropertiesUpdateCallbackContainer;
    typedef CallbackContainer<OnMasterClientSwitchedCallback> OnMasterClientSwitchedCallbackContainer;

    /// @brief call this when a new player entered the room
    void OnPlayerEnteredRoom(Player* newPlayer);

    /// @brief call this when a player leaves the room
    void OnPlayerLeftRoom(Player* otherPlayer);

    /// @brief when the room properties change this gets called
    void OnRoomPropertiesUpdate(Hashtable* propertiesThatChanged);

    /// @brief when a players properties get updated, this gets called
    void OnPlayerPropertiesUpdate(Player* targetPlayer, Hashtable* changedProp);

    /// @brief when the master client switches this gets called
    void OnMasterClientSwitched(Player* newMasterClient);
}