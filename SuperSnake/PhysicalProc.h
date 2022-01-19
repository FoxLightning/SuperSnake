#pragma once
#include <list>
#include <mutex>
#include "PhysicalObject.h"
#include "Observer.h"
#include "ss_common.h"

class PhysicalProc: public Observer
{
	/*
	* Observer implementation - which essentially just checks
	* for collisions and iterates over the Base objects of
	* all subscribers 
	*/
	inline static PhysicalProc* physical_proc;
	inline static std::mutex mutex_;

	PhysicalProc() {};
	
public:
	static PhysicalProc* get_instance();
	int check_colision(ss_t::Vector2d<int>, bool);
	int check_colision(ss_t::Vector2d<int>);
};

