//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// MapReader.hpp
//

#ifndef CPP_ARCADE_MAPREADER_HPP
#define CPP_ARCADE_MAPREADER_HPP

#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include "src/std/Vertex.hpp"
#include "src/games/utils/IGameObject.hpp"

#define ASSETS_DIR "../assets"

namespace arc {
	class MapReader {
	public:
		explicit MapReader(const std::string &pathFile = "");

		static std::vector<std::pair<arc::VertexS, int>> readMap(const std::string &path);
		std::vector<std::pair<arc::VertexS, int>> readMap() const;

	private:
		std::string _name;
	};
}

#endif /* CPP_ARCADE_MAPREADER_HPP */