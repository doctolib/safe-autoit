#include <iostream>
#include <windows.h>
#include "autoit_instance_symbols.hpp"

#define AUTOIT_LIBRARY_NAME "AutoItX3.dll"

autoit_instance_symbols::autoit_instance_symbols(void) {
	this->handle = LoadLibraryA(AUTOIT_LIBRARY_NAME);
	std::cout << "library handle is " << this->handle << std::endl;
	void __stdcall (*init)(void) = (void __stdcall (*)(void))GetProcAddress(this->handle, "AU3_Init");
	init();
	#define X(type, name, params...) this->name = (type __stdcall (*)(params))GetProcAddress(this->handle, #name);
	# include "autoit_functions.h"
	#undef X
}

autoit_instance_symbols::~autoit_instance_symbols(void) {
	FreeLibrary(this->handle);
}
