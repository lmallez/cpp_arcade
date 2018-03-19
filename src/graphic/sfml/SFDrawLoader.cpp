//
// EPITECH PROJECT, 2018
// cpp_arcade - SFDrawLoader.cpp
// File description:
// Created by Faudil Puttilli
//

#include <src/graphic/sfml/draw/SFDrawRect.hpp>
#include <src/graphic/sfml/draw/SFDrawText.hpp>
#include <src/graphic/sfml/draw/SFDrawCircle.hpp>
#include "SFDrawLoader.hpp"

const std::unique_ptr<arc::IDrawLoader> &arc::SFDrawLoader::getInstance()
{
	static std::unique_ptr<arc::IDrawLoader> instance = nullptr;

	if (!instance)
		instance.reset(new SFDrawLoader());
	return instance;
}

arc::SFDrawLoader::SFDrawLoader()
{
	_items["rect"] = std::make_unique<arc::SFDrawRect>();
	_items["circle"] = std::make_unique<arc::SFDrawCircle>();
	_items["text"] = std::make_unique<arc::SFDrawText>();
}

const arc::IDraw &arc::SFDrawLoader::load(const std::shared_ptr<IShape> shape) const
{
	return _items.at(shape->getType())->load(shape);
}