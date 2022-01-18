#pragma once
#include <list>
#include "RenderObject.h"

class Render_Mixin
{
public:
	Render_Mixin();
	~Render_Mixin();
	virtual std::list<RenderObject> get_render_objects() = 0;
};

