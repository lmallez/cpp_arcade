//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Direction.cpp
//

#include "Direction.hpp"

arc::Direction arc::operator!(arc::Direction dir)
{
	switch (dir) {
	case UP:
		return DOWN;
	case LEFT:
		return RIGHT;
	case DOWN:
		return UP;
	case RIGHT:
		return LEFT;
	default:
		return NONE;
	}
}

arc::Direction arc::operator&(arc::Direction dir)
{
	switch (dir) {
	case UP:
		return RIGHT;
	case LEFT:
		return UP;
	case DOWN:
		return LEFT;
	case RIGHT:
		return DOWN;
	default:
		return NONE;
	}
}

arc::Direction arc::operator*(arc::Direction dir)
{
	switch (dir) {
	case UP:
		return LEFT;
	case LEFT:
		return DOWN;
	case DOWN:
		return RIGHT;
	case RIGHT:
		return UP;
	default:
		return NONE;
	}
}