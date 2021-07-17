#include "Callbacks/InRoomCallbacksInternal.hpp"
#include "Callbacks/InRoomCallbacks.hpp"
#include "CallbackUtils.hpp"

namespace GorillaUtils::InRoomCallbacks
{
    EVENT(OnPlayerEnteredRoomEvent, onPlayerEnteredRoomEvent);
    EVENT(OnPlayerLeftRoomEvent, onPlayerLeftRoomEvent);
    EVENT(OnRoomPropertiesUpdateEvent, onRoomPropertiesUpdateEvent);
    EVENT(OnPlayerPropertiesUpdateEvent, onPlayerPropertiesUpdateEvent);
    EVENT(OnMasterClientSwitchedEvent, onMasterClientSwitchedEvent);

    void OnPlayerEnteredRoom(Player* newPlayer) { RUNCALLBACKS(OnPlayerEnteredRoomEvent, newPlayer); }
    void OnPlayerLeftRoom(Player* otherPlayer) { RUNCALLBACKS(OnPlayerLeftRoomEvent, otherPlayer); }
    void OnRoomPropertiesUpdate(Hashtable* propertiesThatChanged) { RUNCALLBACKS(OnRoomPropertiesUpdateEvent, propertiesThatChanged); }
    void OnPlayerPropertiesUpdate(Player* targetPlayer, Hashtable* changedProp) { RUNCALLBACKS(OnPlayerPropertiesUpdateEvent, targetPlayer, changedProp); }
    void OnMasterClientSwitched(Player* newMasterClient) { RUNCALLBACKS(OnMasterClientSwitchedEvent, newMasterClient); }
}