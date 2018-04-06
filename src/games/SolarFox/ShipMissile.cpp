//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// ShipMissile.cpp
//

#include "ShipMissile.hpp"

arc::solarfox::ShipMissile::ShipMissile(arc::VertexF pos, arc::VertexF size,
	Direction dir):
	AMissile(pos, size, dir, 0.005, 0.2)
{
}

std::shared_ptr <arc::IShape>
arc::solarfox::ShipMissile::draw(const std::shared_ptr<IShape> &ptr) const
{
	std::shared_ptr<arc::IShape> a = std::make_shared<arc::ShapeRect>(ptr, arc::Texture(arc::Color::Magenta, arc::Color::Magenta), getPos());
	return a;
}