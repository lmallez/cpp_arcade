//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SFShapeCircle.hpp
//

#ifndef CPP_ARCADE_SFSHAPECIRCLE_HPP
#define CPP_ARCADE_SFSHAPECIRCLE_HPP

#include <SFML/Graphics/CircleShape.hpp>
#include "src/std/Rect.hpp"
#include "src/graphic/shape/ShapeCircle.hpp"
#include "src/graphic/sfml/SFShape.hpp"

namespace arc {
	class SFShapeCircle : public ShapeCircle, public SFShape {
	public:
		explicit SFShapeCircle(
			std::shared_ptr<IShape> parent = nullptr,
			const arc::Texture &texture = arc::Texture(),
			const VertexF &pos = VertexF(0, 0),
			float radius = 0);
		explicit SFShapeCircle(
			std::shared_ptr<IShape> parent = nullptr,
			const arc::Texture &texture = arc::Texture(),
			const RectF &rect = RectF(0, 0, 0, 0));
		explicit SFShapeCircle(const ShapeCircle &shape);
		~SFShapeCircle() = default;

		virtual void draw() const override;
	};
}

#endif /* CPP_ARCADE_SFSHAPECIRCLE_HPP */