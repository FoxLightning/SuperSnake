#include "Snake.h"
#include "iostream"
#include "BasePrimitive.h"
#include "PhysicalProc.h"

void Snake::increase_size(int value)
{
	for (int i = 0; i < value; i++) {
		segments.push_back(ss_t::Vector2d<int>{2, 2});
	}
}

Snake::Snake(ss_t::Vector2d<int> start_position)
{
	input_manager = InputManager::get_instance();
	direction = ss_c::NORTH;
	segments.push_back(start_position);
	increase_size(5);
	size = segments.size();
	PhysicalProc* po = PhysicalProc::get_instance();
	po->add_head(&(* segments.begin()));
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
	switch (get_input_m())
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
	get_input();
	move_segments();
	move_head();
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

std::list<BasePrimitive> Snake::get_render_objects()
{
	std::list<BasePrimitive> render_objects;

	render_objects.push_back(BasePrimitive(*segments.begin(), ss_c::HEAD));
	for (std::list<ss_t::Vector2d<int>>::iterator it = ++segments.begin();
		it != segments.end(); ++it)
	{
		render_objects.push_back(BasePrimitive(*it, ss_c::TAIL));
	}
	return render_objects;
}

std::list<BasePrimitive> Snake::get_physical_objects()
{
	std::list<BasePrimitive> render_objects;

	render_objects.push_back(BasePrimitive(*segments.begin(), ss_c::HEAD));
	for (std::list<ss_t::Vector2d<int>>::iterator it = ++segments.begin();
		it != segments.end(); ++it)
	{
		render_objects.push_back(BasePrimitive(*it, ss_c::TAIL));
	}
	return render_objects;
}
