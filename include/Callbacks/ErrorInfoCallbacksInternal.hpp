#pragma once

#include "CallbackContainer.hpp"
#include "Callbacks/ErrorInfoCallbacks.hpp"

namespace GorillaUtils::ErrorInfoCallbacks
{
    typedef CallbackContainer<OnErrorInfoCallback> OnErrorInfoCallbackContainer;
    
    void OnErrorInfo(ErrorInfo* response);
}