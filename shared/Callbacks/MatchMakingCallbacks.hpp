#pragma once

#include "beatsaber-hook/shared/utils/typedefs-wrappers.hpp"
#include <functional>
#include "Photon/Realtime/FriendInfo.hpp"

#include <string>

namespace GorillaUtils::MatchMakingCallbacks
{
    using FriendInfo = Photon::Realtime::FriendInfo;
    using FriendList = List<FriendInfo*>;

    typedef UnorderedEventCallback<> OnCreatedRoomEvent;
    typedef UnorderedEventCallback<> OnJoinedRoomEvent;
    typedef UnorderedEventCallback<short, std::string> OnCreateRoomFailedEvent;
    typedef UnorderedEventCallback<short, std::string> OnJoinRandomFailedEvent;
    typedef UnorderedEventCallback<short, std::string> OnJoinRoomFailedEvent;
    typedef UnorderedEventCallback<> OnLeftRoomEvent;
    typedef UnorderedEventCallback<FriendList*> OnFriendListUpdateEvent;

    OnCreatedRoomEvent& onCreatedRoomEvent();
    OnJoinedRoomEvent& onJoinedRoomEvent();
    OnCreateRoomFailedEvent& onCreateRoomFailedEvent();
    OnJoinRandomFailedEvent& onJoinRandomFailedEvent();
    OnJoinRoomFailedEvent& onJoinRoomFailedEvent();
    OnLeftRoomEvent& onLeftRoomEvent();
    OnFriendListUpdateEvent& onFriendListUpdateEvent();
}