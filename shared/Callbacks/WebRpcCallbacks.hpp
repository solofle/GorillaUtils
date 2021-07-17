#pragma once

#include "beatsaber-hook/shared/utils/typedefs-wrappers.hpp"
#include <functional>

namespace ExitGames::Client::Photon {
    class OperationResponse;
}

namespace GorillaUtils::WebRpcCallbacks
{
    using OperationResponse = ExitGames::Client::Photon::OperationResponse;

    typedef UnorderedEventCallback<OperationResponse*> OnWebRpcResponseEvent;

    OnWebRpcResponseEvent& onWebRpcResponseEvent();
}