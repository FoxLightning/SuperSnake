#pragma once
#include <list>
#include <mutex>
#include "PhysicalObject.h"
#include "BasePrimitive.h"
#include "ss_common.h"

class PhysicalProc 
{
	std::list<PhysicalObject*> physical_objects;

	inline static PhysicalProc* physical_proc;
	inline static std::mutex mutex_;

	PhysicalProc() {};
public:

	ss_t::Vector2d<int> *head;
	static PhysicalProc* get_instance();
	void add_physical_object(PhysicalObject*);
	void add_head(ss_t::Vector2d<int> *);
	void remove_physical_object(PhysicalObject*);
	int check_colision();
};

