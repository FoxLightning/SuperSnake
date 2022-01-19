#pragma once
#include <list>
#include "ss_common.h"
#include "InputManager.h"
#include "ControlledObject.h"
#include "RenderableObject.h"
#include "PhysicalObject.h"
#include "ss_common.h"

class Snake:
	public ControlledObject,
	public RenderableObject,
	public PhysicalObject
{
	/*
	* This class is responsible for controlling and moving the snake. 
	*/
	std::list<ss_t::BasePrimitive>	segments;
	int								direction;
	size_t							size;
	InputManager					*input_manager;
	
	Snake();

	void get_input();
	void move_head();
	void move_segments();
public:
	Snake(ss_t::Vector2d<int>);
	
	void refresh_state();

	std::list<ss_t::BasePrimitive> get_primitives();
	void set_direction(int);
	ss_t::Vector2d<int> get_head();
	void increase_size(int);
};

