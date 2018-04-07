//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// MapManager.cpp
//

#include <algorithm>
#include "src/games/utils/mapReader/MapReader.hpp"
#include "src/std/DirectoryReader.hpp"
#include "MapManager.hpp"

arc::snake::MapManager::MapManager(const std::string &dir):
	_dir(dir)
{
	arc::DirectoryReader mapDir(dir);
	_mapList = mapDir.fileName();
	std::sort(_mapList.begin(), _mapList.end(), [](const std::string &a,
		const std::string &b) {return a < b;});
}

std::vector<arc::VertexS> arc::snake::MapManager::initMap(size_t lvl) const
{
	if (lvl >= _mapList.size())
		throw arc::Exception("initMap", "Invalid MapManager ID");
	auto intMap = arc::MapReader::readMap(_dir + "/" + _mapList[lvl]);
	std::vector<arc::VertexS> map;
	for (auto elem : intMap) {
		if (elem.second > 0) {
			map.push_back(elem.first);
		}
	}
	return map;
}

std::vector<arc::VertexS> arc::snake::MapManager::loadRandMap() const
{
	size_t map = random() % _mapList.size();
	return initMap(map);
}
