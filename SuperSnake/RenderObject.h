#pragma once
#include "ss_common.h"
class RenderObject
{
	ss_t::Vector2d<int> position;
	unsigned int type;
public:
	RenderObject(ss_t::Vector2d<int>, char);
	ss_t::Vector2d<int> get_position();
	char get_type();
};

