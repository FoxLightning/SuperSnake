#pragma once
#include <string>

#include "GameProc.h"
#include "ControlledObject.h"
#include "RenderableObject.h"
#include "RenderProc.h"
#include "ss_common.h"

class Menu:
	/*
	* The class representing the menu 
	*/
	public ControlledObject,
	public RenderableObject
{
	ss_t::Vector2d<int> position;
	int	menu_pointer;
	std::list<ss_t::BasePrimitive> primitives;
	std::list<std::string> options;

	void options_to_primitives();
	void up_menu_pointer();
	void down_menu_pointer();
	ss_t::Vector2d<int> get_menu_pointer_position();
	void run_game();
public:
	Menu();
	void run_menu();
	virtual std::list<ss_t::BasePrimitive> get_primitives();
};

