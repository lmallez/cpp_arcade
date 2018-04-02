//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// ShapeEmpty.hpp
//

#ifndef CPP_ARCADE_SHAPEEMPTY_HPP
#define CPP_ARCADE_SHAPEEMPTY_HPP

#include <memory>
#include "src/graphic/shape/AShape.hpp"
#include "src/std/Rect.hpp"

namespace arc {
	class ShapeContainer : public AShape {
	public:
		explicit ShapeContainer(
			const std::shared_ptr<IShape> &parent = nullptr,
			const RectF &geometry = arc::RectF(0, 0, 1, 1));
		ShapeContainer(const ShapeContainer &ex);

		virtual std::unique_ptr<IShape>
		convert(const arc::IShapeLoader &loader) const override;
	};
}

#endif /* CPP_ARCADE_SHAPEEMPTY_HPP */