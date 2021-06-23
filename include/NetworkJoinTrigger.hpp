#pragma once

#include "custom-types/shared/macros.hpp"
#include "GlobalNamespace/GorillaNetworkJoinTrigger.hpp"
#include "GlobalNamespace/GorillaTriggerBox.hpp"
#include <string>

DECLARE_CLASS_CODEGEN(GorillaUtils, NetworkJoinTrigger, GlobalNamespace::GorillaNetworkJoinTrigger,
    DECLARE_CTOR(ctor);
    DECLARE_METHOD(static NetworkJoinTrigger*, get_instance);

    public:
        void set_gameMode(std::string gameMode);
    private:
        static inline NetworkJoinTrigger* instance = nullptr;
    REGISTER_FUNCTION(
        REGISTER_METHOD(ctor);
        REGISTER_METHOD(get_instance);
    )
)