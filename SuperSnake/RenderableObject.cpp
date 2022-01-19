#include "RenderableObject.h"
#include "RenderProc.h"

RenderableObject::RenderableObject()
{
	RenderProc *render_proc = RenderProc::get_instance();
	render_proc->add_subscriber(this);
}

RenderableObject::~RenderableObject()
{

	RenderProc *render_proc = RenderProc::get_instance();
	render_proc->add_subscriber(this);
}

