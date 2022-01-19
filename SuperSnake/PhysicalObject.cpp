#include "PhysicalObject.h"
#include "PhysicalProc.h"
#include <iostream>


PhysicalObject::PhysicalObject()
{
	PhysicalProc* physical_proc = PhysicalProc::get_instance();
	physical_proc->add_subscriber(this);
	std::cout << "Phys create" << std::endl;
}

PhysicalObject::~PhysicalObject()
{
	PhysicalProc* physical_proc = PhysicalProc::get_instance();
	physical_proc->remove_subscriber(this);
}

