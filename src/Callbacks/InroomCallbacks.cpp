#include "Callbacks/InRoomCallbacksInternal.hpp"
#include "Callbacks/InRoomCallbacks.hpp"
#include "CallbackUtils.hpp"

namespace GorillaUtils::InRoomCallbacks
{
    OnPlayerEnteredRoomCallbackContainer onPlayerEnteredRoomCallbackContainer;
    OnPlayerLeftRoomCallbackContainer onPlayerLeftRoomCallbackContainer;
    OnRoomPropertiesUpdateCallbackContainer onRoomPropertiesUpdateCallbackContainer;
    OnPlayerPropertiesUpdateCallbackContainer onPlayerPropertiesUpdateCallbackContainer;
    OnMasterClientSwitchedCallbackContainer onMasterClientSwitchedCallbackContainer;
    
    void OnPlayerEnteredRoom(Player* newPlayer) { RUNCALLBACKS(onPlayerEnteredRoomCallbackContainer, newPlayer); }
    void OnPlayerLeftRoom(Player* otherPlayer) { RUNCALLBACKS(onPlayerLeftRoomCallbackContainer, otherPlayer); }
    void OnRoomPropertiesUpdate(Hashtable* propertiesThatChanged) { RUNCALLBACKS(onRoomPropertiesUpdateCallbackContainer, propertiesThatChanged); }
    void OnPlayerPropertiesUpdate(Player* targetPlayer, Hashtable* changedProp) { RUNCALLBACKS(onPlayerPropertiesUpdateCallbackContainer, targetPlayer, changedProp); }
    void OnMasterClientSwitched(Player* newMasterClient) { RUNCALLBACKS(onMasterClientSwitchedCallbackContainer, newMasterClient); }
    
    int add_OnPlayerEnteredRoom(OnPlayerEnteredRoomCallback callback) { return ADD(onPlayerEnteredRoomCallbackContainer); }
    int add_OnPlayerLeftRoom(OnPlayerLeftRoomCallback callback) { return ADD(onPlayerLeftRoomCallbackContainer); }
    int add_OnRoomPropertiesUpdate(OnRoomPropertiesUpdateCallback callback) { return ADD(onRoomPropertiesUpdateCallbackContainer); }
    int add_OnPlayerPropertiesUpdate(OnPlayerPropertiesUpdateCallback callback) { return ADD(onPlayerPropertiesUpdateCallbackContainer); }
    int add_OnMasterClientSwitched(OnMasterClientSwitchedCallback callback) { return ADD(onMasterClientSwitchedCallbackContainer); }

    void remove_OnPlayerEnteredRoom(int identifier) { REMOVE(onPlayerEnteredRoomCallbackContainer); }
    void remove_OnPlayerLeftRoom(int identifier) { REMOVE(onPlayerLeftRoomCallbackContainer); }
    void remove_OnRoomPropertiesUpdate(int identifier) { REMOVE(onRoomPropertiesUpdateCallbackContainer); }
    void remove_OnPlayerPropertiesUpdate(int identifier) { REMOVE(onPlayerPropertiesUpdateCallbackContainer); }
    void remove_OnMasterClientSwitched(int identifier) { REMOVE(onMasterClientSwitchedCallbackContainer); }

}