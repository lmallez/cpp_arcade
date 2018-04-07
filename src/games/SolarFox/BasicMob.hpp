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

			std::SPTR<arc::IShape> draw(const std::SPTR<IShape> &parent) const override;
		};
	}
}

#endif /* CPP_ARCADE_BASICMOB_HPP */