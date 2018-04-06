//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// ShapeRect.hpp
//

#ifndef CPP_ARCADE_SHAPERECT_HPP
#define CPP_ARCADE_SHAPERECT_HPP

#include <memory>
#include "src/graphic/shape/AShape.hpp"
#include "src/std/Rect.hpp"

namespace arc {
	class ShapeRect : public AShape {
	public:
		ShapeRect(
			const std::SPTR<IShape> &parent,
			const Texture &texture,
			RectF geometry);
		ShapeRect(const ShapeRect &ex);

		virtual std::UPTR<IShape>
		convert(const arc::IShapeLoader &loader) const override;
	};
}

#endif /* CPP_ARCADE_SHAPERECT_HPP */