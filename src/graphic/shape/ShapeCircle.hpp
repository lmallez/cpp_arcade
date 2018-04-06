//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// ShapeCircle.hpp
//

#ifndef CPP_ARCADE_SHAPECIRCLE_HPP
#define CPP_ARCADE_SHAPECIRCLE_HPP

#include <memory>
#include "src/graphic/shape/AShape.hpp"
#include "src/std/Rect.hpp"

namespace arc {
	class ShapeCircle : public AShape {
	public:
		ShapeCircle(
			const std::SPTR<IShape> &parent,
			const Texture &texture,
			VertexF pos,
			float radius
		);
		ShapeCircle(
			const std::SPTR<IShape> &parent,
			const Texture &texture,
			RectF geometry);
		ShapeCircle(const ShapeCircle &ex);

		virtual std::UPTR<IShape>
		convert(const arc::IShapeLoader &loader) const override;
	};
}

#endif /* CPP_ARCADE_SHAPECIRCLE_HPP */