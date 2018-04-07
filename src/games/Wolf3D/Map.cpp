//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Raycatser.cpp
//

#include <src/exception/Exception.hpp>
#include "Map.hpp"

arc::wolf::Map::Map()
{
	_size = {10, 10};
}

uint8_t arc::wolf::Map::findOnMap(const Vertex <int> &pos) const
{
	if (!isOnMap(pos.x(), pos.y()))
		throw arc::Exception("Map", "Invalid Pos");
	return findOnMap(pos.x(), pos.y());
}

uint8_t arc::wolf::Map::findOnMap(int x, int y) const
{
	if (!isOnMap(x, y))
		throw arc::Exception("Map", "Invalid Pos");
	return tmpMap[x][y];
}

bool arc::wolf::Map::isOnMap(const Vertex<int> &pos) const
{
	return isOnMap(pos.x(), pos.y());
}

bool arc::wolf::Map::isOnMap(int x, int y) const
{
	return x >= 0 && x < _size.x() && y >= 0 && y < _size.y();
}
