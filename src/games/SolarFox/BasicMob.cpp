//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// BasicMob.cpp
//

#include "src/graphic/shape/ShapeCircle.hpp"
#include "BasicMob.hpp"

arc::solarfox::BasicMob::BasicMob(arc::RectF pos, int health):
	AObject(pos, health)
{
}

bool arc::solarfox::BasicMob::collision(const RectF &obj)
{
	if (getPos().isCollide(obj)) {
		_health--;
		return true;
	}
	return false;
}

std::shared_ptr<arc::IShape>
arc::solarfox::BasicMob::draw(std::shared_ptr<arc::IShape> parent) const
{
	uint8_t a;
	if (_health > 0)
		a = (uint8_t)255 / _health;
	else
		a = 255;
	arc::Color color = arc::Color(a, a, a);
	return std::make_shared<arc::ShapeCircle>(parent, arc::Texture(color, color), getPos());
}
