#pragma once
#include <iostream>
#include "RenderableObject.h"
#include "Observer.h"
#include "ss_common.h"
#include <list>
#include <mutex>

class RenderProc: public Observer
{
	/*
	* This class iterates over the base
	* objects of all subscribers and contains
	* the logic for rendering the scene 
	*/

	char *render_field;
	int field_height;
	int field_width;
	int	field_size_len;

	inline static RenderProc* render_proc;
	inline static std::mutex mutex_;

	void fill_screen();
	void clear_screen();
	void clear_field();
	void fill_field();
	int arrey_position(int, int);
	RenderProc(ss_t::Vector2d<int>);

public:
	~RenderProc();
	static RenderProc *get_instance();
	void render();
};

