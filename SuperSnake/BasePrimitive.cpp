#include "BasePrimitive.h"


BasePrimitive::BasePrimitive(ss_t::Vector2d<int> in_position, char in_type)
{
	position = in_position;
	type = in_type;

}

ss_t::Vector2d<int> BasePrimitive::get_position()
{
	return position;
}

int BasePrimitive::get_type()
{
	return type;
}
