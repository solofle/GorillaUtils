#pragma once

#include <functional>

#include "Photon/Realtime/DisconnectCause.hpp"

namespace Photon::Realtime {
    class RegionHandler;
}

namespace System::Collections::Generic {
    template<class U, class T>
    class Dictionary_2;
}

struct Il2CppString;
struct Il2CppObject;

namespace GorillaUtils::ConnectionCallbacks
{
    using RegionHandler = Photon::Realtime::RegionHandler;
    using DisconnectCause = Photon::Realtime::DisconnectCause;
    using AuthResult = System::Collections::Generic::Dictionary_2<Il2CppString*, Il2CppObject*>;

    typedef std::function<void(void)> OnConnectedCallback;
    typedef std::function<void(void)> OnConnectedToMasterCallback;
    typedef std::function<void(RegionHandler*)> OnRegionListReceivedCallback;
    typedef std::function<void(DisconnectCause&)> OnDisconnectedCallback;
    typedef std::function<void(AuthResult*)> OnCustomAuthenticationResponseCallback;
    typedef std::function<void(Il2CppString*)> OnCustomAuthenticationFailedCallback;

    int add_OnConnected(OnConnectedCallback callback);
    int add_OnConnectedToMaster(OnConnectedToMasterCallback callback);
    int add_OnRegionListReceived(OnRegionListReceivedCallback callback);
    int add_OnDisconnected(OnDisconnectedCallback callback);
    int add_OnCustomAuthenticationResponse(OnCustomAuthenticationResponseCallback callback);
    int add_OnCustomAuthenticationFailed(OnCustomAuthenticationFailedCallback callback);

    void remove_OnConnected(int identifier);
    void remove_OnConnectedToMaster(int identifier);
    void remove_OnRegionListReceived(int identifier);
    void remove_OnDisconnected(int identifier);
    void remove_OnCustomAuthenticationResponse(int identifier);
    void remove_OnCustomAuthenticationFailed(int identifier);
}