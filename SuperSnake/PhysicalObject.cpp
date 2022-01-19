#include "PhysicalObject.h"
#include "PhysicalProc.h"
#include <iostream>


PhysicalObject::PhysicalObject()
{
	/*
	* We add ourselves to the list of subscribers so that PhysicalProc can
	* take into account collisions of primitives of the current class 
	*/
	PhysicalProc* physical_proc = PhysicalProc::get_instance();
	physical_proc->add_subscriber(this);
	std::cout << "Phys create" << std::endl;
}

PhysicalObject::~PhysicalObject()
{
	PhysicalProc* physical_proc = PhysicalProc::get_instance();
	physical_proc->remove_subscriber(this);
}

