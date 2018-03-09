//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SFDrawRect.hpp
//

#ifndef CPP_ARCADE_SFDRAWRECT_HPP
#define CPP_ARCADE_SFDRAWRECT_HPP

#include <src/graphic/sfml/SFDraw.hpp>

namespace arc {
	class SFDrawRect : public SFDraw {
	public:
		virtual void draw() override;
	};
}

#endif /* CPP_ARCADE_SFDRAWRECT_HPP */