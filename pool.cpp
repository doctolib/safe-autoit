#include <iostream>
#include <mutex>
#include <deque>
#include "pool.hpp"
#include "autoit_instance.hpp"

const int max_pool_size = 5;

std::mutex pool_mutex;
std::deque<autoit_instance> pool;

autoit_instance get_autoit_instance(void) {
	std::lock_guard<std::mutex> lock(pool_mutex);
	if (pool.empty()) {
		autoit_instance new_instance;
		return new_instance;
	} else {
		autoit_instance old_instance = std::move(pool.front());
		pool.pop_front();
		return old_instance;
	}
}

void release_autoit_instance(autoit_instance&& released_instance) {
	std::lock_guard<std::mutex> lock(pool_mutex);
	if (pool.size() < max_pool_size)
		pool.push_back(std::move(released_instance));
}

