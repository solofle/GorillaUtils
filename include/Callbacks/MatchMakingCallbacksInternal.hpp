#pragma once

#include "CallbackContainer.hpp"
#include "Callbacks/MatchMakingCallbacks.hpp"

struct Il2CppString;

namespace GorillaUtils::MatchMakingCallbacks
{
    void OnCreatedRoom();
    void OnJoinedRoom();
    void OnCreateRoomFailed(short returnCode, Il2CppString* message);
    void OnJoinRandomFailed(short returnCode, Il2CppString* message);
    void OnJoinRoomFailed(short returnCode, Il2CppString* message);
    void OnLeftRoom();
    void OnFriendListUpdate(FriendList* friendList);
}