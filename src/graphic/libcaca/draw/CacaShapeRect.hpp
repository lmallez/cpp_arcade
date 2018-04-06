/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
** aaaah
*/

#ifndef CPP_ARCADE_CacaDRAWRECT_HPP
#define CPP_ARCADE_CacaDRAWRECT_HPP

#include <caca.h>
#include "src/std/Rect.hpp"
#include "src/graphic/shape/ShapeRect.hpp"
#include "src/graphic/libcaca/CacaShape.hpp"
#include "src/graphic/libcaca/CacaMainWindow.hpp"
#include "src/graphic/libcaca/CacaImage.hpp"

namespace arc {
	class CacaShapeRect : public ShapeRect, public CacaShape {
	public:
		explicit CacaShapeRect(
			std::SPTR<IShape> parent = nullptr,
			const arc::Texture &texture = arc::Texture(),
			const RectF &rect = RectF(0, 0, 0, 0));
		bool drawFromFile() const;
		explicit CacaShapeRect(const ShapeRect &shape);
		~CacaShapeRect() = default;

		virtual void draw() const override;
	};
}

#endif /* CPP_ARCADE_CacaDRAWRECT_HPP */
