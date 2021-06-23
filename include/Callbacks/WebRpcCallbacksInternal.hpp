#pragma once

#include "CallbackContainer.hpp"
#include "Callbacks/WebRpcCallbacks.hpp"

namespace GorillaUtils::WebRpcCallbacks
{
    typedef CallbackContainer<OnWebRpcResponseCallback> OnWebRpcResponseCallbackContainer;

    void OnWebRpcResponse(OperationResponse* response);
}