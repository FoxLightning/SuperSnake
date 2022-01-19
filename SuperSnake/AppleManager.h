#pragma once
#include <list>
#include "RenderableObject.h"
#include "PhysicalObject.h"
#include "ss_common.h"
#include "PhysicalProc.h"

class AppleManager:
	public RenderableObject,
	public PhysicalObject
{
	/*
	* A class that is designed to create and remove apples
	* and store information about it. 
	*/
	std::list<ss_t::BasePrimitive> apples;
public:
	AppleManager();
	std::list<ss_t::BasePrimitive> get_primitives();
	void add_apple();
	void remove_apple(ss_t::Vector2d<int>);
};

