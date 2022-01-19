#pragma once
#include <list>
#include "Observer.h"
#include "BasePrimitive.h"

class Subscriber
{
public:
	virtual std::list<BasePrimitive> get_primitives() = 0;
};

