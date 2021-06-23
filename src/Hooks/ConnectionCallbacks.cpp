#include "beatsaber-hook/shared/utils/utils.h"
#include "beatsaber-hook/shared/utils/il2cpp-utils.hpp"

#include "modloader/shared/modloader.hpp"

#include "Callbacks/ConnectionCallbacksInternal.hpp"

namespace Photon::Realtime {
    class ConnectionCallbacksContainer;
}

using ConnectionCallbacksContainer = Photon::Realtime::ConnectionCallbacksContainer;

using RegionHandler = Photon::Realtime::RegionHandler;
using DisconnectCause = Photon::Realtime::DisconnectCause;
using AuthResult = System::Collections::Generic::Dictionary_2<Il2CppString*, Il2CppObject*>;

using namespace GorillaUtils;

// ConnectionCallbacksContianer hooks
MAKE_HOOK_OFFSETLESS(ConnectionCallbacksContainer_OnConnected, void, ConnectionCallbacksContainer* self)
{
    ConnectionCallbacksContainer_OnConnected(self);
    ConnectionCallbacks::OnConnected();
}

MAKE_HOOK_OFFSETLESS(ConnectionCallbacksContainer_OnConnectedToMaster, void, ConnectionCallbacksContainer* self)
{
    ConnectionCallbacksContainer_OnConnectedToMaster(self);
    ConnectionCallbacks::OnConnectedToMaster();
}

MAKE_HOOK_OFFSETLESS(ConnectionCallbacksContainer_OnRegionListReceived, void, ConnectionCallbacksContainer* self, RegionHandler* regionHandler)
{
    ConnectionCallbacksContainer_OnRegionListReceived(self, regionHandler);
    ConnectionCallbacks::OnRegionListReceived(regionHandler);
}

MAKE_HOOK_OFFSETLESS(ConnectionCallbacksContainer_OnDisconnected, void, ConnectionCallbacksContainer* self, DisconnectCause cause)
{
    ConnectionCallbacksContainer_OnDisconnected(self, cause);
    ConnectionCallbacks::OnDisconnected(cause);
}

MAKE_HOOK_OFFSETLESS(ConnectionCallbacksContainer_OnCustomAuthenticationResponse, void, ConnectionCallbacksContainer* self, AuthResult* data)
{
    ConnectionCallbacksContainer_OnCustomAuthenticationResponse(self, data);
    ConnectionCallbacks::OnCustomAuthenticationResponse(data);
}

MAKE_HOOK_OFFSETLESS(ConnectionCallbacksContainer_OnCustomAuthenticationFailed, void, ConnectionCallbacksContainer* self, Il2CppString* debugMessage)
{
    ConnectionCallbacksContainer_OnCustomAuthenticationFailed(self, debugMessage);
    ConnectionCallbacks::OnCustomAuthenticationFailed(debugMessage);
}

void installConnectionCallbackHooks(Logger& logger)
{
    INSTALL_HOOK_OFFSETLESS(logger, ConnectionCallbacksContainer_OnConnected, il2cpp_utils::FindMethodUnsafe("Photon.Realtime", "ConnectionCallbacksContainer", "OnConnected", 0));
    INSTALL_HOOK_OFFSETLESS(logger, ConnectionCallbacksContainer_OnConnectedToMaster, il2cpp_utils::FindMethodUnsafe("Photon.Realtime", "ConnectionCallbacksContainer", "OnConnectedToMaster", 0));
    INSTALL_HOOK_OFFSETLESS(logger, ConnectionCallbacksContainer_OnRegionListReceived, il2cpp_utils::FindMethodUnsafe("Photon.Realtime", "ConnectionCallbacksContainer", "OnRegionListReceived", 1));
    INSTALL_HOOK_OFFSETLESS(logger, ConnectionCallbacksContainer_OnDisconnected, il2cpp_utils::FindMethodUnsafe("Photon.Realtime", "ConnectionCallbacksContainer", "OnDisconnected", 1));
    INSTALL_HOOK_OFFSETLESS(logger, ConnectionCallbacksContainer_OnCustomAuthenticationResponse, il2cpp_utils::FindMethodUnsafe("Photon.Realtime", "ConnectionCallbacksContainer", "OnCustomAuthenticationResponse", 1));
    INSTALL_HOOK_OFFSETLESS(logger, ConnectionCallbacksContainer_OnCustomAuthenticationFailed, il2cpp_utils::FindMethodUnsafe("Photon.Realtime", "ConnectionCallbacksContainer", "OnCustomAuthenticationFailed", 1));
}