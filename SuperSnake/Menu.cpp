#include "Menu.h"
#include <iostream>

Menu::Menu()
{
	position = ss_t::Vector2d<int>{ss_c::FIELD_WIDTH / 2 * 3,
								   ss_c::FIELD_HEIGHT / 2 * 3};
	options.push_back(std::string("Start"));
	options.push_back(std::string("Exit"));
	options_to_primitives();
}

void Menu::options_to_primitives()
{
	ss_t::Vector2d<int> cur_position = position;

	for (std::list<std::string>::iterator options_it = options.begin();
		options_it != options.end(); ++options_it)
	{
		for (std::string::iterator string_it = options_it->begin();
			string_it != options_it->end(); ++string_it)
		{
			primitives.push_back(ss_t::BasePrimitive{cur_position, *string_it});
			cur_position.x++;
		}
		cur_position.y++;
	}
}

std::list<ss_t::BasePrimitive> Menu::get_primitives()
{
	return primitives;
}

void Menu::run_menu()
{
	RenderProc *render_proc = RenderProc::get_instance();
	
	while (true)
	{
		render_proc->render();
		std::cout << primitives.size() << std::endl;
	}
}
