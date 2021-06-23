#pragma once

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

    typedef std::function<void(Player*)> OnPlayerEnteredRoomCallback;
    typedef std::function<void(Player*)> OnPlayerLeftRoomCallback;
    typedef std::function<void(Hashtable*)> OnRoomPropertiesUpdateCallback;
    typedef std::function<void(Player*, Hashtable*)> OnPlayerPropertiesUpdateCallback;
    typedef std::function<void(Player*)> OnMasterClientSwitchedCallback;

    int add_OnPlayerEnteredRoom(OnPlayerEnteredRoomCallback callback);
    int add_OnPlayerLeftRoom(OnPlayerLeftRoomCallback callback);
    int add_OnRoomPropertiesUpdate(OnRoomPropertiesUpdateCallback callback);
    int add_OnPlayerPropertiesUpdate(OnPlayerPropertiesUpdateCallback callback);
    int add_OnMasterClientSwitched(OnMasterClientSwitchedCallback callback);

    void remove_OnPlayerEnteredRoom(int identifier);
    void remove_OnPlayerLeftRoom(int identifier);
    void remove_OnRoomPropertiesUpdate(int identifier);
    void remove_OnPlayerPropertiesUpdate(int identifier);
    void remove_OnMasterClientSwitched(int identifier);
}