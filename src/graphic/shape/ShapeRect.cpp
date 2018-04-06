//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// ShapeRect.cpp
//

#include "ShapeRect.hpp"

arc::ShapeRect::ShapeRect(
	const std::SPTR<IShape> &parent,
	const Texture &texture,
	RectF geometry) :
	AShape(parent, texture, geometry)
{
}

arc::ShapeRect::ShapeRect(const arc::ShapeRect &ex):
	AShape(ex)
{
}

std::UPTR<arc::IShape>
arc::ShapeRect::convert(const arc::IShapeLoader &loader) const
{
	return loader.load(*this);
}
