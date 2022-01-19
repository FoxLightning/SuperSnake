#include "RenderableObject.h"
#include "RenderProc.h"

RenderableObject::RenderableObject()
{
	/*
	* We subscribe to RenderProc so that it receives
	* all primitives for rendering from the current class 
	*/
	RenderProc *render_proc = RenderProc::get_instance();
	render_proc->add_subscriber(this);
}

RenderableObject::~RenderableObject()
{

	RenderProc *render_proc = RenderProc::get_instance();
	render_proc->remove_subscriber(this);
}

