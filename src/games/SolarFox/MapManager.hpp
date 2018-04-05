//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// MapManager.hpp
//

#ifndef CPP_ARCADE_MAP_HPP
#define CPP_ARCADE_MAP_HPP

#include <string>
#include <vector>
#include "src/std/Vertex.hpp"
#include "src/std/DirectoryReader.hpp"
#include "AObject.hpp"
#include "BasicMob.hpp"

namespace arc {
	namespace solarfox {
		class MapManager {
		public:
			explicit MapManager(const std::string &dir);

			std::vector<std::shared_ptr<AObject>> initMap(size_t lvl);
			std::vector<std::shared_ptr<AObject>> nextMap();

		private:
			size_t _lvl = 0;
			std::vector<std::string> _mapList;
			std::string _dir;
		};
	}
}

#endif /* CPP_ARCADE_MAP_HPP */