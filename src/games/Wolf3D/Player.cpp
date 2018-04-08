//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Player.cpp
//

#include <cmath>
#include "Player.hpp"

arc::wolf::Player::Player()
{
	_pos = {2, 2};
	_angle = 0;
}

float arc::wolf::Player::getAngle() const
{
	return _angle;
}

arc::VertexF arc::wolf::Player::getPos() const
{
	return _pos;
}

bool arc::wolf::Player::canMove(const Map &map, float dist) const
{
	VertexF pos;

	pos.rx() = _pos.x() + cosf(_angle) * dist;
	pos.ry() = _pos.y() + sinf(_angle) * dist;
	return (map.isOnMap((uint8_t)pos.x(), (uint8_t)pos.y())
	&& map.findOnMap((uint8_t)pos.x(), (uint8_t)pos.y()) == 0);
}

void arc::wolf::Player::move(float dist)
{
	_pos.rx() = _pos.x() + cosf(_angle) * dist;
	_pos.ry() = _pos.y() + sinf(_angle) * dist;
}

void arc::wolf::Player::rotate(float angle)
{
	_angle = _angle + angle;
	if (_angle >= 2 * M_PI)
		_angle -= 2 * M_PI;
	else if (_angle < 0)
		_angle += 2 * M_PI;
}
