//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// AShapeLoader.cpp
//

#include "AShapeLoader.hpp"

void arc::AShapeLoader::loadChild(const arc::IShape &from,
	std::UPTR<IShape> &dest) const
{
	for (size_t i = 0; i < from.nbChild(); i++)
		dest->addChild(from.getChild(i).convert(*this));
}
