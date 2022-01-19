#include <stdlib.h>
#include <time.h>
#include "GameProc.h"
#include "Menu.h"

int main()
{
	srand(time(NULL));
	Menu menu;
	menu.run_menu();
	GameProc game_proc;
	game_proc.run_game();
}
