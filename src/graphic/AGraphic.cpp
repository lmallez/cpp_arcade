//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// AGraphic.cpp
//

#include "AGraphic.hpp"

arc::AGraphic::AGraphic(const std::unique_ptr<arc::IDrawLoader> &loader):
	_drawLoader()
{
}

void arc::AGraphic::draw(const std::shared_ptr<arc::IShape> &shape) const
{
	getDrawLoader().load(shape);
}

const arc::IDrawLoader &arc::AGraphic::getDrawLoader() const
{
	return *_drawLoader;
}
