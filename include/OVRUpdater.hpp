#pragma once

#include "custom-types/shared/macros.hpp"
#include "UnityEngine/MonoBehaviour.hpp"

DECLARE_CLASS_CODEGEN(GorillaUtils, OVRUpdater, UnityEngine::MonoBehaviour,
    DECLARE_METHOD(void, Update);
    DECLARE_METHOD(void, FixedUpdate);

    REGISTER_FUNCTION(
        REGISTER_METHOD(Update);
        REGISTER_METHOD(FixedUpdate);
    )
)