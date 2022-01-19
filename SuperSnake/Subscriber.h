#pragma once
#include <list>
#include "BasePrimitive.h"

class Subscriber
{
public:
	Subscriber();
	~Subscriber();
	virtual std::list<BasePrimitive> get_primitives();
};

