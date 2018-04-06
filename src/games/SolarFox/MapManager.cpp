//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// MapManager.cpp
//

#include "src/games/utils/mapReader/MapReader.hpp"
#include <algorithm>
#include "MapManager.hpp"

arc::solarfox::MapManager::MapManager(const std::string &dir):
	_dir(dir)
{
	arc::DirectoryReader mapDir(dir);
	_mapList = mapDir.fileName();
	std::sort(_mapList.begin(), _mapList.end(), [](const std::string &a, const std::string &b) {return a < b;});
}

std::vector<std::shared_ptr<arc::solarfox::AObject>> arc::solarfox::MapManager::initMap(size_t lvl)
{
	if (lvl >= _mapList.size())
		throw arc::Exception("initMap", "Invalid MapManager ID");
	auto intMap = arc::MapReader::readMap(_dir + "/" + _mapList[lvl]);
	std::vector<std::shared_ptr<arc::solarfox::AObject>> map;
	arc::VertexF elemSize = arc::VertexF(1, 1) / arc::VertexF(20, 20);
	for (auto elem : intMap) {
		if (elem.second > 0) {
			arc::RectF size(elem.first.x() * elemSize.x(), elem.first.y() * elemSize.y(), elemSize.x(), elemSize.y());
			size.rsize() = size.size() / 2;
			size.rpos() = size.rpos() + size.size() / 0.5;
			map.push_back(std::make_shared<arc::solarfox::BasicMob>(size, elem.second));
		}
	}
	_lvl = lvl;
	return map;
}

std::vector<std::shared_ptr<arc::solarfox::AObject>> arc::solarfox::MapManager::nextMap()
{
	return initMap(_lvl + 1);
}

bool arc::solarfox::MapManager::lastLvl() const
{
	return (_lvl == _mapList.size() - 1);
}
