#include "OVRUpdater.hpp"
#include "GlobalNamespace/OVRInput.hpp"

DEFINE_TYPE(GorillaUtils::OVRUpdater);

namespace GorillaUtils
{
    void OVRUpdater::Update()
    {
        GlobalNamespace::OVRInput::Update();
    }

    void OVRUpdater::FixedUpdate()
    {
        GlobalNamespace::OVRInput::FixedUpdate();
    }
}