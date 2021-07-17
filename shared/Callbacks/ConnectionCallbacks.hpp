#pragma once

#include "beatsaber-hook/shared/utils/typedefs-wrappers.hpp"

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

    typedef UnorderedEventCallback<> OnConnectedEvent;
    typedef UnorderedEventCallback<> OnConnectedToMasterEvent;
    typedef UnorderedEventCallback<RegionHandler*> OnRegionListReceivedEvent;
    typedef UnorderedEventCallback<DisconnectCause&> OnDisconnectedEvent;
    typedef UnorderedEventCallback<AuthResult*> OnCustomAuthenticationResponseEvent;
    typedef UnorderedEventCallback<std::string> OnCustomAuthenticationFailedEvent;

    OnConnectedEvent& onConnectedEvent();
    OnConnectedToMasterEvent& onConnectedToMasterEvent();
    OnRegionListReceivedEvent& onRegionListReceivedEvent();
    OnDisconnectedEvent& onDisconnectedEvent();
    OnCustomAuthenticationResponseEvent& onCustomAuthenticationResponseEvent();
    OnCustomAuthenticationFailedEvent& onCustomAuthenticationFailedEvent();
}