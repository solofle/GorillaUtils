#include "beatsaber-hook/shared/utils/utils.h"
#include "beatsaber-hook/shared/utils/il2cpp-utils.hpp"
#include "beatsaber-hook/shared/utils/hooking.hpp"

#include "modloader/shared/modloader.hpp"

#include "Callbacks/WebRpcCallbacksInternal.hpp"
#include "Photon/Realtime/WebRpcCallbacksContainer.hpp"
#include "ExitGames/Client/Photon/OperationResponse.hpp"

using WebRpcCallbacksContainer = Photon::Realtime::WebRpcCallbacksContainer;
using OperationResponse = ExitGames::Client::Photon::OperationResponse;

using namespace GorillaUtils;

// WebRpcCallbacksContianer hooks
MAKE_HOOK_MATCH(WebRpcCallbacksContainer_OnWebRpcResponse, &WebRpcCallbacksContainer::OnWebRpcResponse, void, WebRpcCallbacksContainer* self, OperationResponse* response)
{
    WebRpcCallbacksContainer_OnWebRpcResponse(self, response);
    WebRpcCallbacks::OnWebRpcResponse(response);
}

void installWebRpcCallbackHooks(Logger& logger)
{
    INSTALL_HOOK(logger, WebRpcCallbacksContainer_OnWebRpcResponse);
}