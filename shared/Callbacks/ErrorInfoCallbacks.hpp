#pragma once

#include "beatsaber-hook/shared/utils/typedefs-wrappers.hpp"

#include <functional>

namespace Photon::Realtime {
    class ErrorInfo;
}

namespace GorillaUtils::ErrorInfoCallbacks
{
    using ErrorInfo = Photon::Realtime::ErrorInfo;
    
    typedef UnorderedEventCallback<ErrorInfo*> OnErrorInfoEvent;
    
    OnErrorInfoEvent& onErrorInfoEvent();
}