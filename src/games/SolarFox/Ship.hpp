//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Ship.hpp
//

#ifndef CPP_ARCADE_SHIP_HPP
#define CPP_ARCADE_SHIP_HPP

#include "src/games/utils/Controller/PlayerController.hpp"
#include "src/graphic/shape/ShapeContainer.hpp"
#include "src/graphic/shape/ShapeRect.hpp"
#include "src/graphic/shape/ShapeCircle.hpp"
#include "src/graphic/shape/ShapeText.hpp"
#include "AMissile.hpp"

#define BULLET_SIZE 0.02

namespace arc {
	namespace solarfox {
		class Ship : protected PlayerController {
		public:
			Ship(const arc::VertexS &mapSize,
				const arc::VertexF &shipSize,
				int life = 5);

			void execKey(EventHandler &event) override;
			std::shared_ptr<IShape> draw(
				const std::shared_ptr<arc::IShape> &parent) const;
			std::shared_ptr<IShape> drawShip(const std::shared_ptr<arc::IShape> &parent, RectF pos, Direction dir) const;
			RectF getPos() const;

			std::shared_ptr<IShape> drawLife(const std::shared_ptr<arc::IShape> &zone, arc::RectF pos) const;
			int getLife() const;
			void setLife(int life);
			bool moveLife(int nb);

			std::shared_ptr<AMissile>  shot() const;

		private:
			arc::RectF _getCanonSize(Direction dir) const;
			int _life = 10;
			int _maxLife = 10;
		};
	}
}

#endif /* CPP_ARCADE_SHIP_HPP */