#pragma once
#include <list>
#include "ss_common.h"
#include "InputManager.h"
#include "ISubjectMixin.h"
#include "Render_Mixin.h"

class Snake : public ISubjectMixin, public Render_Mixin
{
	std::list<ss_t::Vector2d<int>>	segments;
	int								direction;
	int								size;
	InputManager					*input_manager;
	
	Snake();

	void get_input();
	void move_head();
	void move_segments();
public:
	Snake(ss_t::Vector2d<int>);
	
	void refresh_state();

	std::list<RenderObject> get_render_objects();

	void set_direction(int);
	void increase_size(int);
	bool is_alive(ss_t::Vector2d<int>);

};

