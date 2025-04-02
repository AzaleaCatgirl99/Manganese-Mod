#pragma once
#include <cstdint>
#include "Utils/HookHelperExtension.h"

/*
* Calls a memory address in the form of a function
*/
template <typename RetT, typename... Args> RetT Call(size_t address, Args... args) {

	typedef RetT func(Args...);
	func* function = (func*)address;

	return function(args...);
}

template <uintptr_t Addr, typename RetT, typename... Args> RetT CALL_FUNC(Args... args) {

	typedef RetT func(Args...);
	func* function = (func*)GET_ADDRESS(Addr);

	return function(args...);
}

// Thanks to @SkyForces for help on this function
template <typename RetT, off_t Offset, typename... Args> RetT CALL_VTABLE_FUNC(void* objPtr, Args... args) {
	uintptr_t vPtr{ *static_cast<uintptr_t*>(objPtr) };
	vPtr = *reinterpret_cast<uintptr_t*>(vPtr + Offset);

	return (reinterpret_cast<RetT(*)(void*, Args...)>(vPtr))(objPtr, args...);
}