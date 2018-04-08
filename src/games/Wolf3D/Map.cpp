//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Raycatser.cpp
//

#include <src/exception/Exception.hpp>
#include "Map.hpp"

arc::wolf::Map::Map(const VertexS &mapSize)
{
	_size = mapSize;
	_map = new uint8_t*[mapSize.y()];
	for(size_t i = 0; i < mapSize.y(); ++i) {
		_map[i] = new uint8_t[mapSize.x()];
	}
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
	return _map[x][y];
}

bool arc::wolf::Map::isOnMap(const Vertex<int> &pos) const
{
	return isOnMap(pos.x(), pos.y());
}

bool arc::wolf::Map::isOnMap(int x, int y) const
{
	return x >= 0 && x < (int)_size.x()
		&& y >= 0 && y < (int)_size.y();
}

void arc::wolf::Map::setMap(const arc::VertexS &pos, uint8_t val) const
{
	setMap((int)pos.x(), (int)pos.y(), val);
}

void arc::wolf::Map::setMap(const arc::Vertex<int> &pos, uint8_t val) const
{
	setMap(pos.x(), pos.y(), val);
}

void arc::wolf::Map::setMap(int x, int y, uint8_t val) const
{
	if (!isOnMap(x, y))
		throw arc::Exception("Map", "Invalid Pos");
	_map[x][y] = val;
}
