//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// MapManager.cpp
//

#include <src/games/utils/mapReader/MapReader.hpp>
#include "MapManager.hpp"

arc::solarfox::MapManager::MapManager(const std::string &dir):
	_dir(dir)
{
	arc::DirectoryReader mapDir(dir);
	_mapList = mapDir.fileName();
}

std::vector<std::shared_ptr<arc::solarfox::AObject>> arc::solarfox::MapManager::initMap(size_t lvl)
{
	if (lvl > _mapList.size())
		throw arc::Exception("initMap", "Invalid MapManager ID");
	auto intMap = arc::MapReader::readMap(_dir + "/" + _mapList[lvl]);
	std::vector<std::shared_ptr<arc::solarfox::AObject>> map;
	arc::VertexF elemSize = arc::VertexF(1, 1) / arc::VertexF(20, 20);
	for (auto elem : intMap) {
		if (elem.second > 0) {
			arc::RectF size(elem.first.x() * elemSize.x(), elem.first.y() * elemSize.y(), elemSize.x(), elemSize.y());
			map.push_back(std::make_shared<arc::solarfox::BasicMob>(size, elem.second));
		}
	}
	return map;
}

std::vector<std::shared_ptr<arc::solarfox::AObject>> arc::solarfox::MapManager::nextMap()
{
	return initMap(_lvl + 1);
}
