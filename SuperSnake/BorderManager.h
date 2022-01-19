#pragma once
#include <list>
#include "RenderableObject.h"
#include "PhysicalObject.h"
#include "ss_common.h"

class BorderManager:
	public RenderableObject,
	public PhysicalObject
{
	/*
	* A class that is designed to create and remove borders 
	* and store information about it. 
	*/
	std::list<ss_t::BasePrimitive> borders;
public:

	BorderManager();
	std::list<ss_t::BasePrimitive> get_primitives();
};

