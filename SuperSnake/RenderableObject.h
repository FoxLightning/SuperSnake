#pragma once
#include <list>
#include "BasePrimitive.h"

class RenderableObject
{
public:
	RenderableObject();
	~RenderableObject();
	virtual std::list<BasePrimitive> get_render_objects() = 0;
};

