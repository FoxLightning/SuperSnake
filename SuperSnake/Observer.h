#pragma once
#include <list>
#include "Subscriber.h"

class Observer
{
	std::list<Subscriber*> subscribers_list;

public:
	void add_subscriber(Subscriber*);
	void remove_subscriber(Subscriber*);
};

