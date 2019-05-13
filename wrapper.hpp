#pragma once
#include <iostream>
#include "autoit_instance.hpp"
#include "pool.hpp"

template <typename...Args>
void void_autoit_function(void (autoit_instance::*function)(Args...) const, Args... args) {
	std::cout << "calling void function" << std::endl;
	autoit_instance instance = std::move(get_autoit_instance());
	std::cout << "got autoit instance" << std::endl;
	(instance.*function)(args...);
	release_autoit_instance(std::move(instance));
	std::cout << "released autoit instance" << std::endl;
}

template <typename Result, typename... Args>
Result autoit_function(Result (autoit_instance::*function)(Args...) const, Args... args) {
	autoit_instance instance = std::move(get_autoit_instance());
	Result result = (instance.*function)(args...);
	release_autoit_instance(std::move(instance));
	return result;
}
