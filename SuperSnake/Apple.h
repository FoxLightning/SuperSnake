#pragma once
#include <ctime>
#include "ss_common.h"

class Apple
{
	ss_t::Vector2d<int> position;
	char				image;
	int					estimate;
	time_t				birthday;
	Apple();
public:
	Apple(ss_t::Vector2d<int>, int, int);
	ss_t::Vector2d<int> get_position();
	char get_image();
};

