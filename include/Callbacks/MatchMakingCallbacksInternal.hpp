#pragma once

#include "CallbackContainer.hpp"
#include "Callbacks/MatchMakingCallbacks.hpp"

struct Il2CppString;

namespace GorillaUtils::MatchMakingCallbacks
{
    typedef CallbackContainer<OnCreatedRoomCallback> OnCreatedRoomCallbackContainer;
    typedef CallbackContainer<OnJoinedRoomCallback> OnJoinedRoomCallbackContainer;
    typedef CallbackContainer<OnCreateRoomFailedCallback> OnCreateRoomFailedCallbackContainer;
    typedef CallbackContainer<OnJoinRandomFailedCallback> OnJoinRandomFailedCallbackContainer;
    typedef CallbackContainer<OnJoinRoomFailedCallback> OnJoinRoomFailedCallbackContainer;
    typedef CallbackContainer<OnLeftRoomCallback> OnLeftRoomCallbackContainer;
    typedef CallbackContainer<OnFriendListUpdateCallback> OnFriendListUpdateCallbackContainer;

    void OnCreatedRoom();
    void OnJoinedRoom();
    void OnCreateRoomFailed(short returnCode, Il2CppString* message);
    void OnJoinRandomFailed(short returnCode, Il2CppString* message);
    void OnJoinRoomFailed(short returnCode, Il2CppString* message);
    void OnLeftRoom();
    void OnFriendListUpdate(FriendList* friendList);
}