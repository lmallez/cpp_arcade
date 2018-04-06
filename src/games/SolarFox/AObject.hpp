//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// AObject.hpp
//

#ifndef CPP_ARCADE_AOBJECT_HPP
#define CPP_ARCADE_AOBJECT_HPP

#include <vector>
#include <memory>
#include <src/games/utils/IObject.hpp>
#include "src/graphic/IShape.hpp"
#include "src/std/Rect.hpp"

namespace arc {
	namespace solarfox {
		class AObject : virtual public IObject {
		public:
			AObject(const RectF &pos, int health);

			arc::RectF getPos() const;
			int getHealth() const;

			bool collision(const RectF &obj) const override;
			bool tryCollision(const RectF &obj);

		protected:
			int _health;

		private:
			arc::RectF _pos;
		};
	}
}

#endif /* CPP_ARCADE_AOBJECT_HPP */