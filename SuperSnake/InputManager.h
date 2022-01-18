#pragma once
#include <conio.h>
#include <thread>
#include <stdlib.h>
#include <list>
#include <mutex>
#include "ISubjectMixin.h"

class InputManager
{
	std::list<ISubjectMixin*> subject_list;
	inline static InputManager* input_manager;
	inline static std::mutex mutex_;

	InputManager();
	InputManager(InputManager&) = delete;
	void operator=(const InputManager&) = delete;
public:
	static InputManager* get_instance();
	void add_subject(ISubjectMixin* subject);
	void remove_subject(ISubjectMixin* subject);
};
