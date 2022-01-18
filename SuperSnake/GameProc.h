#pragma once

#include <chrono>
#include <conio.h>
#include <iostream>
#include <thread>
#include <algorithm>
#include <stdlib.h>
#include <list>

#include "ss_common.h"
#include "Snake.h"
#include "Apple.h"
#include "InputManager.h"


class GameProc
{
	ss_t::Vector2d<int> field_size;
	InputManager *input_manager;
public:
	GameProc();
	void run_game();
};

