#pragma once
#include "autoit_instance.hpp"
#include "pool.hpp"

template <typename Result, typename... Args>
Result autoit_function(Result (autoit_instance::*function)(Args...) const, Args... args) {
	autoit_instance instance = std::move(get_autoit_instance());
	Result result = (instance.*function)(args...);
	release_autoit_instance(std::move(instance));
	return result;
}
