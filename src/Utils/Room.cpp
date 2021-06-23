#include "Utils/Room.hpp"
#include "beatsaber-hook/shared/utils/il2cpp-utils.hpp"
#include "CustomProperties/Room.hpp"
#include "CallbackUtils.hpp"

#include "Photon/Pun/PhotonNetwork.hpp"
#include "GlobalNamespace/PhotonNetworkController.hpp"
#include "NetworkJoinTrigger.hpp"

#define NETWORKCONTROLLER GlobalNamespace::PhotonNetworkController::_get_instance()

namespace GorillaUtils::Room
{
    using PhotonNetwork = Photon::Pun::PhotonNetwork;
    std::optional<std::string> getRoomGameMode()
    {
        if (!PhotonNetwork::get_InRoom()) return std::nullopt;
        auto room = PhotonNetwork::get_CurrentRoom();

        auto gameMode = GetProperty<Il2CppString*>(room, "gameMode");
        if (!gameMode) return "";
        else return TO_CPP_STRING(*gameMode);
    }

    std::optional<std::string> get_roomID()
    {
        if (!PhotonNetwork::get_InRoom()) return std::nullopt;
        auto room = PhotonNetwork::get_CurrentRoom();
        
        Il2CppString* roomName = room->get_Name();
        return TO_CPP_STRING(roomName);
    }

    void joinRoom(std::string roomID)
    {
        // if room id empty just early return
        if (roomID == "") return;
        auto roomNameResult = get_roomID();
        // if in a room (result came back) and room name is equal to given room id, early return;
        if (roomNameResult && *roomNameResult == roomID) return;
        // use the networkcontroller to join specific room
        NETWORKCONTROLLER->AttemptToJoinSpecificRoom(il2cpp_utils::newcsstr(roomID));
    }

    void joinPublic(std::string gameMode)
    {
        if (gameMode == "") return;
        NetworkJoinTrigger::get_instance()->set_gameMode(gameMode);
        joinPublic(NetworkJoinTrigger::get_instance());
    }

    void joinPublic(GorillaNetworkJoinTrigger* trigger)
    {
        // if trigger null or gamemode is null or empty, just return
        if (!trigger || Il2CppString::IsNullOrEmpty(trigger->gameModeName)) return;
        NETWORKCONTROLLER->AttemptToJoinPublicRoom(trigger);
    }

    std::optional<std::string> getGameMode()
    {
        GlobalNamespace::PhotonNetworkController* networkController = NETWORKCONTROLLER;
        GorillaNetworkJoinTrigger* trigger = networkController->currentJoinTrigger;
        if (!trigger || !trigger->gameModeName) return std::nullopt;

        return TO_CPP_STRING(trigger->gameModeName);
    }

    std::optional<bool> getIsPublic()
    {
        if (!PhotonNetwork::get_InRoom()) return std::nullopt;
        auto room = PhotonNetwork::get_CurrentRoom();
        return room->get_IsVisible();
    }

    std::optional<bool> getIsPrivate()
    {
        auto result = getIsPublic();
        if (!result) return result;
        else return !*result;
    }
}