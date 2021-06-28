#include "GorillaUtils.hpp"
#include "GorillaUtilsInternal.hpp"
#include "beatsaber-hook/shared/utils/logging.hpp" 

#include "Callbacks/MatchMakingCallbacks.hpp"
#include "Utils/Room.hpp"

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

    void RegisterDisablingValue(bool& value)
    {
        RegisterDisablingValue(value, false);
    }

    void RegisterDisablingValue(bool& value, bool allowLocal)
    {
        RegisterDisablingValue(value, allowLocal, {});
    }

    void RegisterDisablingValue(bool& value, std::vector<std::string> queues)
    {
        RegisterDisablingValue(value, false, queues);
    }

    void RegisterDisablingValue(bool& value, bool allowLocal, std::vector<std::string> queues)
    {
        containers.push_back(DisablingValueContainer(value, allowLocal, queues));
        value = allowLocal;
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

        for(auto c : containers)
        {
            // if private, set true
            if (Room::getIsPrivate()) c.set_value(true);
            else // if public
            {
                c.set_value(c.checkQueue(gameMode));
            }
        }
    }

    void OnLeftRoom()
    {
        for(auto c : containers)
        {
            c.set_ifLocal();
        }
    }
}