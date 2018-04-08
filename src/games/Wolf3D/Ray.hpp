//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Ray.hpp
//

#ifndef CPP_ARCADE_RAY_HPP
#define CPP_ARCADE_RAY_HPP

#include "src/games/utils/IObject.hpp"
#include "src/graphic/shape/ShapeRect.hpp"
#include "Map.hpp"
#include "Player.hpp"

namespace arc {
	namespace wolf {
		class Ray : public IObject {
		public:
			Ray(float angle, size_t pos, float larg);

			VertexF castMath(const VertexF &playPos, float angle,
				const Map &map);

			std::shared_ptr<IShape> draw(
				const std::SPTR<arc::IShape> &parent)
			const override;
			bool collision(const RectF &obj) const override;

		private:
			float _angle;
			size_t _pos;
			float _larg;

			bool _isCast;
			float _dist;
			bool _side;
		};
	}
}
#endif /* CPP_ARCADE_RAY_HPP */