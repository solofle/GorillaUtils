#include "Callbacks/WebRpcCallbacksInternal.hpp"
#include "Callbacks/WebRpcCallbacks.hpp"
#include "CallbackUtils.hpp"

namespace GorillaUtils::WebRpcCallbacks
{
    EVENT(OnWebRpcResponseEvent, onWebRpcResponseEvent);

    void OnWebRpcResponse(OperationResponse* response) { RUNCALLBACKS(OnWebRpcResponseEvent, response); }
}