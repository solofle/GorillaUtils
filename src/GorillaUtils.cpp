#include "beatsaber-hook/shared/rapidjson/include/rapidjson/document.h"
#include "beatsaber-hook/shared/rapidjson/include/rapidjson/stringbuffer.h"
#include "beatsaber-hook/shared/rapidjson/include/rapidjson/prettywriter.h"

#include "GorillaUtils.hpp"
#include "GorillaUtilsInternal.hpp"
#include "beatsaber-hook/shared/utils/logging.hpp" 

#include "Callbacks/MatchMakingCallbacks.hpp"
#include "Utils/Room.hpp"
#include "CustomProperties/Player.hpp"

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
        auto gameModeOptional = Room::getRoomGameMode();
        if (!gameModeOptional) gameModeOptional = Room::getGameMode();
        std::string gameMode = "";
        if (gameModeOptional) gameMode = *gameModeOptional;

        // setup json doc to get an allocator
        rapidjson::Document d;
        d.SetObject();
        rapidjson::Document::AllocatorType& allocator = d.GetAllocator();  
        
        // known mods, this means we can know if the mod was enabled/disabled by the lib
        rapidjson::Value known;
        known.SetObject();

        for(auto c : containers)
        {
            // if private, set true
            if (Room::getIsPrivate()) c.set_value(true);
            else // if public
            {
                c.set_value(c.checkQueue(gameMode));
            }

            const ModInfo& info = c.get_info();
            std::string name = string_format("%s|%s", info.id.c_str(), info.version.c_str());
            rapidjson::Value jsonName = rapidjson::Value(name.c_str(), name.size(), allocator);
            known.AddMember(jsonName, c.get_value(), allocator);
        }

        // just list all the installed Mod IDs
        rapidjson::Value installedIDs(rapidjson::kArrayType);
        installedIDs.SetArray();

        for (const auto& m : Modloader::getMods())
        {
            const ModInfo& info = m.second.info;
            std::string name = string_format("%s|%s", info.id.c_str(), info.version.c_str());
            installedIDs.PushBack(rapidjson::Value(name.c_str(), name.size(), allocator), allocator);
        }

        // add it to the doc
        d.AddMember("known", known, allocator);
        d.AddMember("installedIDs", installedIDs, allocator);
        
        // stringify document
        rapidjson::StringBuffer buffer;
        buffer.Clear();

        // pretty writer for readability
        rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(buffer);
        d.Accept(writer);

        // make string out of buffer data
        std::string json(buffer.GetString(), buffer.GetSize());

        // set the property on the player 
        Player::SetProperty<Il2CppString*>(Photon::Pun::PhotonNetwork::get_LocalPlayer(), "mods", il2cpp_utils::newcsstr(json));
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