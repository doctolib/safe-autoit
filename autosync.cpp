#include <windows.h>
#include <mutex>
#include <deque>
#include <memory>

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
	pool.push_back(std::move(released_instance));
}

template <typename Result, typename... Args>
Result autoit_function(Result (autoit_instance::*function)(Args...) const, Args... args) {
	autoit_instance instance = std::move(get_autoit_instance());
	Result result = (instance.*function)(args...);
	release_autoit_instance(std::move(instance));
	return result;
}

