//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Monster.hpp
//

#ifndef CPP_ARCADE_MONSTER_HPP
#define CPP_ARCADE_MONSTER_HPP

#include "src/games/Controller/PlayerController.hpp"
#include "src/graphic/shape/ShapeRect.hpp"
#include "MonsterMissile.hpp"

namespace arc {
	namespace solarfox {
		class Monster {
		public:
			Monster(Direction dir, VertexF size);

			std::shared_ptr<IShape> draw(const std::shared_ptr<IShape> &parent) const;
			void move(float speed);
			std::shared_ptr<AMissile> shot() const;

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