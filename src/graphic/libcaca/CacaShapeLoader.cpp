/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
** aaaah
*/

#include "src/graphic/libcaca/draw/CacaShapeText.hpp"
#include "src/graphic/libcaca/draw/CacaShapeCircle.hpp"
#include "src/graphic/libcaca/draw/CacaShapeRect.hpp"
#include "CacaShapeLoader.hpp"

arc::CacaShapeLoader::CacaShapeLoader()
{
}

std::unique_ptr<arc::IShape>
arc::CacaShapeLoader::load(const arc::ShapeRect &item) const
{
	std::unique_ptr<arc::IShape> a = std::make_unique<arc::CacaShapeRect>(item);
	loadChild(item, a);
	return a;
}

std::unique_ptr<arc::IShape>
arc::CacaShapeLoader::load(const arc::ShapeCircle &item) const
{
	std::unique_ptr<arc::IShape> a = std::make_unique<arc::CacaShapeCircle>(item);
	loadChild(item, a);
	return a;
}

std::unique_ptr<arc::IShape>
arc::CacaShapeLoader::load(const arc::ShapeText &item) const
{
	std::unique_ptr<arc::IShape> a = std::make_unique<arc::CacaShapeText>(item);
	loadChild(item, a);
	return a;
}
