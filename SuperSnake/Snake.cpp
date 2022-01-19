#include "Snake.h"
#include "iostream"
#include "PhysicalProc.h"

void Snake::increase_size(int value)
{
	for (int i = 0; i < value; i++) {
		segments.push_back(ss_t::BasePrimitive{ss_t::Vector2d<int>{0, 0},
						   ss_c::TAIL});
	}
}

Snake::Snake(ss_t::Vector2d<int> start_position)
{
	input_manager = InputManager::get_instance();
	direction = ss_c::NORTH;
	segments.push_back(ss_t::BasePrimitive{ start_position, ss_c::HEAD });
	increase_size(5);
	size = segments.size();
}

void Snake::set_direction(int new_direction)
{
	switch (new_direction)
	{
	case ss_c::WEST:
		if (direction != ss_c::EAST)
		{
			direction = new_direction;
		}
		break;
	case ss_c::EAST:
		if (direction != ss_c::WEST)
		{
			direction = new_direction;
		}
		break;
	case ss_c::NORTH:
		if (direction != ss_c::SOUTH)
		{
			direction = new_direction;
		}
		break;
	case ss_c::SOUTH:
		if (direction != ss_c::NORTH)
		{
			direction = new_direction;
		}
		break;
	}
}

void Snake::get_input()
{
	switch (get_input_console())
	{
	case 'a':
		set_direction(ss_c::WEST);
		break;
	case 'd':
		set_direction(ss_c::EAST);
		break;
	case 'w':
		set_direction(ss_c::NORTH);
		break;
	case 's':
		set_direction(ss_c::SOUTH);
		break;
	}
}

void Snake::move_head()
{

	switch (direction)
	{
	case ss_c::WEST:
		segments.begin()->position.x--;
		break;
	case ss_c::EAST:
		segments.begin()->position.x++;
		break;
	case ss_c::NORTH:
		segments.begin()->position.y--;
		break;
	default:
		segments.begin()->position.y++;
		break;
	}
}

ss_t::Vector2d<int>	Snake::get_head()
{
	return segments.begin()->position;
}

void Snake::move_segments()
{
	ss_t::Vector2d<int> prev_pos = (segments.begin())->position;
	ss_t::Vector2d<int> tmp;
	
	for (std::list<ss_t::BasePrimitive>::iterator it = ++segments.begin();
		it != segments.end(); ++it)
	{
		tmp = it->position;
		it->position = prev_pos;
		prev_pos = tmp;
	}
}

void Snake::refresh_state()
{
	get_input();
	move_segments();
	move_head();
}

std::list<ss_t::BasePrimitive> Snake::get_primitives()
{
	return segments;
}
