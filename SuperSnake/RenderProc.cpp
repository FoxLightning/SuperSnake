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

RenderProc::~RenderProc()
{
	delete[] render_field;
}

void RenderProc::add_render_subject(Render_Mixin* render_subject)
{
	render_subjects.push_back(render_subject);
}

void RenderProc::remove_render_subject(Render_Mixin* render_subject)
{
	render_subjects.remove(render_subject);
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
	ss_t::Vector2d<int> current_pos{ 0, 0 };
	int	current_type = 0;
	std::list<RenderObject> render_objects;

	for (std::list<Render_Mixin*>::iterator render_mixin_it = render_subjects.begin();
		render_mixin_it != render_subjects.end(); ++render_mixin_it)
	{
		render_objects = (*render_mixin_it)->get_render_objects();

		for (std::list<RenderObject>::iterator render_objects_it = render_objects.begin();
			render_objects_it != render_objects.end(); ++render_objects_it)
		{
			current_pos = render_objects_it->get_position();
			current_type = get_image_type(render_objects_it->get_type());
			render_field[current_pos.y * (field_width+1) + current_pos.x] = current_type;
		}
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

