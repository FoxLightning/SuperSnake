#pragma once
#include <list>
#include "ss_common.h"
#include "InputManager.h"
#include "ControlledObject.h"
#include "RenderableObject.h"
#include "PhysicalObject.h"

class Snake : public ControlledObject, public RenderableObject,
	public PhysicalObject
{
	std::list<ss_t::Vector2d<int>>	segments;
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

	std::list<BasePrimitive> get_render_objects();
	std::list<BasePrimitive> get_physical_objects();
	void set_direction(int);
	void increase_size(int);
	bool is_alive(ss_t::Vector2d<int>);

};

