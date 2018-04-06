//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// MapManager.hpp
//

#ifndef CPP_ARCADE_MAPMANAGER_HPP
#define CPP_ARCADE_MAPMANAGER_HPP

#include <string>
#include <vector>
#include "src/std/Vertex.hpp"

namespace arc {
	namespace snake {
		class MapManager {
		public:
			explicit MapManager(const std::string &dir);

			std::vector<arc::VertexS> initMap(size_t lvl) const;
			std::vector<arc::VertexS> loadRandMap() const;

		private:
			std::vector<std::string> _mapList;
			std::string _dir;
		};
	}
}

#endif /* CPP_ARCADE_MAPMANAGER_HPP */