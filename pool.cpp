#include <iostream>
#include <mutex>
#include <deque>
#include "pool.hpp"
#include "autoit_instance.hpp"

std::mutex pool_mutex;
std::deque<autoit_instance> pool;

autoit_instance get_autoit_instance(void) {
	std::lock_guard<std::mutex> lock(pool_mutex);
	std::cout << "getting autoit instance from pool" << std::endl;
	if (pool.empty()) {
		std::cout << "pool is empty" << std::endl;
		autoit_instance new_instance;
		std::cout << "made new instance" << std::endl;
		return new_instance;
	} else {
		std::cout << "taking from pool" << std::endl;
		autoit_instance old_instance = std::move(pool.front());
		pool.pop_front();
		std::cout << "took from pool" << std::endl;
		return old_instance;
	}
}

void release_autoit_instance(autoit_instance&& released_instance) {
	std::lock_guard<std::mutex> lock(pool_mutex);
	pool.push_back(std::move(released_instance));
	std::cout << "released autoit instance to pool" << std::endl;
}

