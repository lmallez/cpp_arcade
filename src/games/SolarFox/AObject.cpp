//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// AObject.cpp
//

#include "AObject.hpp"

arc::solarfox::AObject::AObject(const arc::RectF &pos, int health):
	_health(health), _pos(pos)
{
}

arc::RectF arc::solarfox::AObject::getPos() const
{
	return _pos;
}

int arc::solarfox::AObject::getHealth() const
{
	return _health;
}

bool arc::solarfox::AObject::collision(const arc::RectF &obj) const
{
	return (getPos().isCollide(obj));
}

bool arc::solarfox::AObject::tryCollision(const arc::RectF &obj)
{
	if (collision(obj)) {
		_health--;
		return true;
	}
	return false;
}
