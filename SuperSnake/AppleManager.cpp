#include "AppleManager.h"

AppleManager::AppleManager()
{
	add_apple();
}

std::list<ss_t::BasePrimitive> AppleManager::get_primitives()
{
	return apples;
}


void AppleManager::add_apple()
{
	PhysicalProc *physical_proc = PhysicalProc::get_instance();
	int rand_x = rand() % ss_c::FIELD_WIDTH;
	int rand_y = rand() % ss_c::FIELD_HEIGHT;
	ss_t::Vector2d<int> proposed_location{ rand_x, rand_y };


	while (ss_c::NOTHING != physical_proc->check_colision(proposed_location))
	{
		proposed_location.x++;
		if (proposed_location.x >= ss_c::FIELD_WIDTH)
		{
			proposed_location.x %= ss_c::FIELD_WIDTH;
			proposed_location.y++;
		}
		if (proposed_location.y >= ss_c::FIELD_HEIGHT)
		{
			proposed_location.y %= ss_c::FIELD_HEIGHT;
		}
	}
	apples.push_back(ss_t::BasePrimitive{ proposed_location, ss_c::APPLE });
}

void AppleManager::remove_apple(ss_t::Vector2d<int> apple_remove)
{
	apples.remove_if([&apple_remove](const ss_t::BasePrimitive& apple) {
		return apple_remove.x == apple.position.x and apple_remove.y == apple.position.y; });
}
