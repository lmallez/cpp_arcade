//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SDLShapeCircle.hpp
//

#ifndef CPP_ARCADE_SDLSHAPECIRCLE_HPP
#define CPP_ARCADE_SDLSHAPECIRCLE_HPP

#include <SDL2/SDL2_gfxPrimitives.h>
#include "src/std/Rect.hpp"
#include "src/graphic/shape/ShapeCircle.hpp"
#include "src/graphic/SDL/SDLShape.hpp"

namespace arc {
	class SDLShapeCircle : public ShapeCircle, public SDLShape {
	public:
		explicit SDLShapeCircle(
			std::SPTR<IShape> parent = nullptr,
			const arc::Texture &texture = arc::Texture(),
			const VertexF &pos = VertexF(0, 0),
			float radius = 0);
		explicit SDLShapeCircle(
			std::SPTR<IShape> parent = nullptr,
			const arc::Texture &texture = arc::Texture(),
			const RectF &rect = RectF(0, 0, 0, 0));
		explicit SDLShapeCircle(const ShapeCircle &shape);
		~SDLShapeCircle() = default;

		virtual void draw() const override;
	};
}

#endif /* CPP_ARCADE_SDLSHAPECIRCLE_HPP */