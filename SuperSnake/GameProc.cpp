#include "GameProc.h"
#include "RenderProc.h"

static bool in_list(std::list<ss_t::Vector2d<int>> *list, ss_t::Vector2d<int> value) {
	for (std::list<ss_t::Vector2d<int>>::iterator it = list->begin(); it != list->end(); ++it)
	{
		if (it->x == value.x && it->y == value.y)
		{
			return true;
		}
	}
	return false;
}

/*
static Apple apple_builder(Snake &snake, ss_t::Vector2d<int> field_size)
{
	ss_t::Vector2d<int> position{
		rand() % field_size.x,
		rand() % field_size.y
	};
	
	while (in_list(snake.get_draweble_objects(), position))
	{
		if (position.x >= field_size.x)
		{
			position.x = 0;
			position.y++;
			if (position.y >= field_size.y)
			{
				position.y = 0;
			}
		}
		position.x++;
	}

	
	return Apple(position, '0', 10000);
}
*/
GameProc::GameProc()
{
	field_size = ss_t::Vector2d<int>{ 30, 30 };
	input_manager = InputManager::get_instance();

}

void GameProc::run_game()
{

	Snake snake(ss_t::Vector2d<int>{15, 15});
	RenderProc* render_proc = RenderProc::get_instance();
	while (true)
	{
		snake.refresh_state();
		render_proc->render();
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}

	// Apple apple = apple_builder(snake, field_size);
	/*
	int score = 0;
	ss_t::Vector2d<int> render_cur{0,0};
	while (true)
	{


		for (int y = 0; y < field_size.y; y++)
		{
			render_cur.y = y;
			for (int x = 0; x < field_size.x; x++)
			{
				render_cur.x = x;
				if (y == 0 or y == field_size.y - 1 or
					x == 0 or x == field_size.x - 1)
				{
					std::cout << " #";
				}
				else if (in_list(snake.get_draweble_objects(), render_cur))
				{
					std::cout << " @";
				}
				else if (render_cur.x == apple.get_position().x && render_cur.y == apple.get_position().y)
				{
					std::cout << ' ' << apple.get_image();
				}
				else
				{
					std::cout << "  ";
				}

				// logic
				if (in_list(snake.get_draweble_objects(), apple.get_position()))
				{
					snake.increase_size(1);
					apple = apple_builder(snake, field_size);
				}
				if (not snake.is_alive(field_size))
				{
					system("cls");
					std::cout << "The end" << std::endl;
					return;
				}
			}
			std::cout << std::endl;
		}
		snake.refresh_state();
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		system("cls");
	}
	*/
	return;
}