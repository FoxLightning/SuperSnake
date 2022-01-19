#include "PhysicalProc.h"
#include "Subscriber.h"

int PhysicalProc::check_colision(ss_t::Vector2d<int> place, bool skip_head)
{
	ss_t::Vector2d<int> current_pos{ 0, 0 };
	std::list<ss_t::BasePrimitive> primitives_list = get_primitives();

	for (std::list<ss_t::BasePrimitive>::iterator primitives_it = primitives_list.begin();
		primitives_it != primitives_list.end(); ++primitives_it)
	{
		if (skip_head and primitives_it->type == ss_c::HEAD)
		{
			continue;
		}
		current_pos = primitives_it->position;
		if (current_pos.x == place.x and
			current_pos.y == place.y)
		{
			return primitives_it->type;
		}
	}
	return ss_c::NOTHING;
}

int PhysicalProc::check_colision(ss_t::Vector2d<int> place)
{
	return check_colision(place, false);
}

PhysicalProc* PhysicalProc::get_instance()
{
	std::lock_guard<std::mutex> lock(mutex_);
	if (physical_proc == NULL)
	{
		physical_proc  = new PhysicalProc();
	}
	return physical_proc;
}
