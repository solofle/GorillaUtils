#pragma once

#include "CallbackContainer.hpp"
#include "Callbacks/ErrorInfoCallbacks.hpp"

namespace GorillaUtils::ErrorInfoCallbacks
{
    void OnErrorInfo(ErrorInfo* response);
}