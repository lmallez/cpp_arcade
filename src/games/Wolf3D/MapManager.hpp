
//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// MapManager.hpp
//

#ifndef CPP_ARCADE_MAPMANAGER_HPP
#define CPP_ARCADE_MAPMANAGER_HPP

#include <string>
#include "Map.hpp"

namespace arc {
	namespace wolf {
		class MapManager {
		public:
			MapManager(const std::string &dir);
			VertexS getMapSize(std::vector<std::pair<arc::VertexS, int>> map) const;
			Map initMap(size_t lvl);
			Map loadRandMap();
			const Map &getMap() const;

		private:
			std::string _dir;
			std::vector<std::string> _mapList;
			Map _map;
		};
	}
}

#endif /* CPP_ARCADE_MAPMANAGER_HPP */