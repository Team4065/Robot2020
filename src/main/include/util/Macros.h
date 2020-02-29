#include <string.h>

// LOG_LEVEL should be changed based on what logs are desired in the console. For 
// example, if you didn't want to see debug logs, you would need to set LOG_LEVEL to 1.
#define LOG_LEVEL 0

#define DEBUG_LEVEL 0X00
#define INFO_LEVEL 0x01
#define FATAL_LEVEL 0xFF

#if !(LOG_LEVEL > DEBUG_LEVEL)
#   define DEBUG_LOG(x) std::cout << "[DEBUG] " << x << std::endl;
#else
#   define DEBUG_LOG(x)
#endif

#if !(LOG_LEVEL > INFO_LEVEL)
#   define INFO_LOG(x) std::cout << "[INFO] " << x << std::endl;
#else
#   define INFO_LOG(x)
#endif

#if !(LOG_LEVEL > FATAL_LEVEL)
#   define FATAL_LOG(x) std::cout << "[FATAL] " << x << std::endl;
#else
#   define FATAL_LOG(x)
#endif

#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
TypeName(const TypeName&) = delete;        \
void operator=(const TypeName&) = delete

#define STRINGIFY(x) #x