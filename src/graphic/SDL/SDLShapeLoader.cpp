//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SDLDrawLoader.cpp
//

#include <src/graphic/SDL/draw/SDLShapeText.hpp>
#include "src/graphic/SDL/draw/SDLShapeRect.hpp"
#include "src/graphic/SDL/draw/SDLShapeCircle.hpp"
#include "SDLShapeLoader.hpp"

arc::SDLShapeLoader::SDLShapeLoader()
{
}

std::UPTR<arc::IShape>
arc::SDLShapeLoader::load(const arc::ShapeRect &item) const
{
	std::UPTR<arc::IShape> a = std::MKU<arc::SDLShapeRect>(item);
	loadChild(item, a);
	return a;
}

std::UPTR<arc::IShape>
arc::SDLShapeLoader::load(const arc::ShapeCircle &item) const
{
	std::UPTR<arc::IShape> a = std::MKU<arc::SDLShapeCircle>(item);
	loadChild(item, a);
	return a;
}

std::UPTR<arc::IShape>
arc::SDLShapeLoader::load(const arc::ShapeText &item) const
{
	std::UPTR<arc::IShape> a = std::MKU<arc::SDLShapeText>(item);
	loadChild(item, a);
	return a;
}
