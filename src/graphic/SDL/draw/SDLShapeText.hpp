//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SDLDrawText.hpp
//

#ifndef CPP_ARCADE_SDLDRAWTEXT_HPP
#define CPP_ARCADE_SDLDRAWTEXT_HPP

#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include "src/graphic/SDL/SDLMainWindow.hpp"
#include "src/std/Rect.hpp"
#include "src/graphic/shape/ShapeText.hpp"
#include "src/graphic/SDL/SDLShape.hpp"

#define SDL_TEXT_PADING 1.5

namespace arc {
	class SDLShapeText : public ShapeText, public SDLShape {
	public:
		explicit SDLShapeText(
			std::SPTR<IShape> parent = nullptr,
			const arc::Texture &texture = arc::Texture(),
			const RectF &rect = RectF(0, 0, 0, 0),
			const std::string &text = 0);
		explicit SDLShapeText(const ShapeText &shape);
		~SDLShapeText() = default;

		virtual void draw() const override;
	};
}

#endif /* CPP_ARCADE_SDLDRAWTEXT_HPP */