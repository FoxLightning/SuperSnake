#pragma once
#include <list>
#include "Subscriber.h"
#include "ss_common.h"

class Observer
{
	/*
	* This mixin makes the class an observer. Since the logic of this
	* particular observer was repeated, it was decided to move it to a separate class.
	* Works with interface Subscriber
	*/
	std::list<Subscriber*> subscribers_list;

public:
	virtual void add_subscriber(Subscriber*);
	virtual void remove_subscriber(Subscriber*);
	virtual std::list<ss_t::BasePrimitive> get_primitives();
};

