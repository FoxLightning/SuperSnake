#include "PhysicalProc.h"

int PhysicalProc::check_colision()
{
	ss_t::Vector2d<int> current_pos{ 0, 0 };
	ss_t::Vector2d<int> head_pos = *head;
	std::list<BasePrimitive> cur_primitives_list;

	if (head->x < 1 or head->y < 1 or
		head->x >= 30 or head->y >= 30)
	{
		return ss_c::GAME_OVER;
	}

	for (std::list<PhysicalObject*>::iterator physical_objects_it = physical_objects.begin();
		physical_objects_it != physical_objects.end(); physical_objects_it++)
	{
		cur_primitives_list = (*physical_objects_it)->get_physical_objects();

		for (std::list<BasePrimitive>::iterator render_objects_it = cur_primitives_list.begin();
			render_objects_it != cur_primitives_list.end(); ++render_objects_it)
		{
			current_pos = render_objects_it->get_position();
			if (current_pos.x == head_pos.x and
				current_pos.y == head_pos.y)
			{
				switch (render_objects_it->get_type())
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

void PhysicalProc::add_physical_object(PhysicalObject *physical_object)
{
	physical_objects.push_back(physical_object);
}


void PhysicalProc::remove_physical_object(PhysicalObject *physical_object)
{
	physical_objects.remove(physical_object);
}

void PhysicalProc::add_head(ss_t::Vector2d<int> *in_head)
{
	head = in_head;
}
