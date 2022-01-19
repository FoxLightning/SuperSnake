#pragma once
#include <list>
#include "ss_common.h"
#include "Subscriber.h"

class PhysicalObject: public Subscriber
{
	/*
	* It is an implementation of the Subscriber interface.
	* This is an abstract class that is needed to interact
	* with a concrete Observer - PhysicalProc 
	*/

public:
	PhysicalObject();
	~PhysicalObject();
};

