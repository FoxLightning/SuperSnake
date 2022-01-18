#include "Render_Mixin.h"
#include "RenderProc.h"

Render_Mixin::Render_Mixin()
{
	RenderProc *render_proc = RenderProc::get_instance();
	render_proc->add_render_subject(this);
}

Render_Mixin::~Render_Mixin()
{

	RenderProc *render_proc = RenderProc::get_instance();
	render_proc->add_render_subject(this);
}

