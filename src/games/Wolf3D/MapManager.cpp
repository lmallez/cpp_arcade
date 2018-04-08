//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// MapManager.cpp
//

#include <src/std/DirectoryReader.hpp>
#include <src/games/utils/mapReader/MapReader.hpp>
#include "MapManager.hpp"

arc::wolf::MapManager::MapManager(const std::string &dir):
	_dir(dir), _map({0, 0})
{
	arc::DirectoryReader mapDir(dir);
	_mapList = mapDir.fileName();
	_map = loadRandMap();
}

arc::VertexS arc::wolf::MapManager::getMapSize(
	std::vector<std::pair<arc::VertexS, int>> map) const
{
	arc::VertexS mapSize(0, 0);

	for (auto &a : map) {
		mapSize.rx() = std::max(a.first.x() + 1, mapSize.x());
		mapSize.ry() = std::max(a.first.y() + 1, mapSize.y());
	}
	return mapSize;
}

arc::wolf::Map arc::wolf::MapManager::initMap(size_t lvl)
{
	if (lvl >= _mapList.size())
		throw arc::Exception("initMap", "Invalid MapManager ID");
	auto intMap = arc::MapReader::readMap(_dir + "/" + _mapList[lvl]);
	arc::VertexS mapSize = getMapSize(intMap);
	auto map = arc::wolf::Map(mapSize);
	for (auto a : intMap)
		map.setMap(a.first, (uint8_t )a.second);
	_map = map;
	return map;
}

arc::wolf::Map arc::wolf::MapManager::loadRandMap()
{
	size_t lvl = random() % _mapList.size();
	return initMap(lvl);
}

const arc::wolf::Map &arc::wolf::MapManager::getMap() const
{
	return _map;
}