#include <stdlib.h>
#include <time.h>
#include "Menu.h"

int main()
{
	srand(time(NULL));
	Menu menu;
	menu.run_menu();
}
