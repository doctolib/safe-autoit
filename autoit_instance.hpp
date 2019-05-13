#pragma once
#include <windows.h>
#include <memory>
#include <utility>
#include "autoit_instance_symbols.hpp"

struct autoit_instance {
	autoit_instance(void);
	autoit_instance(autoit_instance&&) = default;
	autoit_instance(autoit_instance const&) = delete;
	#define X(type, name, ...) type name(__VA_ARGS__) const;
	# include "autoit_functions.h"
	#undef X
	private:
	std::unique_ptr<autoit_instance_symbols> symbols;
};
