//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// MonsterMissile.hpp
//

#ifndef CPP_ARCADE_MONSTERMISSILE_HPP
#define CPP_ARCADE_MONSTERMISSILE_HPP

#include "AMissile.hpp"
#include "src/games/SolarFox/MonsterMissile.hpp"
#include "src/graphic/shape/ShapeCircle.hpp"

namespace arc {
	namespace solarfox {
		class MonsterMissile : public AMissile {
		public:
			MonsterMissile(arc::VertexF pos, arc::VertexF size, Direction dir);

			std::shared_ptr<IShape> draw(const std::shared_ptr<IShape> &ptr) const override;
		};
	}
}

#endif /* CPP_ARCADE_MONSTERMISSILE_HPP */