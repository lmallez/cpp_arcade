//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SDLShape.hpp
//

#ifndef CPP_ARCADE_SDLTEST_HPP
#define CPP_ARCADE_SDLTEST_HPP

#include "src/graphic/shape/AShape.hpp"
#include "src/graphic/SDL/SDLGraphic.hpp"

#define SDLML_BORDER_SIZE 0.01

namespace arc {
	class SDLShape : virtual public IShape {
	public:
		SDLShape();

	protected:
		SDL_Rect winGeometry() const;
		SDL_Texture * getTexture(const std::string &) const;
	};
}

#endif /* CPP_ARCADE_SDLTEST_HPP */