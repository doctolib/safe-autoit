#include <iostream>
#include <windows.h>
#include "autoit_instance_symbols.hpp"

#define AUTOIT_LIBRARY_NAME L"AutoItX3_original.dll"
#define countof(xs) (sizeof(xs) / sizeof(*(xs)))

bool autoit_loaded = false;
DWORD autoit_path_size = 0;
WCHAR autoit_path[MAX_PATH + 1] = {0};

autoit_instance_symbols::autoit_instance_symbols(void) {
	if (autoit_loaded) {
		GetTempFileNameW(L".", L"ait", 0, this->library_path);
		CopyFileW(autoit_path, this->library_path, false);
		this->handle = LoadLibraryW(this->library_path);
		this->is_library_clone = true;
	} else {
		this->handle = LoadLibraryW(AUTOIT_LIBRARY_NAME);
		autoit_path_size = GetModuleFileNameW(this->handle, autoit_path, countof(autoit_path));
		wcscpy_s(this->library_path, countof(this->library_path), autoit_path);
		autoit_loaded = true;
	}
	void __stdcall (*init)(void) = (void __stdcall (*)(void))GetProcAddress(this->handle, "AU3_Init");
	init();
	#define X(type, name, params...) this->name = (type __stdcall (*)(params))GetProcAddress(this->handle, #name);
	# include "autoit_functions.h"
	#undef X
}

autoit_instance_symbols::~autoit_instance_symbols(void) {
	FreeLibrary(this->handle);
	if (this->is_library_clone) DeleteFileW(this->library_path);
}
