#include "beatsaber-hook/shared/utils/utils.h"
#include "beatsaber-hook/shared/utils/il2cpp-utils.hpp"

#include "GorillaUtilsInternal.hpp"
#include "modloader/shared/modloader.hpp"

#include "Callbacks/MatchMakingCallbacksInternal.hpp"

namespace Photon::Realtime {
    class MatchMakingCallbacksContainer;
}

using MatchMakingCallbacksContainer = Photon::Realtime::MatchMakingCallbacksContainer;

using FriendInfo = Photon::Realtime::FriendInfo;
using FriendList = List<FriendInfo*>;

using namespace GorillaUtils;

// MatchMakingCallbacksContianer hooks
MAKE_HOOK_OFFSETLESS(MatchMakingCallbacksContainer_OnCreatedRoom, void, MatchMakingCallbacksContainer* self)
{
    MatchMakingCallbacksContainer_OnCreatedRoom(self);
    MatchMakingCallbacks::OnCreatedRoom();
}

MAKE_HOOK_OFFSETLESS(MatchMakingCallbacksContainer_OnJoinedRoom, void, MatchMakingCallbacksContainer* self)
{
    MatchMakingCallbacksContainer_OnJoinedRoom(self);
    GorillaUtils::OnJoinedRoom();
    MatchMakingCallbacks::OnJoinedRoom();
}

MAKE_HOOK_OFFSETLESS(MatchMakingCallbacksContainer_OnCreateRoomFailed, void, MatchMakingCallbacksContainer* self, short returnCode, Il2CppString* message)
{
    MatchMakingCallbacksContainer_OnCreateRoomFailed(self, returnCode, message);
    MatchMakingCallbacks::OnCreateRoomFailed(returnCode, message);
}

MAKE_HOOK_OFFSETLESS(MatchMakingCallbacksContainer_OnJoinRandomFailed, void, MatchMakingCallbacksContainer* self, short returnCode, Il2CppString* message)
{
    MatchMakingCallbacksContainer_OnJoinRandomFailed(self, returnCode, message);
    MatchMakingCallbacks::OnJoinRandomFailed(returnCode, message);
}

MAKE_HOOK_OFFSETLESS(MatchMakingCallbacksContainer_OnJoinRoomFailed, void, MatchMakingCallbacksContainer* self, short returnCode, Il2CppString* message)
{
    MatchMakingCallbacksContainer_OnJoinRoomFailed(self, returnCode, message);
    MatchMakingCallbacks::OnJoinRoomFailed(returnCode, message);
}

MAKE_HOOK_OFFSETLESS(MatchMakingCallbacksContainer_OnLeftRoom, void, MatchMakingCallbacksContainer* self)
{
    MatchMakingCallbacksContainer_OnLeftRoom(self);
    GorillaUtils::OnLeftRoom();
    MatchMakingCallbacks::OnLeftRoom();
}

MAKE_HOOK_OFFSETLESS(MatchMakingCallbacksContainer_OnFriendListUpdate, void, MatchMakingCallbacksContainer* self, FriendList* friendList)
{
    MatchMakingCallbacksContainer_OnFriendListUpdate(self, friendList);
    MatchMakingCallbacks::OnFriendListUpdate(friendList);
}

void installMatchMakingCallbackHooks(Logger& logger)
{
    INSTALL_HOOK_OFFSETLESS(logger, MatchMakingCallbacksContainer_OnCreatedRoom, il2cpp_utils::FindMethodUnsafe("Photon.Realtime", "MatchMakingCallbacksContainer", "OnCreatedRoom", 0));
    INSTALL_HOOK_OFFSETLESS(logger, MatchMakingCallbacksContainer_OnJoinedRoom, il2cpp_utils::FindMethodUnsafe("Photon.Realtime", "MatchMakingCallbacksContainer", "OnJoinedRoom", 0));
    INSTALL_HOOK_OFFSETLESS(logger, MatchMakingCallbacksContainer_OnCreateRoomFailed, il2cpp_utils::FindMethodUnsafe("Photon.Realtime", "MatchMakingCallbacksContainer", "OnCreateRoomFailed", 2));
    INSTALL_HOOK_OFFSETLESS(logger, MatchMakingCallbacksContainer_OnJoinRandomFailed, il2cpp_utils::FindMethodUnsafe("Photon.Realtime", "MatchMakingCallbacksContainer", "OnJoinRandomFailed", 2));
    INSTALL_HOOK_OFFSETLESS(logger, MatchMakingCallbacksContainer_OnJoinRoomFailed, il2cpp_utils::FindMethodUnsafe("Photon.Realtime", "MatchMakingCallbacksContainer", "OnJoinRoomFailed", 2));
    INSTALL_HOOK_OFFSETLESS(logger, MatchMakingCallbacksContainer_OnLeftRoom, il2cpp_utils::FindMethodUnsafe("Photon.Realtime", "MatchMakingCallbacksContainer", "OnLeftRoom", 0));
    INSTALL_HOOK_OFFSETLESS(logger, MatchMakingCallbacksContainer_OnFriendListUpdate, il2cpp_utils::FindMethodUnsafe("Photon.Realtime", "MatchMakingCallbacksContainer", "OnFriendListUpdate", 1));
}