#pragma once

#include "CallbackContainer.hpp"
#include "Callbacks/ConnectionCallbacks.hpp"

namespace GorillaUtils::ConnectionCallbacks
{
    typedef CallbackContainer<OnConnectedCallback> OnConnectedCallbackContainer;
    typedef CallbackContainer<OnConnectedToMasterCallback> OnConnectedToMasterCallbackContainer;
    typedef CallbackContainer<OnRegionListReceivedCallback> OnRegionListReceivedCallbackContainer;
    typedef CallbackContainer<OnDisconnectedCallback> OnDisconnectedCallbackContainer;
    typedef CallbackContainer<OnCustomAuthenticationResponseCallback> OnCustomAuthenticationResponseCallbackContainer;
    typedef CallbackContainer<OnCustomAuthenticationFailedCallback> OnCustomAuthenticationFailedCallbackContainer;
    
    void OnConnected();
    void OnConnectedToMaster();
    void OnRegionListReceived(RegionHandler* regionHandler);
    void OnDisconnected(DisconnectCause& cause);
    void OnCustomAuthenticationResponse(AuthResult* data);
    void OnCustomAuthenticationFailed(Il2CppString* debugMessage);
}