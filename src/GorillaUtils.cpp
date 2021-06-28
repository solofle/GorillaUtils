#include "GorillaUtils.hpp"
#include "GorillaUtilsInternal.hpp"
#include "beatsaber-hook/shared/utils/logging.hpp" 

#include "Callbacks/MatchMakingCallbacks.hpp"
#include "Utils/Room.hpp"
#include "CustomProperties/Room.hpp"

#include "Photon/Pun/PhotonNetwork.hpp"
#include "ExitGames/Client/Photon/Hashtable.hpp"

#include <sstream>

extern Logger& getLogger();
extern void loadLib();

#include "DisablingValueContainer.hpp"

namespace GorillaUtils
{
    std::vector<DisablingValueContainer> containers;

    void Init()
    {
        loadLib();
    }

    void Innit()
    {
        getLogger().info("Cheers bruv");
        Init();
    }

    void RegisterCheckCallbacks()
    {
        MatchMakingCallbacks::add_OnJoinedRoom(&OnJoinedRoom);
        MatchMakingCallbacks::add_OnLeftRoom(&OnLeftRoom);
    }

    void OnJoinedRoom()
    {
        if (containers.size() == 0) return;

        auto gameModeOptional = Room::getRoomGameMode();
        if (!gameModeOptional) gameModeOptional = Room::getGameMode();
        std::string gameMode = "";
        if (gameModeOptional) gameMode = *gameModeOptional;

        std::stringstream sstream;

        sstream << std::boolalpha;
        sstream << "{ ";
        for(auto c : containers)
        {
            // if private, set true
            if (Room::getIsPrivate()) c.set_value(true);
            else // if public
            {
                c.set_value(c.checkQueue(gameMode));
            }
            const ModInfo& info = c.get_info();
            sstream << '\"' << info.id << '|'<< info.version << "\": " << c.get_value() << ", "; 
        }
        sstream << "}";

        std::string text = sstream.str();

        Room::SetProperty(Photon::Pun::PhotonNetwork::get_CurrentRoom(), "mods", il2cpp_utils::newcsstr(text));
    }

    void OnLeftRoom()
    {
        if (containers.size() == 0) return;

        for(auto c : containers)
        {
            c.set_ifLocal();
        }
    }

    void RegisterDisablingValue(std::string name, std::string version, bool& value, std::vector<std::string> queues)
    {
        RegisterDisablingValue({name, version}, value, false, queues);
    }

    void RegisterDisablingValue(ModInfo info, bool& value, std::vector<std::string> queues)
    {
        RegisterDisablingValue(info, value, false, queues);
    }

    void RegisterDisablingValue(std::string name, std::string version, bool& value, bool allowLocal, std::vector<std::string> queues)
    {
        RegisterDisablingValue({name, version}, value, allowLocal, queues);
    }

    void RegisterDisablingValue(ModInfo info, bool& value, bool allowLocal, std::vector<std::string> queues)
    {
        containers.push_back(DisablingValueContainer(info, value, allowLocal, queues));
        value = allowLocal;
    }
}