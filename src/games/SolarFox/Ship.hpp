//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Ship.hpp
//

#ifndef CPP_ARCADE_SHIP_HPP
#define CPP_ARCADE_SHIP_HPP

#include "src/games/Controller/PlayerController.hpp"
#include "src/graphic/shape/ShapeContainer.hpp"
#include "src/graphic/shape/ShapeRect.hpp"
#include "src/graphic/shape/ShapeCircle.hpp"
#include "src/graphic/shape/ShapeText.hpp"

namespace arc {
	namespace solarfox {
		class Ship : protected PlayerController {
		public:
			Ship(const arc::VertexS &mapSize,
					const arc::VertexF &shipSize);

			void execKey(EventHandler &event) override;
			std::shared_ptr<IShape>
			draw(std::shared_ptr<arc::IShape> map) const;
			RectF getPos() const;
		private:
			RectF _getCanonSize() const;
		};
	}
}

#endif /* CPP_ARCADE_SHIP_HPP */