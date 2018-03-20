//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SFDrawLoader.cpp
//

#include <src/graphic/sfml/draw/SFShapeText.hpp>
#include "src/graphic/sfml/draw/SFShapeRect.hpp"
#include "src/graphic/sfml/draw/SFShapeCircle.hpp"
#include "SFShapeLoader.hpp"

arc::SFShapeLoader::SFShapeLoader()
{
}

std::unique_ptr<arc::IShape>
arc::SFShapeLoader::load(const arc::ShapeRect &item) const
{
	return std::make_unique<arc::SFShapeRect>(item);
}

std::unique_ptr<arc::IShape>
arc::SFShapeLoader::load(const arc::ShapeCircle &item) const
{
	return std::make_unique<arc::SFShapeCircle>(item);
}

std::unique_ptr<arc::IShape>
arc::SFShapeLoader::load(const arc::ShapeText &item) const
{
	return std::make_unique<arc::SFShapeText>(item);
}
