#include "Callbacks/ErrorInfoCallbacksInternal.hpp"
#include "Callbacks/ErrorInfoCallbacks.hpp"
#include "CallbackUtils.hpp"

namespace GorillaUtils::ErrorInfoCallbacks
{
    OnErrorInfoCallbackContainer onErrorInfoCallbackContainer;

    void OnErrorInfo(ErrorInfo* response)
    {
        RUNCALLBACKS(onErrorInfoCallbackContainer, response);
    }

    int add_OnErrorInfo(OnErrorInfoCallback callback)
    {
        return ADD(onErrorInfoCallbackContainer);
    }
    
    void remove_OnErrorInfo(int identifier)
    {
        REMOVE(onErrorInfoCallbackContainer);
    }
}