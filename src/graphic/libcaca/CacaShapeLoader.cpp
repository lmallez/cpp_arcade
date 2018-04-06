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

std::UPTR<arc::IShape>
arc::CacaShapeLoader::load(const arc::ShapeRect &item) const
{
	std::UPTR<arc::IShape> a = std::MKU<arc::CacaShapeRect>(item);
	loadChild(item, a);
	return a;
}

std::UPTR<arc::IShape>
arc::CacaShapeLoader::load(const arc::ShapeCircle &item) const
{
	std::UPTR<arc::IShape> a = std::MKU<arc::CacaShapeCircle>(item);
	loadChild(item, a);
	return a;
}

std::UPTR<arc::IShape>
arc::CacaShapeLoader::load(const arc::ShapeText &item) const
{
	std::UPTR<arc::IShape> a = std::MKU<arc::CacaShapeText>(item);
	loadChild(item, a);
	return a;
}
