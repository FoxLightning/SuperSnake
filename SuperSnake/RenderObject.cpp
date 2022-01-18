#include "RenderObject.h"


RenderObject::RenderObject(ss_t::Vector2d<int> in_position, char in_type)
{
	position = in_position;
	type = in_type;

}

ss_t::Vector2d<int> RenderObject::get_position()
{
	return position;
}

int RenderObject::get_type()
{
	return type;
}
