#include "GameProc.h"
#include "RenderProc.h"
#include "PhysicalProc.h"

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

GameProc::GameProc()
{
	field_size = ss_t::Vector2d<int>{ 30, 30 };
	input_manager = InputManager::get_instance();

}

void GameProc::run_game()
{

	Snake snake(ss_t::Vector2d<int>{15, 15});
	RenderProc* render_proc = RenderProc::get_instance();
	PhysicalProc* physical_proc = PhysicalProc::get_instance();
	while (true)
	{

		snake.refresh_state();
		render_proc->render();

		if (physical_proc->check_colision() == ss_c::GAME_OVER)
		{
			std::cout << "Game Over" << std::endl;
			return;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}

	return;
}