//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// ShapeCircle.cpp
//

#include "ShapeCircle.hpp"

arc::ShapeCircle::ShapeCircle(const std::shared_ptr<arc::IShape> &parent,
	const arc::Texture &texture, arc::VertexF pos, float radius):
	AShape(parent, texture,
		arc::RectF(pos.x() - radius / 2, pos.y() - radius / 2,
			radius, radius))
{

}

arc::ShapeCircle::ShapeCircle(const std::shared_ptr<arc::IShape> &parent,
	const arc::Texture &texture, arc::RectF geometry):
	AShape(parent, texture, geometry)
{

}

arc::ShapeCircle::ShapeCircle(const arc::ShapeCircle &ex):
	AShape(ex)
{
}

std::unique_ptr<arc::IShape>
arc::ShapeCircle::convert(const arc::IShapeLoader &loader) const
{
	return loader.load(*this);
}
