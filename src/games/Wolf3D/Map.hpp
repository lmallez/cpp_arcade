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

namespace arc {
	namespace wolf {
		class Map {
		public:
			Map(const VertexS &mapSize);
			uint8_t findOnMap(const Vertex <int> &pos) const;
			uint8_t findOnMap(int x, int y) const;
			bool isOnMap(const Vertex <int> &pos) const;
			bool isOnMap(int x, int y) const;
			void setMap(const VertexS &pos, uint8_t val) const;
			void setMap(const Vertex<int> &pos, uint8_t val) const;
			void setMap(int x, int y, uint8_t val) const;

		private:
			VertexS _size;
			uint8_t **_map;
		};
	}
}

#endif /* CPP_ARCADE_RAYCATSER_HPP */