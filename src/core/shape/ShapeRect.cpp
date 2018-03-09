//
// EPITECH PROJECT, 2018
// cpp_arcade - ShapeRect.cpp
// File description:
// Created by Faudil Puttilli
//

#include "ShapeRect.hpp"

arc::ShapeRect::ShapeRect()
:_geometry(0, 0, 0, 0)
{}

arc::ShapeRect::ShapeRect(const arc::Rect<float> &geo) :
_geometry(geo)
{}

arc::ShapeRect::ShapeRect(const arc::ShapeRect &copy) :
_geometry(copy.getGeometry())
{}

arc::Rect<float> arc::ShapeRect::getGeometry() const
{
	return _geometry;
}

void arc::ShapeRect::setGeometry(const arc::Rect<float> &val)
{
	_geometry = val;
}

std::unique_ptr<arc::IDraw> arc::ShapeRect::convert(
	std::unique_ptr<IShapeLoader> &loader)
{
	return nullptr;
}

std::unique_ptr<arc::IShape> arc::ShapeRect::clone() const
{
	return std::make_unique<arc::ShapeRect>(*this);
}