#include <ctime>

#include "Apple.h"


Apple::Apple(ss_t::Vector2d<int> in_position, int in_image, int in_estimate)
{
	position = in_position;
	image = in_image;
	estimate = in_estimate;
	birthday = time(NULL);
}


ss_t::Vector2d<int> Apple::get_position()
{
	return position;
}


char Apple::get_image()
{
	return image;
}
