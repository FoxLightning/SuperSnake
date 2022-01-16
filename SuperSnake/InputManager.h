#pragma once
#include <conio.h>
#include <thread>
#include <stdlib.h>

class InputManager
{
	char in_key;
	inline static InputManager* input_manager;
	InputManager();
	InputManager(InputManager&) = delete;
	void operator=(const InputManager&) = delete;
public:
	char get_key();
	static InputManager* get_instance();
};
