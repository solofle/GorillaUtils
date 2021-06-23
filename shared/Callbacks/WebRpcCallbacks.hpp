#pragma once

#include <functional>

namespace Photon::Realtime {
    class OperationResponse;
}

namespace GorillaUtils::WebRpcCallbacks
{
    using OperationResponse = Photon::Realtime::OperationResponse;

    typedef std::function<void(OperationResponse*)> OnWebRpcResponseCallback;

    int add_OnWebRpcResponse(OnWebRpcResponseCallback callback);

    void remove_OnWebRpcResponse(int identifier);
}