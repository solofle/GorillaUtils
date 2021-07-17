#pragma once

#include "beatsaber-hook/shared/utils/typedefs-wrappers.hpp"
#include <functional>

namespace Photon::Realtime {
    class Player;
}

namespace ExitGames::Client::Photon {
    class Hashtable;
}

namespace GorillaUtils::InRoomCallbacks
{
    using Player = Photon::Realtime::Player;
    using Hashtable = ExitGames::Client::Photon::Hashtable;

    typedef UnorderedEventCallback<Player*> OnPlayerEnteredRoomEvent;
    typedef UnorderedEventCallback<Player*> OnPlayerLeftRoomEvent;
    typedef UnorderedEventCallback<Hashtable*> OnRoomPropertiesUpdateEvent;
    typedef UnorderedEventCallback<Player*, Hashtable*> OnPlayerPropertiesUpdateEvent;
    typedef UnorderedEventCallback<Player*> OnMasterClientSwitchedEvent;

    OnPlayerEnteredRoomEvent& onPlayerEnteredRoomEvent();
    OnPlayerLeftRoomEvent& onPlayerLeftRoomEvent();
    OnRoomPropertiesUpdateEvent& onRoomPropertiesUpdateEvent();
    OnPlayerPropertiesUpdateEvent& onPlayerPropertiesUpdateEvent();
    OnMasterClientSwitchedEvent& onMasterClientSwitchedEvent();
}