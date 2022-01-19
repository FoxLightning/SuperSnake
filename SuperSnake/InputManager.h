#pragma once
#include <conio.h>
#include <thread>
#include <stdlib.h>
#include <list>
#include <mutex>
#include "ControlledObject.h"

class InputManager
{
	std::list<ControlledObject*> subject_list;
	inline static InputManager* input_manager;
	inline static std::mutex mutex_;

	InputManager();
public:
	static InputManager* get_instance();
	void add_subject(ControlledObject* subject);
	void remove_subject(ControlledObject* subject);
};
