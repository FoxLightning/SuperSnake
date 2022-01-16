#pragma once
#include <list>
#include "ss_common.h"
#include "InputManager.h"

class Snake
{
	std::list<ss_t::Vector2d<int>>	segments;
	int								direction;
	int								size;
	InputManager					*input_manager;
	
	Snake();
public:
	Snake(ss_t::Vector2d<int> start_position);
	// ~Snake();
	
	void refresh_state();
	void get_input();
	void apply_direction();
	void move_segments();

	std::list<ss_t::Vector2d<int>> *get_draweble_objects();

	void set_direction(int);
	void increase_size(int);
	bool is_alive(ss_t::Vector2d<int>);

};

