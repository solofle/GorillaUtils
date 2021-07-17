#include "beatsaber-hook/shared/utils/logging.hpp"
extern Logger& getLogger();

#ifndef RUNCALLBACKS
#define RUNCALLBACKS(container, args...) \
getLogger().info("Running Callbacks for %s", #container); \
_ ##container.invoke(args);
#endif

#ifndef TO_CPP_STRING
#define TO_CPP_STRING(csString) (csString ? to_utf8(csstrtostr(csString)) : "")
#endif

#ifndef ADD
#define ADD(container) container.add(callback)
#endif

#ifndef REMOVE
#define REMOVE(container) container.remove(identifier)
#endif


// Declares the variable, and defines the getter
#ifndef EVENT
#define EVENT(typename, getter) \
typename _ ##typename; \
typename& getter() {return _ ##typename; }
#endif