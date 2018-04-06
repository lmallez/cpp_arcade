//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SFDrawLoader.cpp
//

#include "src/graphic/sfml/draw/SFShapeText.hpp"
#include "src/graphic/sfml/draw/SFShapeRect.hpp"
#include "src/graphic/sfml/draw/SFShapeCircle.hpp"
#include "SFShapeLoader.hpp"

arc::SFShapeLoader::SFShapeLoader()
{
}

std::UPTR<arc::IShape>
arc::SFShapeLoader::load(const arc::ShapeRect &item) const
{
	std::UPTR<arc::IShape> a = std::MKU<arc::SFShapeRect>(item);
	loadChild(item, a);
	return a;
}

std::UPTR<arc::IShape>
arc::SFShapeLoader::load(const arc::ShapeCircle &item) const
{
	std::UPTR<arc::IShape> a = std::MKU<arc::SFShapeCircle>(item);
	loadChild(item, a);
	return a;
}

std::UPTR<arc::IShape>
arc::SFShapeLoader::load(const arc::ShapeText &item) const
{
	std::UPTR<arc::IShape> a = std::MKU<arc::SFShapeText>(item);
	loadChild(item, a);
	return a;
}
