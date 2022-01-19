#include "ControlledObject.h"
#include "InputManager.h"


ControlledObject::ControlledObject()
{
	/*
	* Add yourself to the list of subscribers 
	*/
	input = 0;
	InputManager* input_manager = InputManager::get_instance();
	input_manager->add_subscriber(this);
}

ControlledObject::~ControlledObject()
{
	/*
	* Remove yourself from the list of subscribers 
	*/
	InputManager* input_manager = InputManager::get_instance();
	input_manager->remove_subscriber(this);
}

char ControlledObject::get_input_console()
{
	return input;
}

void ControlledObject::set_input_console(char in_char)
{
	input = in_char;
}
