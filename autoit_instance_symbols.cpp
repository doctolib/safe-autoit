#include <windows.h>
#include "autoit_instance_symbols.hpp"

autoit_instance_symbols::autoit_instance_symbols(void) {
	this->handle = LoadLibraryA("toto");
	#define X(type, name, params...) this->name = (type __stdcall (*)(params))GetProcAddress(this->handle, #name);
	# include "autoit_functions.h"
	#undef X
}

autoit_instance_symbols::~autoit_instance_symbols(void) {
	FreeLibrary(this->handle);
}
