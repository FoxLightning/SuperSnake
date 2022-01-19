#pragma once


namespace ss_c
/*
* constants 
*/
{
	const int FIELD_WIDTH = 30;
	const int FIELD_HEIGHT = 30;
	enum colision_cases {
		GAME_OVER,
		INCREASE_SCORE,
	};
	enum object_types {
		NOTHING = 0,
		HEAD,
		TAIL,
		APPLE,
		BORDER
	};
	enum direction {
		WEST = 0,
		EAST,
		NORTH,
		SOUTH,
	};
}

namespace ss_t
/*
* types
*/
{
	template <class TYPE>
	struct Vector2d
	{
		/*
		* simple 2d vector
		*/
		TYPE x;
		TYPE y;
	};
	struct BasePrimitive
	{
		/*
		* A structure that represents a cell.
		* To renderand calculate game logic, it is
		* enough to know the positionand type of the cell 
		*/
		Vector2d<int> position;
		int type;
	};
}
