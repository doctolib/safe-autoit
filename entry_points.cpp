#include <windows.h>
#include "AutoItX3_DLL.h"
#include "wrapper.hpp"
#include "vaargs.hpp"

#define FUNvoid void_autoit_function
#define FUNint autoit_function
#define FUNHWND autoit_function
#define FUNDWORD autoit_function

extern "C" {
#define X(result, name, ...) result name(EV(PARAMS, PP_NARG(magic,## __VA_ARGS__))(__VA_ARGS__)) { \
	return EV(FUN, result)(&autoit_instance::name EV(ARGS, PP_NARG(magic,## __VA_ARGS__))); \
}
#include "autoit_functions.h"
}
