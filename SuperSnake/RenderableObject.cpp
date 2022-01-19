#include "RenderableObject.h"
#include "RenderProc.h"

RenderableObject::RenderableObject()
{
	RenderProc *render_proc = RenderProc::get_instance();
	render_proc->add_render_subject(this);
}

RenderableObject::~RenderableObject()
{

	RenderProc *render_proc = RenderProc::get_instance();
	render_proc->remove_render_subject(this);
}

