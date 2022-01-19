#pragma once
#include <string>
#include "ControlledObject.h"
#include "RenderableObject.h"
#include "RenderProc.h"
#include "ss_common.h"

class Menu:
	public ControlledObject,
	public RenderableObject
{
	ss_t::Vector2d<int> position;
	std::list<ss_t::BasePrimitive> primitives;
	std::list<std::string> options;

	void options_to_primitives();
public:
	Menu();
	void run_menu();
	virtual std::list<ss_t::BasePrimitive> get_primitives();
};

