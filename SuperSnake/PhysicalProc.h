#pragma once
#include <list>
#include <mutex>
#include "RenderObject.h"
#include "PhysicalObject.h"

enum colision_cases {
	NOTHING = 0,
	GAME_OVER,
	INCREASE_SCORE,
};

class PhysicalProc 
{
	std::list<PhysicalObject*> physical_objects;

	inline static PhysicalProc* logic_proc;
	inline static std::mutex mutex_;

	PhysicalProc();
public:

	int check_colision();
};

