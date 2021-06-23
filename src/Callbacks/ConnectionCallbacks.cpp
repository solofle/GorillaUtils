#include "Callbacks/ConnectionCallbacksInternal.hpp"
#include "Callbacks/ConnectionCallbacks.hpp"
#include "CallbackUtils.hpp"

using RegionHandler = Photon::Realtime::RegionHandler;
using DisconnectCause = Photon::Realtime::DisconnectCause;
using AuthResult = System::Collections::Generic::Dictionary_2<Il2CppString*, Il2CppObject*>;

namespace GorillaUtils::ConnectionCallbacks
{
    OnConnectedCallbackContainer onConnectedCallbackContainer;
    OnConnectedToMasterCallbackContainer onConnectedToMasterCallbackContainer;
    OnRegionListReceivedCallbackContainer onRegionListReceivedCallbackContainer;
    OnDisconnectedCallbackContainer onDisconnectedCallbackContainer;
    OnCustomAuthenticationResponseCallbackContainer onCustomAuthenticationResponseCallbackContainer;
    OnCustomAuthenticationFailedCallbackContainer onCustomAuthenticationFailedCallbackContainer;

    void OnConnected() { RUNCALLBACKS(onConnectedCallbackContainer); }
    void OnConnectedToMaster() { RUNCALLBACKS(onConnectedToMasterCallbackContainer); }
    void OnRegionListReceived(RegionHandler* regionHandler) { RUNCALLBACKS(onRegionListReceivedCallbackContainer, regionHandler); }
    void OnDisconnected(DisconnectCause& cause) { RUNCALLBACKS(onDisconnectedCallbackContainer, cause); }
    void OnCustomAuthenticationResponse(AuthResult* data) { RUNCALLBACKS(onCustomAuthenticationResponseCallbackContainer, data); }
    void OnCustomAuthenticationFailed(Il2CppString* debugMessage) { RUNCALLBACKS(onCustomAuthenticationFailedCallbackContainer, debugMessage); }

    int add_OnConnected(OnConnectedCallback callback) { return ADD(onConnectedCallbackContainer); }
    int add_OnConnectedToMaster(OnConnectedToMasterCallback callback) { return ADD(onConnectedToMasterCallbackContainer); }
    int add_OnRegionListReceived(OnRegionListReceivedCallback callback) { return ADD(onRegionListReceivedCallbackContainer); }
    int add_OnDisconnected(OnDisconnectedCallback callback) { return ADD(onDisconnectedCallbackContainer); }
    int add_OnCustomAuthenticationResponse(OnCustomAuthenticationResponseCallback callback) { return ADD(onCustomAuthenticationResponseCallbackContainer); }
    int add_OnCustomAuthenticationFailed(OnCustomAuthenticationFailedCallback callback) { return ADD(onCustomAuthenticationFailedCallbackContainer); }

    void remove_OnConnected(int identifier) { REMOVE(onConnectedCallbackContainer); }
    void remove_OnConnectedToMaster(int identifier) { REMOVE(onConnectedToMasterCallbackContainer); }
    void remove_OnRegionListReceived(int identifier) { REMOVE(onRegionListReceivedCallbackContainer); }
    void remove_OnDisconnected(int identifier) { REMOVE(onDisconnectedCallbackContainer); }
    void remove_OnCustomAuthenticationResponse(int identifier) { REMOVE(onCustomAuthenticationResponseCallbackContainer); }
    void remove_OnCustomAuthenticationFailed(int identifier) { REMOVE(onCustomAuthenticationFailedCallbackContainer); }
}