#include "Callbacks/MatchMakingCallbacksInternal.hpp"
#include "Callbacks/MatchMakingCallbacks.hpp"
#include "CallbackUtils.hpp"
#include "beatsaber-hook/shared/utils/il2cpp-utils.hpp"

using FriendInfo = Photon::Realtime::FriendInfo;
using FriendList = List<FriendInfo*>;

namespace GorillaUtils::MatchMakingCallbacks 
{
    EVENT(OnCreatedRoomEvent, onCreatedRoomEvent);
    EVENT(OnJoinedRoomEvent, onJoinedRoomEvent);
    EVENT(OnCreateRoomFailedEvent, onCreateRoomFailedEvent);
    EVENT(OnJoinRandomFailedEvent, onJoinRandomFailedEvent);
    EVENT(OnJoinRoomFailedEvent, onJoinRoomFailedEvent);
    EVENT(OnLeftRoomEvent, onLeftRoomEvent);
    EVENT(OnFriendListUpdateEvent, onFriendListUpdateEvent);
    
    void OnCreatedRoom() { RUNCALLBACKS(OnCreatedRoomEvent); }
    void OnJoinedRoom() { RUNCALLBACKS(OnJoinedRoomEvent); }
    void OnCreateRoomFailed(short returnCode, Il2CppString* message) { RUNCALLBACKS(OnCreateRoomFailedEvent, returnCode, TO_CPP_STRING(message)); }
    void OnJoinRandomFailed(short returnCode, Il2CppString* message) { RUNCALLBACKS(OnJoinRandomFailedEvent, returnCode, TO_CPP_STRING(message)); }
    void OnJoinRoomFailed(short returnCode, Il2CppString* message) { RUNCALLBACKS(OnJoinRoomFailedEvent, returnCode, TO_CPP_STRING(message)); }
    void OnLeftRoom() { RUNCALLBACKS(OnLeftRoomEvent); }
    void OnFriendListUpdate(FriendList* friendList) { RUNCALLBACKS(OnFriendListUpdateEvent, friendList); }
}