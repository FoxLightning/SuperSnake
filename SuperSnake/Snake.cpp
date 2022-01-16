#include "Snake.h"
#include "iostream"

void Snake::increase_size(int value)
{
	for (int i = 0; i < value; i++) {
		segments.push_back(ss_t::Vector2d<int>{1+ i, 1+ i});
	}
}

Snake::Snake(ss_t::Vector2d<int> start_position)
{
	input_manager = InputManager::get_instance();
	direction = ss_c::NORTH;
	segments.push_back(start_position);
	increase_size(5);
	size = segments.size();
	std::cout << size << std::endl;
}

void Snake::set_direction(int new_direction)
{
	direction = direction == ss_c::WEST ? direction : ss_c::EAST;
}

void Snake::get_input()
{
	switch (input_manager->get_key())
	{
	case 'a':
		direction = (direction == ss_c::EAST) ? direction : ss_c::WEST;
		direction = ss_c::WEST;
		break;
	case 'd':
		direction = (direction == ss_c::WEST) ? direction : ss_c::EAST;
		break;
	case 'w':
		direction = (direction == ss_c::SOUTH) ? direction : ss_c::NORTH;
		break;
	case 's':
		direction = (direction == ss_c::NORTH) ? direction : ss_c::SOUTH;
		break;
	}
}

void Snake::apply_direction()
{
	switch (direction)
	{
	case ss_c::WEST:
		segments.begin()->x--;
		break;
	case ss_c::EAST:
		segments.begin()->x++;
		break;
	case ss_c::NORTH:
		segments.begin()->y--;
		break;
	default:
		segments.begin()->y++;
		break;
	}
}

void Snake::move_segments()
{
	ss_t::Vector2d<int> prev_pos = *segments.begin();
	ss_t::Vector2d<int> tmp;
	
	for (std::list<ss_t::Vector2d<int>>::iterator it = ++segments.begin();
		it != segments.end(); ++it)
	{
		tmp = *it;
		*it = prev_pos;
		prev_pos = tmp;
	}
}

void Snake::refresh_state()
{
	// get_input();
	// apply_direction();
	move_segments();
}

bool Snake::is_alive(ss_t::Vector2d<int> borders)
{
	for (std::list<ss_t::Vector2d<int>>::iterator it = ++segments.begin();
		it != segments.end(); ++it)
	{
		if (segments.begin()->x == it->x &&
			segments.begin()->y == it->y)
		{
			return false;
		}
	}

	if (segments.begin()->x < 1 or segments.begin()->y < 1 or
		segments.begin()->x >= borders.x - 2 or segments.begin()->y >= borders.y - 2)
	{
		return false;
	}
	return true;
}

std::list<ss_t::Vector2d<int>> *Snake::get_draweble_objects()
{
	return &segments;
}

