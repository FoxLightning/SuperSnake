#include "InputManager.h"

InputManager::InputManager()
{
	std::thread	input([this]() {
		char in_key = '\0';
		while (true)
		{
			in_key = (char)_getch();

			for (std::list<ISubjectMixin*>::iterator it = this->subject_list.begin();
				it != this->subject_list.end(); ++it)
			{
				(*it)->set_input_m(in_key);
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

void InputManager::add_subject(ISubjectMixin* subject)
{
	subject_list.push_back(subject);
}

void InputManager::remove_subject(ISubjectMixin* subject)
{
	subject_list.remove(subject);
}
