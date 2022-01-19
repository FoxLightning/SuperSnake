#include "InputManager.h"

InputManager::InputManager()
{
	std::thread	input([this]() {
		char in_key = '\0';
		while (true)
		{
			in_key = (char)_getch();

			for (std::list<ControlledObject*>::iterator it = this->subject_list.begin();
				it != this->subject_list.end(); ++it)
			{
				(*it)->set_input_console(in_key);
			}
		}
	});
	input.detach();
}

InputManager* InputManager::get_instance()
{
	std::lock_guard<std::mutex> lock(mutex_);
	if (input_manager == NULL)
	{
		input_manager = new InputManager();
	}
	return input_manager;
}

void InputManager::add_subscriber(ControlledObject* subscriber)
{
	subject_list.push_back(subscriber);
}

void InputManager::remove_subscriber(ControlledObject* subscriber)
{
	subject_list.remove(subscriber);
}
