#include "InputManager.h"

InputManager::InputManager()
{
	in_key = 0;
	std::thread	input([this]() {
		while (true)
		{
			this->in_key = _getch();
		}
	});
	input.detach();
}

char InputManager::get_key()
{
	return in_key;
}


InputManager* InputManager::get_instance()
{
	if (input_manager == NULL)
	{
		input_manager = new InputManager();
	}
	return input_manager;
}

