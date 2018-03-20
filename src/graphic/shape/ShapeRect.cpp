//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// ShapeRect.cpp
//

#include "ShapeRect.hpp"

arc::ShapeRect::ShapeRect(
	const std::shared_ptr<IShape> &parent,
	const Texture &texture,
	RectF geometry) :
	AShape(parent, texture, geometry)
{
}

arc::ShapeRect::ShapeRect(const arc::ShapeRect &ex):
	AShape(ex)
{
}

std::unique_ptr<arc::IShape>
arc::ShapeRect::convert(const arc::IShapeLoader &loader) const
{
	return loader.load(*this);
}
