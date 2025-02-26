#pragma once
#include <cstdint>

template <typename RetT = void, typename... Args> RetT Call(uintptr_t address, Args... args) {

	typedef RetT func(Args...);
	func* function = (func*)address;

	return function(args...);
}