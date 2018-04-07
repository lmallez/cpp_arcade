//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// AMissile.hpp
//

#ifndef CPP_ARCADE_AMISSILE_HPP
#define CPP_ARCADE_AMISSILE_HPP

#include "src/games/utils/IObject.hpp"
#include "src/graphic/IShape.hpp"
#include "src/std/Rect.hpp"

namespace arc {
	namespace solarfox {
		class AMissile : virtual public IObject {
		public:
			AMissile(VertexF pos, VertexF size, Direction dir,
				float speed, float range = 1);
			AMissile(RectF rect, Direction dir, float speed,
				float range = 1);

			RectF getPos() const;
			bool move();
			bool move(float speed);

			bool collision(const RectF &obj) const override;

		protected:
			RectF _pos;
			Direction _dir;

		private:
			float _dist = 0;
			float _range;
			float _speed;
		};
	}
}

#endif /* CPP_ARCADE_AMISSILE_HPP */