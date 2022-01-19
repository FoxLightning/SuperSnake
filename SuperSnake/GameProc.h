#pragma once

#include <list>
#include <chrono>
#include <thread>
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>

#include "Snake.h"
#include "ss_common.h"
#include "RenderProc.h"
#include "AppleManager.h"
#include "PhysicalProc.h"
#include "InputManager.h"
#include "BorderManager.h"
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

