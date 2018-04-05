//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Direction.hpp
//

#ifndef CPP_ARCADE_DIRECTION_HPP
#define CPP_ARCADE_DIRECTION_HPP

namespace arc {
	enum Direction {
		NONE,
		UP,
		DOWN,
		LEFT,
		RIGHT
	};

	Direction operator!(Direction);
	Direction operator*(Direction);
	Direction operator&(Direction);
}

#endif /* CPP_ARCADE_DIRECTION_HPP */