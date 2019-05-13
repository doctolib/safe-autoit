#include <algorithm>
#include <thread>
#include <iostream>
#include <array>
#include "AutoItX3_DLL.h"

void work(void) {
	AU3_Sleep(2000);
}

int main(void) {
	std::array<std::thread, 5> threads;
	std::cout << "started" << std::endl;
	std::for_each(threads.begin(), threads.end(), [](std::thread& thread) {
		std::thread new_thread(work);
		std::swap(new_thread, thread);
	});
	std::cout << "started all workers" << std::endl;
	std::for_each(threads.begin(), threads.end(), [](std::thread& thread) {
		thread.join();
	});
	std::cout << "joined all workers" << std::endl;
	return 0;
}
