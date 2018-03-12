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
	_inst[""] = ;
}