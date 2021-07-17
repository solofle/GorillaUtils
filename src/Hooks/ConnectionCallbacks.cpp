#include "beatsaber-hook/shared/utils/utils.h"
#include "beatsaber-hook/shared/utils/il2cpp-utils.hpp"
#include "beatsaber-hook/shared/utils/hooking.hpp"

#include "modloader/shared/modloader.hpp"

#include "Callbacks/ConnectionCallbacksInternal.hpp"

#include "System/Collections/Generic/Dictionary_2.hpp"
#include "Photon/Realtime/ConnectionCallbacksContainer.hpp"
#include "Photon/Realtime/RegionHandler.hpp"
#include "Photon/Realtime/DisconnectCause.hpp"

using ConnectionCallbacksContainer = Photon::Realtime::ConnectionCallbacksContainer;

using RegionHandler = Photon::Realtime::RegionHandler;
using DisconnectCause = Photon::Realtime::DisconnectCause;
using AuthResult = System::Collections::Generic::Dictionary_2<Il2CppString*, Il2CppObject*>;

// ConnectionCallbacksContianer hooks
MAKE_HOOK_MATCH(ConnectionCallbacksContainer_OnConnected, &ConnectionCallbacksContainer::OnConnected, void, ConnectionCallbacksContainer* self)
{
    ConnectionCallbacksContainer_OnConnected(self);
    GorillaUtils::ConnectionCallbacks::OnConnected();
}

MAKE_HOOK_MATCH(ConnectionCallbacksContainer_OnConnectedToMaster, &ConnectionCallbacksContainer::OnConnectedToMaster, void, ConnectionCallbacksContainer* self)
{
    ConnectionCallbacksContainer_OnConnectedToMaster(self);
    GorillaUtils::ConnectionCallbacks::OnConnectedToMaster();
}

MAKE_HOOK_MATCH(ConnectionCallbacksContainer_OnRegionListReceived, &ConnectionCallbacksContainer::OnRegionListReceived, void, ConnectionCallbacksContainer* self, RegionHandler* regionHandler)
{
    ConnectionCallbacksContainer_OnRegionListReceived(self, regionHandler);
    GorillaUtils::ConnectionCallbacks::OnRegionListReceived(regionHandler);
}

MAKE_HOOK_MATCH(ConnectionCallbacksContainer_OnDisconnected, &ConnectionCallbacksContainer::OnDisconnected, void, ConnectionCallbacksContainer* self, DisconnectCause cause)
{
    ConnectionCallbacksContainer_OnDisconnected(self, cause);
    GorillaUtils::ConnectionCallbacks::OnDisconnected(cause);
}

MAKE_HOOK_MATCH(ConnectionCallbacksContainer_OnCustomAuthenticationResponse, &ConnectionCallbacksContainer::OnCustomAuthenticationResponse, void, ConnectionCallbacksContainer* self, AuthResult* data)
{
    ConnectionCallbacksContainer_OnCustomAuthenticationResponse(self, data);
    GorillaUtils::ConnectionCallbacks::OnCustomAuthenticationResponse(data);
}

MAKE_HOOK_MATCH(ConnectionCallbacksContainer_OnCustomAuthenticationFailed, &ConnectionCallbacksContainer::OnCustomAuthenticationFailed, void, ConnectionCallbacksContainer* self, Il2CppString* debugMessage)
{
    ConnectionCallbacksContainer_OnCustomAuthenticationFailed(self, debugMessage);
    GorillaUtils::ConnectionCallbacks::OnCustomAuthenticationFailed(debugMessage);
}

void installConnectionCallbackHooks(Logger& logger)
{
    INSTALL_HOOK(logger, ConnectionCallbacksContainer_OnConnected);
    INSTALL_HOOK(logger, ConnectionCallbacksContainer_OnConnectedToMaster);
    INSTALL_HOOK(logger, ConnectionCallbacksContainer_OnRegionListReceived);
    INSTALL_HOOK(logger, ConnectionCallbacksContainer_OnDisconnected);
    INSTALL_HOOK(logger, ConnectionCallbacksContainer_OnCustomAuthenticationResponse);
    INSTALL_HOOK(logger, ConnectionCallbacksContainer_OnCustomAuthenticationFailed);
}