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

bool arc::solarfox::BasicMob::collision(arc::VertexF obj)
{
	return false;
}

std::shared_ptr<arc::IShape>
arc::solarfox::BasicMob::draw(std::shared_ptr<arc::IShape> parent) const
{
	uint8_t a = (uint8_t)255 / (uint8_t)getHealth();
	arc::Color color = arc::Color(a, a, a);
	return std::make_shared<arc::ShapeCircle>(parent, arc::Texture(color, color), getPos());
}
