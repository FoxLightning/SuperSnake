#include "Observer.h"


void Observer::add_subscriber(Subscriber* subscriber)
{
	subscribers_list.push_back(subscriber);
}

void Observer::remove_subscriber(Subscriber* subscriber)
{
	subscribers_list.remove(subscriber);
}

std::list<ss_t::BasePrimitive> Observer::get_primitives()
{
	/*
	* gethering primitives from all subscribers 
	*/
	std::list<ss_t::BasePrimitive>	current_primitives_list;
	std::list<ss_t::BasePrimitive>	final_primitives_list;

	for (std::list<Subscriber*>::iterator subscribers_it = subscribers_list.begin();
		subscribers_it != subscribers_list.end(); ++subscribers_it)
	{
		current_primitives_list = (*subscribers_it)->get_primitives();

		for (std::list<ss_t::BasePrimitive>::iterator primitives_it = current_primitives_list.begin();
			primitives_it  != current_primitives_list.end(); ++primitives_it)
		{
			final_primitives_list.push_back(*primitives_it);
		}
	}
	return final_primitives_list;
}

