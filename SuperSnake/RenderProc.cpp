#include "RenderProc.h"

RenderProc::RenderProc(ss_t::Vector2d<int> field_size)
{
	field_height = field_size.y;
	field_width = field_size.x;
	field_size_len = field_height * (field_width + 1);

	render_field = new char[field_size_len];
	clear_field();
}

RenderProc* RenderProc::get_instance()
{
	std::lock_guard<std::mutex> lock(mutex_);
	if (render_proc == NULL)
	{
		render_proc = new RenderProc(ss_t::Vector2d<int>{30, 30});
	}
	return render_proc;
}

inline int RenderProc::arrey_position(int x, int y)
{
	return y * (field_width + 1) + x;
}

RenderProc::~RenderProc()
{
	delete[] render_field;
}

static inline char get_image_type(int type)
{
	switch (type)
	{
	case ss_c::HEAD:
		return '@';
	case ss_c::TAIL:
		return 'X';
	case ss_c::APPLE:
		return 'O';
	case ss_c::BORDER:
		return '#';
	default:
		return '?';
	}
}

inline void RenderProc::fill_field()
{
	int							current_type = 0;
	ss_t::Vector2d<int>			current_pos{ 0, 0 };
	std::list<BasePrimitive>	primitives_list = get_primitives();

	for (std::list<BasePrimitive>::iterator primitives_it = primitives_list.begin();
		primitives_it != primitives_list.end(); ++primitives_it)
	{
		current_pos = primitives_it->get_position();
		current_type = get_image_type(primitives_it->get_type());
		render_field[arrey_position(current_pos.x, current_pos.y)] = current_type;
	}
}

inline void RenderProc::clear_field()
{
	for (int i = 0; i < field_size_len; i++)
	{
		render_field[i] = ' ';
	}
	for (int i = field_width; i < field_size_len; i += (field_width + 1))
	{
		render_field[i] = '\n';
	}
}

inline void RenderProc::fill_screen()
{
	std::cout << render_field;
}

inline void RenderProc::clear_screen()
{
	system("cls");
}

void RenderProc::render()
{
	clear_field();
	fill_field();
	clear_screen();
	fill_screen();
}

