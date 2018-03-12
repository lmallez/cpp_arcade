//
// EPITECH PROJECT, 2018
// cpp_arcade - ShapeLoader.cpp
// File description:
// Created by Faudil Puttilli
//

#include "ShapeLoader.hpp"


arc::ShapeLoader& arc::ShapeLoader::getInstance()
{
	static std::unique_ptr<ShapeLoader> instance = nullptr;

	if (!instance)
		instance.reset(new ShapeLoader());
	return *instance;
}

arc::ShapeLoader::ShapeLoader()
{
	_inst["rect"] = std::make_unique<arc::ShapeRect>();
	_inst["circle"] = std::make_unique<arc::ShapeCircle>();
	_inst["text"] = std::make_unique<arc::ShapeText>();
}

std::unique_ptr<arc::IShape> arc::ShapeLoader::loadShape(
	const std::string &tName)
{
	return _inst[tName]->clone();
}