//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SFShapeRect.hpp
//

#ifndef CPP_ARCADE_SFDRAWRECT_HPP
#define CPP_ARCADE_SFDRAWRECT_HPP

#include <SFML/Graphics/RectangleShape.hpp>
#include "src/std/Rect.hpp"
#include "src/graphic/shape/ShapeRect.hpp"
#include "src/graphic/sfml/SFShape.hpp"

namespace arc {
	class SFShapeRect : public ShapeRect, public SFShape {
	public:
		explicit SFShapeRect(
			std::shared_ptr<IShape> parent = nullptr,
			const arc::Texture &texture = arc::Texture(),
			const RectF &rect = RectF(0, 0, 0, 0));
		explicit SFShapeRect(const ShapeRect &shape);
		~SFShapeRect() = default;

		virtual void draw() const override;
	};
}

#endif /* CPP_ARCADE_SFDRAWRECT_HPP */