#pragma once
#include <cstdint>

/*
* Calls a memory address in the form of a function
*/
template <typename RetT, typename... Args> RetT Call(uintptr_t address, Args... args) {

	typedef RetT func(Args...);
	func* function = (func*)address;

	return function(args...);
}