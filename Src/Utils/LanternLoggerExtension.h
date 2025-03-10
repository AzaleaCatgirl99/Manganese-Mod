#include "Util/Logger.h"

// Lantern Logger Extensions; adds a changeable function name
#define M_LOG(funcName, ...) log(funcName, __VA_ARGS__)
#define M_LOGW(funcName, ...) logw(funcName, __VA_ARGS__)
#define M_LOG_C(funcName, color, ...) log_c(funcName, color, __VA_ARGS__)
#define M_LOGW_C(funcName, color, ...) logw_c(funcName, color, __VA_ARGS__)