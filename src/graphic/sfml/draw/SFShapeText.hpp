//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SFDrawText.hpp
//

#ifndef CPP_ARCADE_SFDRAWTEXT_HPP
#define CPP_ARCADE_SFDRAWTEXT_HPP

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "src/std/Rect.hpp"
#include "src/graphic/shape/ShapeText.hpp"
#include "src/graphic/sfml/SFShape.hpp"

#define SFML_TEXT_PADING 1.1

namespace arc {
	class SFShapeText : public ShapeText, public SFShape {
	public:
		explicit SFShapeText(
			std::shared_ptr<IShape> parent = nullptr,
			const arc::Texture &texture = arc::Texture(),
			const RectF &rect = RectF(0, 0, 0, 0),
			const std::string &text = 0);
		explicit SFShapeText(const ShapeText &shape);
		~SFShapeText() = default;

		virtual void draw() const override;
	};
}

#endif /* CPP_ARCADE_SFDRAWTEXT_HPP */
