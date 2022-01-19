#include "GameProc.h"

GameProc::GameProc()
{
	field_size = ss_t::Vector2d<int>{ss_c::FIELD_WIDTH, ss_c::FIELD_HEIGHT};
	game_speed = 200;
}

void GameProc::run_game()
{
	/*
	* creating game objects
	*/
	BorderManager borders = BorderManager::BorderManager();
	Snake snake(ss_t::Vector2d<int>{field_size.x/2, field_size.y/2});
	AppleManager apples = AppleManager::AppleManager();

	/*
	* creating game processors
	*/
	RenderProc* render_proc = RenderProc::get_instance();
	PhysicalProc* physical_proc = PhysicalProc::get_instance();

	/*
	* run game loop
	*/
	while (true)
	{
		/*
		* refresh state of dynamic objects
		*/
		snake.refresh_state();
	
		/*
		* cheack colisions and hendle result
		*/
		switch (physical_proc->check_colision(snake.get_head(), true))
		{
		case ss_c::APPLE:
			apples.remove_apple(snake.get_head());
			apples.add_apple();
			snake.increase_size(1);
			break;
		case ss_c::BORDER:
		case ss_c::TAIL:
			/*
			* endgame message
			* exit from game loop
			*/
			system("cls");
			std::cout << "\n\n\n\n\n\n\n";
			std::cout << "\tGame over" << std::endl;
			std::cout << "\tSCORE: " << snake.get_primitives().size() << std::endl;
			std::cout << "\tpress any key" << std::endl;
			set_input_console(0);
			while (not get_input_console()) {};
			return;
		}
		/*
		* check ESC input to exit
		*/
		switch (get_input_console())
		{
		case('q'):
			return;
		}
		
		/*
		* render game objects
		*/
		render_proc->render();
		std::cout << "Score: " << snake.get_primitives().size() << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(game_speed));
	}

	return;
}