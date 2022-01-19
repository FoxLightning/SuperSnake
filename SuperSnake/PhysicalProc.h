#pragma once
#include <list>
#include <mutex>
#include "PhysicalObject.h"
#include "BasePrimitive.h"
#include "Observer.h"
#include "ss_common.h"

class PhysicalProc: public Observer
{
	inline static PhysicalProc* physical_proc;
	inline static std::mutex mutex_;

	PhysicalProc() {};

public:
	static PhysicalProc* get_instance();
	int check_colision();
};

