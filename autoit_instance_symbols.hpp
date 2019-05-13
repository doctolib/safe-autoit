#pragma once
#include <windows.h>

struct autoit_instance_symbols {
	autoit_instance_symbols(void);
	~autoit_instance_symbols(void);
	#define X(result, name, params...) result __stdcall (*name)(params);
	# include "autoit_functions.h"
	#undef X
	private:
	HMODULE handle;
};
