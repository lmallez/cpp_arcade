/*
** EPITECH PROJECT, 2018
** cpp_arcade
** File description:
** IDraw.hpp
*/

#ifndef CPP_ARCADE_IDRAW_HPP
#define CPP_ARCADE_IDRAW_HPP

#include <memory>
#include <src/core/shape/IShape.hpp>
#include "src/std/Rect.hpp"
#include "src/std/Vertex.hpp"

namespace arc {
	class IShape;

	class IDraw {
	public:
		virtual ~IDraw() = default;

		virtual const std::shared_ptr<IDraw> &getParent() const = 0;
		virtual IDraw &getChild(size_t pos) = 0;
		virtual size_t nbChild() const = 0;
		virtual void addChild(std::unique_ptr<IDraw> child) = 0;
		virtual RectF getGeometry() const = 0;
		virtual RectF &getrGeometry() = 0;
		virtual void setGeometry(const RectF &rect) = 0;
		virtual void setTexture(const Texture &texture) = 0;
		virtual RectF winPos() const = 0;
		virtual void draw() const = 0;
		virtual std::unique_ptr<IDraw> clone() = 0;
		virtual const IDraw &load(const std::shared_ptr<IShape> &model) = 0;
	};
}

#endif /* CPP_ARCADE_IDRAW_HPP */