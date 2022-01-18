#pragma once


namespace ss_c
// constants
{
	enum object_types {
		HEAD = 0,
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
// types
{
	template <class TYPE>
	struct Vector2d {
		TYPE x;
		TYPE y;
	};
}
