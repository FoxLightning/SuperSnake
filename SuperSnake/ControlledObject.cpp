#include "ControlledObject.h"
#include "InputManager.h"


ControlledObject::ControlledObject()
{
	input = 0;
	InputManager* input_manager = InputManager::get_instance();
	input_manager->add_subject(this);
}

ControlledObject::~ControlledObject()
{
	InputManager* input_manager = InputManager::get_instance();
	input_manager->remove_subject(this);
}

char ControlledObject::get_input_m()
{
	return input;
}

void ControlledObject::set_input_m(char in_char)
{
	input = in_char;
}
