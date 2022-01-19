#pragma once
#include <list>
#include "BasePrimitive.h"
#include "Subscriber.h"

class RenderableObject: public Subscriber
{
public:
	RenderableObject();
	~RenderableObject();
};

