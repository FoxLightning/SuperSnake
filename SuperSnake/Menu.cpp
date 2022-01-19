#include "Menu.h"
#include <iostream>

#include <chrono>
#include <thread>

Menu::Menu()
{
	/*
	* position - where to start drawing the menu 
	*/
	position = ss_t::Vector2d<int>{ss_c::FIELD_WIDTH / 3 ,
								   ss_c::FIELD_HEIGHT / 3};
	options.push_back(std::string("Start"));
	options.push_back(std::string("Exit"));
	options_to_primitives();
}

void Menu::options_to_primitives()
{
	/*
	* Convert the list of strings that represents the menu options to a BasePrimitive
	* so that it can be rendered in RenderProc 
	*/
	ss_t::Vector2d<int> cur_position = position;
	ss_t::Vector2d<int> cur2_position = cur_position;

	for (std::list<std::string>::iterator options_it = options.begin();
		options_it != options.end(); ++options_it)
	{
		for (std::string::iterator string_it = options_it->begin();
			string_it != options_it->end(); ++string_it)
		{
			primitives.push_back(ss_t::BasePrimitive{cur2_position, *string_it});
			cur2_position.x++;
		}
		cur_position.y += 2;
		cur2_position = cur_position;
	}
}

void Menu::up_menu_pointer()
{
	menu_pointer--;
	menu_pointer %= options.size();
}

void Menu::down_menu_pointer()
{
	menu_pointer++;
	menu_pointer %= options.size();
}

ss_t::Vector2d<int> Menu::get_menu_pointer_position()
{
	return ss_t::Vector2d<int>{ss_c::FIELD_WIDTH / 3 - 2, ss_c::FIELD_HEIGHT / 3 + menu_pointer * 2};
}

std::list<ss_t::BasePrimitive> Menu::get_primitives()
{
	/*
	* the pointer is not in the list of primitives, 
	* create a BasePrimitive wich represent pointer and
	* add it before sending the primitives 
	*/
	std::list<ss_t::BasePrimitive> tmp_primitives = primitives;
	tmp_primitives.push_back(ss_t::BasePrimitive{get_menu_pointer_position(), ss_c::BORDER});
	return tmp_primitives;
}

void Menu::run_game()
{
	/*
	* Before starting the game, you need to unsubscribe from RenderProc
	* so that the primitives from the Menu are not displayed during the game.
	* Once completed, you need to renew your subscription
	*/
	RenderProc *render_proc = RenderProc::get_instance();
	render_proc->remove_subscriber(this);
	GameProc game_proc;
	game_proc.run_game();
	render_proc->add_subscriber(this);
}

void Menu::run_menu()
{
	RenderProc *render_proc = RenderProc::get_instance();

	/*
	* menu loop
	*/
	while (true)
	{
		render_proc->render();
		switch (get_input_console())
		{
		case 'w':
			up_menu_pointer();
			set_input_console(0);
			break;
		case 's':
			down_menu_pointer();
			set_input_console(0);
			break;
		case 'd':
			switch (menu_pointer)
			{
			case 0:
				run_game();
				break;
			case 1:
				return;
			}
			set_input_console(0);
		}
		
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
	}
}
