#include "Callbacks/ErrorInfoCallbacksInternal.hpp"
#include "Callbacks/ErrorInfoCallbacks.hpp"
#include "CallbackUtils.hpp"

namespace GorillaUtils::ErrorInfoCallbacks
{
    EVENT(OnErrorInfoEvent, onErrorInfoEvent);

    void OnErrorInfo(ErrorInfo* response) {RUNCALLBACKS(OnErrorInfoEvent, response); }
}