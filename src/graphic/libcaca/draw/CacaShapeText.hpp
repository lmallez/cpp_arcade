/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
** aaaah
*/

#ifndef CPP_ARCADE_CacaDRAWTEXT_HPP
#define CPP_ARCADE_CacaDRAWTEXT_HPP

#include <caca.h>
#include "src/std/Rect.hpp"
#include "src/std/Texture.hpp"
#include "src/graphic/shape/ShapeText.hpp"
#include "src/graphic/libcaca/CacaShape.hpp"
#include "src/graphic/libcaca/CacaMainWindow.hpp"

#define CacaML_TEXT_PADING 1.5

namespace arc {
	class CacaShapeText : public ShapeText, public CacaShape {
	public:
		explicit CacaShapeText(
			std::SPTR<IShape> parent = nullptr,
			const arc::Texture &texture = arc::Texture(),
			const RectF &rect = RectF(0, 0, 0, 0),
			const std::string &text = 0);
		explicit CacaShapeText(const ShapeText &shape);
		~CacaShapeText() = default;

		virtual void draw() const override;
	};
}

#endif /* CPP_ARCADE_CacaDRAWTEXT_HPP */
