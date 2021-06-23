#pragma once

#include <functional>
#include "Photon/Realtime/FriendInfo.hpp"

#include <string>

namespace GorillaUtils::MatchMakingCallbacks
{
    using FriendInfo = Photon::Realtime::FriendInfo;
    using FriendList = List<FriendInfo*>;

    typedef std::function<void(void)> OnCreatedRoomCallback;
    typedef std::function<void(void)> OnJoinedRoomCallback;
    typedef std::function<void(short, std::string)> OnCreateRoomFailedCallback;
    typedef std::function<void(short, std::string)> OnJoinRandomFailedCallback;
    typedef std::function<void(short, std::string)> OnJoinRoomFailedCallback;
    typedef std::function<void(void)> OnLeftRoomCallback;
    typedef std::function<void(FriendList*)> OnFriendListUpdateCallback;

    int add_OnCreatedRoom(OnCreatedRoomCallback callback);
    int add_OnJoinedRoom(OnJoinedRoomCallback callback);
    int add_OnCreateRoomFailed(OnCreateRoomFailedCallback callback);
    int add_OnJoinRandomFailed(OnJoinRandomFailedCallback callback);
    int add_OnJoinRoomFailed(OnJoinRoomFailedCallback callback);
    int add_OnLeftRoom(OnLeftRoomCallback callback);
    int add_OnFriendListUpdate(OnFriendListUpdateCallback callback);

    void remove_OnCreatedRoom(int identifier);
    void remove_OnJoinedRoom(int identifier);
    void remove_OnCreateRoomFailed(int identifier);
    void remove_OnJoinRandomFailed(int identifier);
    void remove_OnJoinRoomFailed(int identifier);
    void remove_OnLeftRoom(int identifier);
    void remove_OnFriendListUpdate(int identifier);
}