//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// MonsterMissile.cpp
//

#include "MonsterMissile.hpp"

arc::solarfox::MonsterMissile::MonsterMissile(arc::VertexF pos,
	arc::VertexF size, arc::Direction dir):
	AMissile(pos, size, dir, 0.01)
{
}

std::shared_ptr<arc::IShape>
arc::solarfox::MonsterMissile::draw(std::shared_ptr<arc::IShape> ptr) const
{
	std::shared_ptr<arc::IShape> a = std::make_shared<arc::ShapeCircle>(ptr, arc::Texture(arc::Color::Magenta, arc::Color::Magenta), getPos());
	return a;
}
