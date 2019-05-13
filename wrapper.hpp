#pragma once
#include <iostream>
#include "autoit_instance.hpp"
#include "pool.hpp"

// had no time to do proper specialization/overloading

template <typename...Args>
void void_autoit_function(void (autoit_instance::*function)(Args...) const, Args... args) {
	autoit_instance instance = std::move(get_autoit_instance());
	(instance.*function)(args...);
	release_autoit_instance(std::move(instance));
}

template <typename Result, typename... Args>
Result autoit_function(Result (autoit_instance::*function)(Args...) const, Args... args) {
	autoit_instance instance = std::move(get_autoit_instance());
	Result result = (instance.*function)(args...);
	release_autoit_instance(std::move(instance));
	return result;
}
