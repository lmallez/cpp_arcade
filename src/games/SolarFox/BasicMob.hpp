//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// BasicMob.hpp
//

#ifndef CPP_ARCADE_BASICMOB_HPP
#define CPP_ARCADE_BASICMOB_HPP

#include "AObject.hpp"

namespace arc {
	namespace solarfox {
		class BasicMob : public AObject {
		public:
			BasicMob(RectF pos, int health);

			bool collision(const RectF &obj) override;
			std::shared_ptr<arc::IShape>
			draw(std::shared_ptr<arc::IShape> parent) const override;
		};
	}
}

#endif /* CPP_ARCADE_BASICMOB_HPP */