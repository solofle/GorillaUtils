#include "beatsaber-hook/shared/utils/utils.h"
#include "beatsaber-hook/shared/utils/il2cpp-utils.hpp"

#include "modloader/shared/modloader.hpp"

#include "Callbacks/ErrorInfoCallbacksInternal.hpp"

namespace Photon::Realtime {
    class ErrorInfo;
    class ErrorInfoCallbacksContainer;
}

using ErrorInfoCallbacksContainer = Photon::Realtime::ErrorInfoCallbacksContainer;
using ErrorInfo = Photon::Realtime::ErrorInfo;

using namespace GorillaUtils;

// ErrorInfoCallbacksContianer hooks
MAKE_HOOK_OFFSETLESS(ErrorInfoCallbacksContainer_OnErrorInfo, void, ErrorInfoCallbacksContainer* self, ErrorInfo* response)
{
    ErrorInfoCallbacksContainer_OnErrorInfo(self, response);
    ErrorInfoCallbacks::OnErrorInfo(response);
}

void installErrorInfoCallbackHooks(Logger& logger)
{
    INSTALL_HOOK_OFFSETLESS(logger, ErrorInfoCallbacksContainer_OnErrorInfo, il2cpp_utils::FindMethodUnsafe("Photon.Realtime", "ErrorInfoCallbacksContainer", "OnErrorInfo", 1));
}