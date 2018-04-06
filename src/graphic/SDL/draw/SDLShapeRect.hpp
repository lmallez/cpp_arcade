//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SDLShapeRect.hpp
//

#ifndef CPP_ARCADE_SDLDRAWRECT_HPP
#define CPP_ARCADE_SDLDRAWRECT_HPP

#include <SDL2/SDL2_gfxPrimitives.h>
#include "src/graphic/SDL/SDLMainWindow.hpp"
#include "src/std/Rect.hpp"
#include "src/graphic/shape/ShapeRect.hpp"
#include "src/graphic/SDL/SDLShape.hpp"

namespace arc {
	class SDLShapeRect : public ShapeRect, public SDLShape {
	public:
		explicit SDLShapeRect(
			std::SPTR<IShape> parent = nullptr,
			const arc::Texture &texture = arc::Texture(),
			const RectF &rect = RectF(0, 0, 0, 0));
		explicit SDLShapeRect(const ShapeRect &shape);
		~SDLShapeRect() = default;

		virtual void draw() const override;
	};
}

#endif /* CPP_ARCADE_SDLDRAWRECT_HPP */