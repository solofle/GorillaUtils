#include "Callbacks/WebRpcCallbacksInternal.hpp"
#include "Callbacks/WebRpcCallbacks.hpp"
#include "CallbackUtils.hpp"

namespace GorillaUtils::WebRpcCallbacks
{
    OnWebRpcResponseCallbackContainer onWebRpcResponseCallbackContainer;

    void OnWebRpcResponse(OperationResponse* response)
    {
        RUNCALLBACKS(onWebRpcResponseCallbackContainer, response);    
    }

    int add_OnWebRpcResponse(OnWebRpcResponseCallback callback)
    {
        return ADD(onWebRpcResponseCallbackContainer);
    }

    void remove_OnWebRpcResponse(int identifier)
    {
        REMOVE(onWebRpcResponseCallbackContainer);
    }
}