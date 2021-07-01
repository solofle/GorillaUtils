#include "beatsaber-hook/shared/utils/utils.h"
#include "beatsaber-hook/shared/utils/il2cpp-utils.hpp"

#include "modloader/shared/modloader.hpp"
#include "custom-types/shared/register.hpp"
#include "NetworkJoinTrigger.hpp"
#include "Utils/RPC.hpp"
#include "GorillaUtilsInternal.hpp"

#include "GlobalNamespace/OVRManager.hpp"
#include "OVRUpdater.hpp"
#include "UnityEngine/GameObject.hpp"
#include "UnityEngine/Object.hpp"

ModInfo modInfo;
bool loaded = false;

Logger& getLogger()
{
    Logger* logger = new Logger({ID, VERSION}, LoggerOptions(false, true));
    return *logger;
}

extern "C" void setup(ModInfo& info)
{
    info.id = ID;
    info.version = VERSION;
}

MAKE_HOOK_OFFSETLESS(GorillaComputer_Start, void, Il2CppObject* self)
{
    GorillaComputer_Start(self);
    using GameObject = UnityEngine::GameObject;
    using Object = UnityEngine::Object;
    
    GameObject* obj = GameObject::New_ctor(); 
    Object::DontDestroyOnLoad(obj);

    obj->AddComponent<GorillaUtils::OVRUpdater*>();
}

extern void installConnectionCallbackHooks(Logger& logger);
extern void installMatchMakingCallbackHooks(Logger& logger);
extern void installInRoomCallbackHooks(Logger& logger);
extern void installLobbyCallbackHooks(Logger& logger);
extern void installWebRpcCallbackHooks(Logger& logger);
extern void installErrorInfoCallbackHooks(Logger& logger);

void loadLib()
{
    if (loaded) return;
    loaded = true;
    Logger& logger = getLogger();
    
    INSTALL_HOOK_OFFSETLESS(logger, GorillaComputer_Start, il2cpp_utils::FindMethodUnsafe("", "GorillaComputer", "Start", 0));

    logger.info("Installing ConnectionCallbacks hooks...");
    installConnectionCallbackHooks(logger);
    logger.info("Installed ConnectionCallbacks hooks!");
    
    logger.info("Installing MatchMakingCallbacks hooks...");
    installMatchMakingCallbackHooks(logger);
    logger.info("Installed MatchMakingCallbacks hooks!");

    logger.info("Installing InRoomCallbacks hooks...");
    installInRoomCallbackHooks(logger);
    logger.info("Installed InRoomCallbacks hooks!");

    logger.info("Installing LobbyCallbacks hooks...");
    installLobbyCallbackHooks(logger);
    logger.info("Installed LobbyCallbacks hooks!");
    
    logger.info("Installing WebRpcCallbacks hooks...");
    installWebRpcCallbackHooks(logger);
    logger.info("Installed WebRpcCallbacks hooks!");

    logger.info("Installing ErrorInfoCallbacks hooks...");
    installErrorInfoCallbackHooks(logger);
    logger.info("Installed ErrorInfoCallbacks hooks!");
    
    custom_types::Register::RegisterType<GorillaUtils::NetworkJoinTrigger>();
    custom_types::Register::RegisterType<GorillaUtils::OVRUpdater>();
}