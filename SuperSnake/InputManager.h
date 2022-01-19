#pragma once
#include <conio.h>
#include <thread>
#include <stdlib.h>
#include <list>
#include <mutex>
#include "ControlledObject.h"

class InputManager
{
	/*
	* This is an implementation of the observer pattern.
	* The class sends all subscribers information about
	* the input to the console.
	* Used in conjunction with class ControlledObject
	*/
	std::list<ControlledObject*> subject_list;
	inline static InputManager* input_manager;
	inline static std::mutex mutex_;

	InputManager();
public:
	static InputManager* get_instance();
	void add_subscriber(ControlledObject* subject);
	void remove_subscriber(ControlledObject* subject);
};
