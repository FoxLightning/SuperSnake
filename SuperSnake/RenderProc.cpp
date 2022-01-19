#include "RenderProc.h"

RenderProc::RenderProc(ss_t::Vector2d<int> field_size)
{
	/*
	* We create a string in the style of C, which we then display on the screen.
	* We add an additional character to each line so that we can insert \n there later 
	*/
	field_height = field_size.y;
	field_width = field_size.x;
	field_size_len = field_height * (field_width + 1);

	render_field = new char[field_size_len];
	clear_field();
}

RenderProc* RenderProc::get_instance()
{
	/*
	* singlton realisation
	*/
	std::lock_guard<std::mutex> lock(mutex_);
	if (render_proc == NULL)
	{
		render_proc = new RenderProc(ss_t::Vector2d<int>{ss_c::FIELD_WIDTH, ss_c::FIELD_HEIGHT});
	}
	return render_proc;
}

inline int RenderProc::arrey_position(int x, int y)
{
	/*
	* Converter from 2d array coordinates to 1d 
	*/
	return y * (field_width + 1) + x;
}

RenderProc::~RenderProc()
{
	delete[] render_field;
}

static inline char get_image_type(int type)
{
	/*
	* Select a character to display the type.
	* If the symbol is not found, it is most likely a string 
	*/
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
		return type;
	}
}

void RenderProc::fill_field()
{
	/*
	* Filling the field with primitives 
	*/
	char current_type = 0;
	ss_t::Vector2d<int>				current_pos{ 0, 0 };
	std::list<ss_t::BasePrimitive>	primitives_list = get_primitives();

	for (std::list<ss_t::BasePrimitive>::iterator primitives_it = primitives_list.begin();
		primitives_it != primitives_list.end(); ++primitives_it)
	{
		current_pos = primitives_it->position;
		current_type = get_image_type(primitives_it->type);
		std::cout << current_type << std::endl;
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
	render_field[arrey_position(field_width - 1, field_height - 1)] = '\0';
}

inline void RenderProc::fill_screen()
{
	/*
	* output the field to the console 
	*/
	std::cout << render_field << std::endl;;
}

inline void RenderProc::clear_screen()
{
	/*
	* claer console 
	*/
	system("cls");
}

void RenderProc::render()
{
	/*
	* order is optimal. There must be a minimum amount of
	* time between clear_screen and fill_screen.
	* The rest of the options don't work. 
	*/
	clear_field();
	fill_field();
	clear_screen();
	fill_screen();
}

