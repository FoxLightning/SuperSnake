#pragma once
#include <list>
#include "BasePrimitive.h"

class PhysicalObject
{

public:
	PhysicalObject();
	~PhysicalObject();
	virtual std::list<BasePrimitive> get_physical_objects() = 0;
};

