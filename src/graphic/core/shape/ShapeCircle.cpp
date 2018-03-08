//
// EPITECH PROJECT, 2018
// cpp_arcade - ShapeCircle.cpp
// File description:
// Created by Faudil Puttilli
//

#include "ShapeCircle.hpp"

arc::ShapeCircle::ShapeCircle(const arc::Vertex<float> &ori, const float rad):
	_origin(ori), _radius(rad)
{}

arc::ShapeCircle::ShapeCircle(const arc::ShapeCircle &cpy) :
	_origin(cpy.getOrigin()), _radius(cpy.getRadius())
{}

arc::Vertex<float> arc::ShapeCircle::getOrigin() const
{
	return _origin;
}

float arc::ShapeCircle::getRadius() const
{
	return _radius;
}

void arc::ShapeCircle::setOrigin(const arc::Vertex<float> &val)
{
	_origin = val;
}

void arc::ShapeCircle::setRadius(const float val)
{
	_radius = val;
}

std::unique_ptr<arc::IDraw> arc::ShapeCircle::convert(
	std::unique_ptr<IShapeLoader> &loader)
{
	return nullptr;
}

std::unique_ptr<arc::IShape> arc::ShapeCircle::getChild(__attribute((unused))
						      size_t id)
{
	return nullptr;
}

std::unique_ptr<arc::IShape> arc::ShapeCircle::operator[](__attribute((unused))
							size_t id)
{
	return nullptr;
}

std::unique_ptr<arc::IShape> arc::ShapeCircle::clone()
{
	return std::make_unique<arc::ShapeCircle>(*this);
}