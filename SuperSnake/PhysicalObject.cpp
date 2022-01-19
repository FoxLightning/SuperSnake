#include "PhysicalObject.h"
#include "PhysicalProc.h"

PhysicalObject::PhysicalObject()
{
	PhysicalProc* physical_proc = PhysicalProc::get_instance();
	physical_proc->add_physical_object(this);
}

PhysicalObject::~PhysicalObject()
{
	PhysicalProc* physical_proc = PhysicalProc::get_instance();
	physical_proc->remove_physical_object(this);
}
