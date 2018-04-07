//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Player.hpp
//

#ifndef CPP_ARCADE_PLAYER_HPP
#define CPP_ARCADE_PLAYER_HPP

#include "src/games/utils/Controller/PlayerController.hpp"
#include "Map.hpp"

namespace arc {
	namespace wolf {
		class Player {
		public:
			Player();

			float getAngle() const;
			VertexF getPos() const;

			void move(float dist);
			void rotate(float angle);

			bool canMove(const Map &map, float dist) const;

		private:
			VertexF _pos;
			float _angle;
		};
	}
}

#endif /* CPP_ARCADE_PLAYER_HPP */