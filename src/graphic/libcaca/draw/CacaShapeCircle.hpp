/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
** aaaah
*/

#ifndef CPP_ARCADE_CacaSHAPECIRCLE_HPP
#define CPP_ARCADE_CacaSHAPECIRCLE_HPP

#include <caca.h>
#include "src/std/Rect.hpp"
#include "src/graphic/shape/ShapeCircle.hpp"
#include "src/graphic/libcaca/CacaShape.hpp"
#include "src/graphic/libcaca/CacaImage.hpp"
#include "src/graphic/libcaca/CacaMainWindow.hpp"

namespace arc {
	class CacaShapeCircle : public ShapeCircle, public CacaShape {
	public:
		explicit CacaShapeCircle(
			std::SPTR<IShape> parent = nullptr,
			const arc::Texture &texture = arc::Texture(),
			const VertexF &pos = VertexF(0, 0),
			float radius = 0);
		explicit CacaShapeCircle(
			std::SPTR<IShape> parent = nullptr,
			const arc::Texture &texture = arc::Texture(),
			const RectF &rect = RectF(0, 0, 0, 0));
		explicit CacaShapeCircle(const ShapeCircle &shape);
		~CacaShapeCircle() = default;

		bool drawFromFile() const;
		virtual void draw() const override;
	};
}

#endif /* CPP_ARCADE_CacaSHAPECIRCLE_HPP */
