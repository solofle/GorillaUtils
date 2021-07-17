#pragma once

#include "CallbackContainer.hpp"
#include "Callbacks/ConnectionCallbacks.hpp"

namespace GorillaUtils::ConnectionCallbacks
{
    void OnConnected();
    void OnConnectedToMaster();
    void OnRegionListReceived(RegionHandler* regionHandler);
    void OnDisconnected(DisconnectCause& cause);
    void OnCustomAuthenticationResponse(AuthResult* data);
    void OnCustomAuthenticationFailed(std::string debugMessage);
}