//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// MonsterMissile.cpp
//

#include "MonsterMissile.hpp"

arc::solarfox::MonsterMissile::MonsterMissile(arc::VertexF pos,
	arc::VertexF size, arc::Direction dir):
	AMissile(pos, size, !dir, 0.005)
{
}

std::SPTR<arc::IShape>
arc::solarfox::MonsterMissile::draw(const std::SPTR<arc::IShape> &ptr) const
{
	std::SPTR<arc::IShape> a = std::MKS<arc::ShapeCircle>(ptr, arc::Texture(arc::Color::Magenta, arc::Color::Magenta), getPos());
	return a;
}
