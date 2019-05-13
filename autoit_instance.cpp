#include "autoit_instance.hpp"
#include "vaargs.hpp"

extern "C" {
#define X(result, name, ...) result autoit_instance::name(EV(PARAMS, PP_NARG(toto,## __VA_ARGS__))(__VA_ARGS__)) const { \
	return this->symbols->name(EV(NARGS, PP_NARG(toto,## __VA_ARGS__))); \
}
#include "autoit_functions.h"
}
