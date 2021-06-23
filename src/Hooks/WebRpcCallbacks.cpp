#include "beatsaber-hook/shared/utils/utils.h"
#include "beatsaber-hook/shared/utils/il2cpp-utils.hpp"

#include "modloader/shared/modloader.hpp"

#include "Callbacks/WebRpcCallbacksInternal.hpp"

namespace Photon::Realtime {
    class OperationResponse;
    class WebRpcCallbacksContainer;
}

using WebRpcCallbacksContainer = Photon::Realtime::WebRpcCallbacksContainer;
using OperationResponse = Photon::Realtime::OperationResponse;

using namespace GorillaUtils;

// WebRpcCallbacksContianer hooks
MAKE_HOOK_OFFSETLESS(WebRpcCallbacksContainer_OnWebRpcResponse, void, WebRpcCallbacksContainer* self, OperationResponse* response)
{
    WebRpcCallbacksContainer_OnWebRpcResponse(self, response);
    WebRpcCallbacks::OnWebRpcResponse(response);
}

void installWebRpcCallbackHooks(Logger& logger)
{
    INSTALL_HOOK_OFFSETLESS(logger, WebRpcCallbacksContainer_OnWebRpcResponse, il2cpp_utils::FindMethodUnsafe("Photon.Realtime", "WebRpcCallbacksContainer", "OnWebRpcResponse", 1));
}