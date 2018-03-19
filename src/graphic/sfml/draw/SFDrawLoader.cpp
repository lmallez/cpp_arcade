//
// EPITECH PROJECT, 2018
// cpp_arcade - SFDrawLoader.cpp
// File description:
// Created by Faudil Puttilli
//

#include "SFDrawLoader.hpp"

std::unique_ptr<arc::IDraw> arc::SFDrawLoader::load(const arc::IShape &shape)
const
{
	return _items[shape.getType()].load(shape);
}