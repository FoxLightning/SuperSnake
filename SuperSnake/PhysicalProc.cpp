#include "PhysicalProc.h"
#include "Subscriber.h"

int PhysicalProc::check_colision()
{
	ss_t::Vector2d<int> current_pos{ 0, 0 };
	ss_t::Vector2d<int> head_pos{0, 0};
	std::list<BasePrimitive> primitives_list = get_primitives();

	for (std::list<BasePrimitive>::iterator primitives_it = primitives_list.begin();
		primitives_it != primitives_list.end(); ++primitives_it)
	{
		if (primitives_it->get_type() == ss_c::HEAD)
		{
			head_pos = primitives_it->get_position();
		}

	}

	for (std::list<BasePrimitive>::iterator primitives_it = primitives_list.begin();
		primitives_it != primitives_list.end(); ++primitives_it)
	{
		current_pos = primitives_it->get_position();
		if (current_pos.x == head_pos.x and
			current_pos.y == head_pos.y)
		{
			switch (primitives_it->get_type())
			{
			case ss_c::BORDER:
				return ss_c::GAME_OVER;
			case ss_c::TAIL:
				return ss_c::GAME_OVER;
			case ss_c::APPLE:
				return ss_c::INCREASE_SCORE;
			}
		}
	}
	return ss_c::NOTHING;
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
