#include "beatsaber-hook/shared/utils/hooking.hpp"
#include "beatsaber-hook/shared/utils/utils.h"
#include "beatsaber-hook/shared/utils/il2cpp-utils.hpp"

#include "GorillaUtilsInternal.hpp"
#include "modloader/shared/modloader.hpp"

#include "Callbacks/MatchMakingCallbacksInternal.hpp"
#include "Photon/Realtime/MatchMakingCallbacksContainer.hpp"
#include "Photon/Realtime/FriendInfo.hpp"

using MatchMakingCallbacksContainer = Photon::Realtime::MatchMakingCallbacksContainer;

using FriendInfo = Photon::Realtime::FriendInfo;
using FriendList = List<FriendInfo*>;

using namespace GorillaUtils;

// MatchMakingCallbacksContianer hooks
MAKE_HOOK_MATCH(MatchMakingCallbacksContainer_OnCreatedRoom, &MatchMakingCallbacksContainer::OnCreatedRoom, void, MatchMakingCallbacksContainer* self)
{
    MatchMakingCallbacksContainer_OnCreatedRoom(self);
    MatchMakingCallbacks::OnCreatedRoom();
}

MAKE_HOOK_MATCH(MatchMakingCallbacksContainer_OnJoinedRoom, &MatchMakingCallbacksContainer::OnJoinedRoom, void, MatchMakingCallbacksContainer* self)
{
    MatchMakingCallbacksContainer_OnJoinedRoom(self);
    GorillaUtils::OnJoinedRoom();
    MatchMakingCallbacks::OnJoinedRoom();
}

MAKE_HOOK_MATCH(MatchMakingCallbacksContainer_OnCreateRoomFailed, &MatchMakingCallbacksContainer::OnCreateRoomFailed, void, MatchMakingCallbacksContainer* self, short returnCode, Il2CppString* message)
{
    MatchMakingCallbacksContainer_OnCreateRoomFailed(self, returnCode, message);
    MatchMakingCallbacks::OnCreateRoomFailed(returnCode, message);
}

MAKE_HOOK_MATCH(MatchMakingCallbacksContainer_OnJoinRandomFailed, &MatchMakingCallbacksContainer::OnJoinRandomFailed, void, MatchMakingCallbacksContainer* self, short returnCode, Il2CppString* message)
{
    MatchMakingCallbacksContainer_OnJoinRandomFailed(self, returnCode, message);
    MatchMakingCallbacks::OnJoinRandomFailed(returnCode, message);
}

MAKE_HOOK_MATCH(MatchMakingCallbacksContainer_OnJoinRoomFailed, &MatchMakingCallbacksContainer::OnJoinRoomFailed, void, MatchMakingCallbacksContainer* self, short returnCode, Il2CppString* message)
{
    MatchMakingCallbacksContainer_OnJoinRoomFailed(self, returnCode, message);
    MatchMakingCallbacks::OnJoinRoomFailed(returnCode, message);
}

MAKE_HOOK_MATCH(MatchMakingCallbacksContainer_OnLeftRoom, &MatchMakingCallbacksContainer::OnLeftRoom, void, MatchMakingCallbacksContainer* self)
{
    MatchMakingCallbacksContainer_OnLeftRoom(self);
    GorillaUtils::OnLeftRoom();
    MatchMakingCallbacks::OnLeftRoom();
}

MAKE_HOOK_MATCH(MatchMakingCallbacksContainer_OnFriendListUpdate, &MatchMakingCallbacksContainer::OnFriendListUpdate, void, MatchMakingCallbacksContainer* self, FriendList* friendList)
{
    MatchMakingCallbacksContainer_OnFriendListUpdate(self, friendList);
    MatchMakingCallbacks::OnFriendListUpdate(friendList);
}

void installMatchMakingCallbackHooks(Logger& logger)
{
    INSTALL_HOOK(logger, MatchMakingCallbacksContainer_OnCreatedRoom);
    INSTALL_HOOK(logger, MatchMakingCallbacksContainer_OnJoinedRoom);
    INSTALL_HOOK(logger, MatchMakingCallbacksContainer_OnCreateRoomFailed);
    INSTALL_HOOK(logger, MatchMakingCallbacksContainer_OnJoinRandomFailed);
    INSTALL_HOOK(logger, MatchMakingCallbacksContainer_OnJoinRoomFailed);
    INSTALL_HOOK(logger, MatchMakingCallbacksContainer_OnLeftRoom);
    INSTALL_HOOK(logger, MatchMakingCallbacksContainer_OnFriendListUpdate);
}