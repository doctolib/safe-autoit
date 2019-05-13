#pragma once
#include <windows.h>

struct autoit_instance {
	autoit_instance(void) = default;
	autoit_instance(autoit_instance&&) = default;
	autoit_instance(autoit_instance const&) = delete;
	#define X(type, name, ...) type name(__VA_ARGS__) const;
	# include "autoit_functions.h"
	#undef X
	private:
	std::unique_ptr<autoit_instance_symbols> symbols;
};
