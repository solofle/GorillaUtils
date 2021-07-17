#include "Callbacks/ConnectionCallbacksInternal.hpp"
#include "Callbacks/ConnectionCallbacks.hpp"
#include "CallbackUtils.hpp"

using RegionHandler = Photon::Realtime::RegionHandler;
using DisconnectCause = Photon::Realtime::DisconnectCause;
using AuthResult = System::Collections::Generic::Dictionary_2<Il2CppString*, Il2CppObject*>;

namespace GorillaUtils::ConnectionCallbacks
{
    EVENT(OnConnectedEvent, onConnectedEvent);
    EVENT(OnConnectedToMasterEvent, onConnectedToMasterEvent);
    EVENT(OnRegionListReceivedEvent, onRegionListReceivedEvent);
    EVENT(OnDisconnectedEvent, onDisconnectedEvent);
    EVENT(OnCustomAuthenticationResponseEvent, onCustomAuthenticationResponseEvent);
    EVENT(OnCustomAuthenticationFailedEvent, onCustomAuthenticationFailedEvent);

    void OnConnected() { RUNCALLBACKS(OnConnectedEvent); }
    void OnConnectedToMaster() { RUNCALLBACKS(OnConnectedToMasterEvent); }
    void OnRegionListReceived(RegionHandler* regionHandler) { RUNCALLBACKS(OnRegionListReceivedEvent, regionHandler); }
    void OnDisconnected(DisconnectCause& cause) { RUNCALLBACKS(OnDisconnectedEvent, cause); }
    void OnCustomAuthenticationResponse(AuthResult* data) { RUNCALLBACKS(OnCustomAuthenticationResponseEvent, data); }
    void OnCustomAuthenticationFailed(std::string debugMessage) { RUNCALLBACKS(OnCustomAuthenticationFailedEvent, debugMessage); }
}