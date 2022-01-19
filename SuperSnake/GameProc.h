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
#include "InputManager.h"
#include "ControlledObject.h"


class GameProc:
	public ControlledObject
{
	/*
	* This class contains basic information about the game
	* and is intended to start the game loop.
	* Also in the loop, the class handles game events 
	*/
	ss_t::Vector2d<int> field_size;
	unsigned int game_speed;
public:
	GameProc();
	void run_game();
};

