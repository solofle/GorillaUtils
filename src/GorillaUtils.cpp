#include "GorillaUtils.hpp"
#include "beatsaber-hook/shared/utils/logging.hpp" 

extern Logger& getLogger();

extern void loadLib();

namespace GorillaUtils
{
    void Init()
    {
        loadLib();
    }

    void Innit()
    {
        getLogger().info("Cheers bruv");
        Init();
    }
}