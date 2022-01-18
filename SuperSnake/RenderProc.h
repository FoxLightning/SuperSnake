#pragma once
#include <iostream>
#include "RenderObject.h"
#include "Render_Mixin.h"
#include "ss_common.h"
#include <list>
#include <mutex>

class RenderProc
{
	std::list<Render_Mixin*> render_subjects;
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
	
	RenderProc(ss_t::Vector2d<int>);
public:
	~RenderProc();

	static RenderProc *get_instance();
	void add_render_subject(Render_Mixin*);
	void remove_render_subject(Render_Mixin*);
	void render();
};

