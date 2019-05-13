#include <windows.h>
#include "AutoItX3_DLL.h"
#include "wrapper.hpp"
#include "vaargs.hpp"

extern "C" {
#define X(result, name, ...) result name(EV(PARAMS, PP_NARG(magic,## __VA_ARGS__))(__VA_ARGS__)) { \
	return autoit_function(&autoit_instance::name EV(ARGS, PP_NARG(magic,## __VA_ARGS__))); \
}
#include "autoit_functions.h"
}
