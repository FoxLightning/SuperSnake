#include "BorderManager.h"
#include <iostream>

BorderManager::BorderManager()
{
	/*
	* Create borders along the edges of the screen 
	*/
	for (int i = 0; i < ss_c::FIELD_WIDTH; ++i)
	{
		borders.push_back(ss_t::BasePrimitive{ ss_t::Vector2d<int>{i, 0}, ss_c::BORDER});
		borders.push_back(ss_t::BasePrimitive{ ss_t::Vector2d<int>{i, ss_c::FIELD_HEIGHT-1}, ss_c::BORDER});
	}

	for (int i = 0; i < ss_c::FIELD_WIDTH; ++i)
	{
		borders.push_back(ss_t::BasePrimitive{ ss_t::Vector2d<int>{0, i}, ss_c::BORDER});
		borders.push_back(ss_t::BasePrimitive{ ss_t::Vector2d<int>{ss_c::FIELD_WIDTH-1, i}, ss_c::BORDER});
	}
	std::cout << "asfdasdfasdfasdfasdf";
}

std::list<ss_t::BasePrimitive> BorderManager::get_primitives()
{
	return borders;
}
