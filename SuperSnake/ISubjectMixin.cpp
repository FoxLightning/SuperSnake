#include "ISubjectMixin.h"
#include "InputManager.h"


ISubjectMixin::ISubjectMixin()
{
	input = 0;
	InputManager* input_manager = InputManager::get_instance();
	input_manager->add_subject(this);
}

ISubjectMixin::~ISubjectMixin()
{
	InputManager* input_manager = InputManager::get_instance();
	input_manager->remove_subject(this);
}

char ISubjectMixin::get_input_m()
{
	return input;
}

void ISubjectMixin::set_input_m(char in_char)
{
	input = in_char;
}
