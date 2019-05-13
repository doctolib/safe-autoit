#include <memory>
#include "autoit_instance.hpp"
#include "vaargs.hpp"

autoit_instance::autoit_instance(void) : symbols(std::make_unique<autoit_instance_symbols>()) {}

#define X(result, name, ...) result autoit_instance::name(EV(PARAMS, PP_NARG(toto,## __VA_ARGS__))(__VA_ARGS__)) const { \
	return this->symbols->name(EV(NARGS, PP_NARG(toto,## __VA_ARGS__))); \
}
#include "autoit_functions.h"
#undef X
