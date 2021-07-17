#pragma once

#include "CallbackContainer.hpp"
#include "Callbacks/WebRpcCallbacks.hpp"

namespace GorillaUtils::WebRpcCallbacks
{
    void OnWebRpcResponse(OperationResponse* response);
}