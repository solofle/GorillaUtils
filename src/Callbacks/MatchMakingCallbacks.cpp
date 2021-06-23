#include "Callbacks/MatchMakingCallbacksInternal.hpp"
#include "Callbacks/MatchMakingCallbacks.hpp"
#include "CallbackUtils.hpp"
#include "beatsaber-hook/shared/utils/il2cpp-utils.hpp"

using FriendInfo = Photon::Realtime::FriendInfo;
using FriendList = List<FriendInfo*>;

namespace GorillaUtils::MatchMakingCallbacks 
{
    OnCreatedRoomCallbackContainer onCreatedRoomCallbackContainer;
    OnJoinedRoomCallbackContainer onJoinedRoomCallbackContainer;
    OnCreateRoomFailedCallbackContainer onCreateRoomFailedCallbackContainer;
    OnJoinRandomFailedCallbackContainer onJoinRandomFailedCallbackContainer;
    OnJoinRoomFailedCallbackContainer onJoinRoomFailedCallbackContainer;
    OnLeftRoomCallbackContainer onLeftRoomCallbackContainer;
    OnFriendListUpdateCallbackContainer onFriendListUpdateCallbackContainer;

    void OnCreatedRoom() { RUNCALLBACKS(onCreatedRoomCallbackContainer); }
    void OnJoinedRoom() { RUNCALLBACKS(onJoinedRoomCallbackContainer); }
    void OnCreateRoomFailed(short returnCode, Il2CppString* message) { RUNCALLBACKS(onCreateRoomFailedCallbackContainer, returnCode, TO_CPP_STRING(message)); }
    void OnJoinRandomFailed(short returnCode, Il2CppString* message) { RUNCALLBACKS(onJoinRandomFailedCallbackContainer, returnCode, TO_CPP_STRING(message)); }
    void OnJoinRoomFailed(short returnCode, Il2CppString* message) { RUNCALLBACKS(onJoinRoomFailedCallbackContainer, returnCode, TO_CPP_STRING(message)); }
    void OnLeftRoom() { RUNCALLBACKS(onLeftRoomCallbackContainer); }
    void OnFriendListUpdate(FriendList* friendList) { RUNCALLBACKS(onFriendListUpdateCallbackContainer, friendList); }

    int add_OnCreatedRoom(OnCreatedRoomCallback callback) { return ADD(onCreatedRoomCallbackContainer); }
    int add_OnJoinedRoom(OnJoinedRoomCallback callback) { return ADD(onJoinedRoomCallbackContainer); }
    int add_OnCreateRoomFailed(OnCreateRoomFailedCallback callback) { return ADD(onCreateRoomFailedCallbackContainer); }
    int add_OnJoinRandomFailed(OnJoinRandomFailedCallback callback) { return ADD(onJoinRandomFailedCallbackContainer); }
    int add_OnJoinRoomFailed(OnJoinRoomFailedCallback callback) { return ADD(onJoinRoomFailedCallbackContainer); }
    int add_OnLeftRoom(OnLeftRoomCallback callback) { return ADD(onLeftRoomCallbackContainer); }
    int add_OnFriendListUpdate(OnFriendListUpdateCallback callback) { return ADD(onFriendListUpdateCallbackContainer); }

    void remove_OnCreatedRoom(int identifier) { REMOVE(onCreatedRoomCallbackContainer); } 
    void remove_OnJoinedRoom(int identifier) { REMOVE(onJoinedRoomCallbackContainer); } 
    void remove_OnCreateRoomFailed(int identifier) { REMOVE(onCreateRoomFailedCallbackContainer); } 
    void remove_OnJoinRandomFailed(int identifier) { REMOVE(onJoinRandomFailedCallbackContainer); } 
    void remove_OnJoinRoomFailed(int identifier) { REMOVE(onJoinRoomFailedCallbackContainer); } 
    void remove_OnLeftRoom(int identifier) { REMOVE(onLeftRoomCallbackContainer); } 
    void remove_OnFriendListUpdate(int identifier) { REMOVE(onFriendListUpdateCallbackContainer); } 

}