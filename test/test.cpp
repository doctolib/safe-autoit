#include <iostream>
#include <thread>
#include <algorithm>
#include <cassert>
#include <chrono>
#include "safe-autoit.h"

#define TEST(case) do { \
	test_##case(); std::cout << #case ": success!" << std::endl; \
} while(0)

void test_initial_state(void)
{
	assert(AU3Safe_max_pool_size() == 5);
	assert(AU3Safe_instances_count() == 0);
	assert(AU3Safe_instances_in_pool_count() == 0);
}

void test_single_call(void)
{
	assert(AU3_WinExists(L"abcdef", L"") == 0);
	assert(AU3Safe_instances_count() == 1);
	assert(AU3Safe_instances_in_pool_count() == 1);
}

void test_blocking(void)
{
	using namespace std::chrono;
	auto start = steady_clock::now();
	AU3_Sleep(200);
	auto end = steady_clock::now();
	auto sleep_span = duration_cast<milliseconds>(end - start).count();
	assert(sleep_span > 150);
	assert(sleep_span < 250);
}

void test_fills_the_pool(void)
{
	using namespace std::chrono;
	std::array<std::thread, 5> threads;
	auto start = steady_clock::now();
	std::for_each(threads.begin(), threads.end(), [](std::thread& thread) {
		thread = std::move(std::thread([]() {
			AU3_Sleep(200);
		}));
	});
	std::this_thread::sleep_for(milliseconds(50));
	assert(AU3Safe_instances_count() == 5);
	assert(AU3Safe_instances_in_pool_count() == 0);
	std::for_each(threads.begin(), threads.end(), [](std::thread& thread) {
		thread.join();
	});
	auto end = steady_clock::now();
	auto sleep_span = duration_cast<milliseconds>(end - start).count();
	assert(sleep_span > 150);
	assert(sleep_span < 250);
	assert(AU3Safe_instances_count() == 5);
	assert(AU3Safe_instances_in_pool_count() == 5);
}

void test_pool_overflows(void)
{
	using namespace std::chrono;
	std::array<std::thread, 10> threads;
	auto start = steady_clock::now();
	std::for_each(threads.begin(), threads.end(), [](std::thread& thread) {
		thread = std::move(std::thread([]() {
			AU3_Sleep(200);
		}));
	});
	std::this_thread::sleep_for(milliseconds(50));
	assert(AU3Safe_instances_count() == 10);
	assert(AU3Safe_instances_in_pool_count() == 0);
	std::for_each(threads.begin(), threads.end(), [](std::thread& thread) {
		thread.join();
	});
	auto end = steady_clock::now();
	auto sleep_span = duration_cast<milliseconds>(end - start).count();
	assert(sleep_span > 150);
	assert(sleep_span < 300);
	assert(AU3Safe_instances_count() == 5);
	assert(AU3Safe_instances_in_pool_count() == 5);
}

int main(void) {
	TEST(initial_state);
	TEST(single_call);
	TEST(single_call); // ensure no more instances are created
	TEST(blocking);
	TEST(fills_the_pool);
	TEST(pool_overflows);
	return EXIT_SUCCESS;
}
