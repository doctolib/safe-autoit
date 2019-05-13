#pragma once
#include <windows.h>

struct autoit_instance_symbols {
	autoit_instance_symbols(void);
	~autoit_instance_symbols(void);
	private:
	#define X(result, name, params) result (*name)(params);
	# include "autoit_functions.h"
	#undef X
	HMODULE handle;
};
