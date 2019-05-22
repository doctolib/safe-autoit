#pragma once
#include <windows.h>

struct autoit_instance_symbols {
	autoit_instance_symbols(void);
	autoit_instance_symbols(autoit_instance_symbols&&) = delete;
	autoit_instance_symbols(autoit_instance_symbols const&) = delete;
	~autoit_instance_symbols(void);
	#define X(result, name, params...) result __stdcall (*name)(params);
	# include "autoit_functions.hpp"
	#undef X
	private:
	bool is_library_clone;
	HMODULE handle;
	WCHAR library_path[MAX_PATH + 1];
};
