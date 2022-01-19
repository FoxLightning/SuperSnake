#pragma once
#include <list>
#include "ss_common.h"

class Subscriber
{
	/*
	* This interface is required to interact with
	* the implementation of the Observer class. 
	*/
public:
	virtual std::list<ss_t::BasePrimitive> get_primitives() = 0;
};

