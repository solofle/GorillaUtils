#pragma once

#include <functional>

namespace ExitGames::Client::Photon {
    class OperationResponse;
}

namespace GorillaUtils::WebRpcCallbacks
{
    using OperationResponse = ExitGames::Client::Photon::OperationResponse;

    typedef std::function<void(OperationResponse*)> OnWebRpcResponseCallback;

    int add_OnWebRpcResponse(OnWebRpcResponseCallback callback);

    void remove_OnWebRpcResponse(int identifier);
}