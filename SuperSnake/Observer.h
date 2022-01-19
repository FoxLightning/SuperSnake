#pragma once
#include <list>
#include "Subscriber.h"
#include "BasePrimitive.h"

class Observer
{
	std::list<Subscriber*> subscribers_list;

public:
	virtual void add_subscriber(Subscriber*);
	virtual void remove_subscriber(Subscriber*);
	virtual std::list<BasePrimitive> get_primitives();
};

