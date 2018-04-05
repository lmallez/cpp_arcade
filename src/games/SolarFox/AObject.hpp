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
#include "src/graphic/IShape.hpp"
#include "src/std/Rect.hpp"

namespace arc {
	namespace solarfox {
		class AObject {
		public:
			AObject(const RectF &pos, int health);

			virtual bool collision(arc::VertexF obj) = 0;
			virtual std::shared_ptr<arc::IShape>
			draw(std::shared_ptr<arc::IShape> parent) const = 0;
			arc::RectF getPos() const;
			int getHealth() const;

		private:
			arc::RectF _pos;
			int _health;
		};
	}
}

#endif /* CPP_ARCADE_AOBJECT_HPP */