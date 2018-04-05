//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// ShipMissile.hpp
//

#ifndef CPP_ARCADE_SHIPMISSILE_HPP
#define CPP_ARCADE_SHIPMISSILE_HPP

#include "AMissile.hpp"
#include "src/games/SolarFox/ShipMissile.hpp"
#include "src/graphic/shape/ShapeRect.hpp"

namespace arc {
	namespace solarfox {
		class ShipMissile : public AMissile {
		public:
			ShipMissile(arc::VertexF pos, arc::VertexF size, Direction dir);

			std::shared_ptr<IShape> draw(std::shared_ptr<IShape> ptr) const override;
			bool collision(const arc::RectF &obj) override;
		};
	}
}

#endif /* CPP_ARCADE_SHIPMISSILE_HPP */