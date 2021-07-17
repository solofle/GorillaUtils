#include "beatsaber-hook/shared/utils/utils.h"
#include "beatsaber-hook/shared/utils/il2cpp-utils.hpp"
#include "beatsaber-hook/shared/utils/hooking.hpp"

#include "modloader/shared/modloader.hpp"

#include "Callbacks/ErrorInfoCallbacksInternal.hpp"
#include "Photon/Realtime/ErrorInfoCallbacksContainer.hpp"
#include "Photon/Realtime/ErrorInfo.hpp"

using ErrorInfoCallbacksContainer = Photon::Realtime::ErrorInfoCallbacksContainer;
using ErrorInfo = Photon::Realtime::ErrorInfo;

using namespace GorillaUtils;

// ErrorInfoCallbacksContianer hooks
MAKE_HOOK_MATCH(ErrorInfoCallbacksContainer_OnErrorInfo, &ErrorInfoCallbacksContainer::OnErrorInfo, void, ErrorInfoCallbacksContainer* self, ErrorInfo* response)
{
    ErrorInfoCallbacksContainer_OnErrorInfo(self, response);
    ErrorInfoCallbacks::OnErrorInfo(response);
}

void installErrorInfoCallbackHooks(Logger& logger)
{
    INSTALL_HOOK(logger, ErrorInfoCallbacksContainer_OnErrorInfo);
}