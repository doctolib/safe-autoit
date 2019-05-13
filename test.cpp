#include <iostream>
#include "AutoItX3_DLL.h"

int main(void) {
	std::cout << "started" << std::endl;
	AU3_WinMinimizeAll();
	std::cout << "minimized all" << std::endl;
	return 0;
}
