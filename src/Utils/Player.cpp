#include "Utils/Player.hpp"

#include "CustomProperties/Player.hpp"
#include "CustomProperties/Room.hpp"

#include "Photon/Pun/PhotonView.hpp"
#include "Photon/Pun/PhotonNetwork.hpp"

#include "GlobalNamespace/VRRig.hpp"
#include "GlobalNamespace/GorillaParent.hpp"

#include "UnityEngine/Component.hpp"


extern Logger& getLogger();
namespace GorillaUtils::Player
{
    using PhotonNetwork = Photon::Pun::PhotonNetwork;
    bool isPlayerTagged(Player* player)
    {
        if (!PhotonNetwork::get_InRoom()) return false;

        VRRig* rig = findPlayerVRRig(player);
        if (rig) return rig->setMatIndex > 0;
        else return false;

        // this is the actual proper way of getting if the gorilla is tagged, but since the isCurrentlyTag property and the other player properties
        // aren't always properly set, we are opting for a method that does work, which is reading the set material index and if its above 0 the gorilla is tagged
        /*
        auto room = PhotonNetwork::get_CurrentRoom();
        auto isTagResult = GorillaUtils::Room::GetProperty<bool>(room, "isCurrentlyTag");

        bool isCurrentlyTag = false;
        if (isTagResult) isCurrentlyTag = *isTagResult;
        else getLogger().info("Room did not have isCurrentlyTag property, assuming false");

        if (isCurrentlyTag) // tag
        {
            auto currentIt = GorillaUtils::Room::GetProperty<Player*>(room, "currentIt");

            if (!currentIt) 
            {
                getLogger().info("Could not find currentIt property on room, returning false");
                return false;
            }
            else return player->Equals(*currentIt);
        }
        else // infection
        {
            auto isInfected = GetProperty<bool>(player, "isInfected");

            if (!isInfected) 
            {
                getLogger().info("Could not find isInfected property on player, returning false");
                return false;
            }
            else return *isInfected;
        }
        */
    }

    VRRig* findPlayerVRRig(Player* player)
    {
        return findPlayerVRRig(player->get_UserId());
    }

    VRRig* findPlayerVRRig(Il2CppString* userID)
    {
        Array<VRRig*>* rigs = GlobalNamespace::GorillaParent::_get_instance()->GetComponentsInChildren<VRRig*>();

        for (int i = 0; i < rigs->Length(); i++)
        {
            VRRig* rig = rigs->values[i];
            Photon::Realtime::Player* player = rig->get_photonView() ? rig->get_photonView()->get_Owner() : nullptr;
            if (player && player->get_UserId()->Contains(userID)) return rig;
        }

        return nullptr;
    }

    VRRig* findPlayerVRRig(std::string userID)
    {
        return findPlayerVRRig(il2cpp_utils::newcsstr(userID));
    }
}