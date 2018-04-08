//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Raycatser.hpp
//

#ifndef CPP_ARCADE_RAYCATSER_HPP
#define CPP_ARCADE_RAYCATSER_HPP

#include <unordered_map>
#include "src/std/Vertex.hpp"

static const uint8_t tmpMap[10][10] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};

namespace arc {
	namespace wolf {
		class Map {
		public:
			Map();
			uint8_t findOnMap(const Vertex <int> &pos) const;
			uint8_t findOnMap(int x, int y) const;
			bool isOnMap(const Vertex <int> &pos) const;
			bool isOnMap(int x, int y) const;

		private:
			VertexS _size;
			uint8_t _map[10][10];
		};
	}
}

#endif /* CPP_ARCADE_RAYCATSER_HPP */