#include <iostream>
#include <mutex>
#include <shared_mutex>
#include <deque>
#include "pool.hpp"
#include "autoit_instance.hpp"
#include "safe-autoit.h"

namespace {
	const int max_pool_size = 5;
	std::shared_mutex mutex;
	std::deque<autoit_instance> pool;
	int instances_count;
}

autoit_instance get_autoit_instance(void) {
	std::unique_lock<std::shared_mutex> lock(mutex);
	if (pool.empty()) {
		autoit_instance new_instance;
		instances_count++;
		return new_instance;
	} else {
		autoit_instance old_instance = std::move(pool.front());
		pool.pop_front();
		return old_instance;
	}
}

void release_autoit_instance(autoit_instance&& released_instance) {
	std::unique_lock<std::shared_mutex> lock(mutex);
	if (pool.size() < max_pool_size) {
		pool.push_back(std::move(released_instance));
	} else {
		instances_count--;
	}
}

extern "C" {
	int __declspec(dllexport) __cdecl AU3Safe_max_pool_size(void) {
		return max_pool_size;
	}
	
	int __declspec(dllexport) __cdecl AU3Safe_instances_in_pool_count(void) {
		std::shared_lock<std::shared_mutex> lock(mutex);
		return pool.size();
	}
	
	int __declspec(dllexport) __cdecl AU3Safe_instances_count(void) {
		std::shared_lock<std::shared_mutex> lock(mutex);
		return instances_count;
	}
}
