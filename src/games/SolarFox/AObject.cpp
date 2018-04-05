//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// AObject.cpp
//

#include "AObject.hpp"

arc::solarfox::AObject::AObject(const arc::RectF &pos, int health):
	_pos(pos), _health(health)
{
	std::cout << _pos.pos().x() << " " << _pos.pos().y() << std::endl;
}

arc::RectF arc::solarfox::AObject::getPos() const
{
	return _pos;
}

int arc::solarfox::AObject::getHealth() const
{
	return _health;
}
