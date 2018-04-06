//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Monster.hpp
//

#ifndef CPP_ARCADE_MONSTER_HPP
#define CPP_ARCADE_MONSTER_HPP

#include "src/games/utils/Controller/PlayerController.hpp"
#include "src/graphic/shape/ShapeRect.hpp"
#include "MonsterMissile.hpp"

namespace arc {
	namespace solarfox {
		class Monster {
		public:
			Monster(Direction dir, VertexF size);

			std::SPTR<IShape> draw(const std::SPTR<IShape> &parent) const;
			void move(float speed);
			std::SPTR<AMissile> shot() const;

		private:
			Direction _dir;

			float _pos;
			VertexF _size;
			bool _upDown;

			RectF _getPos() const;
		};
	}
}

#endif /* CPP_ARCADE_MONSTER_HPP */