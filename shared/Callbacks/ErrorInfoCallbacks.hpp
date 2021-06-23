#pragma once

#include <functional>

namespace Photon::Realtime {
    class ErrorInfo;
}

namespace GorillaUtils::ErrorInfoCallbacks
{
    using ErrorInfo = Photon::Realtime::ErrorInfo;
    
    typedef std::function<void(ErrorInfo*)> OnErrorInfoCallback;

    int add_OnErrorInfo(OnErrorInfoCallback callback);
    
    void remove_OnErrorInfo(int identifier);
}