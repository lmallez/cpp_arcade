/*
** EPITECH PROJECT, 2018
** cpp_arcade
** File description:
** IDraw.hpp
*/

#ifndef CPP_ARCADE_IDRAW_HPP
#define CPP_ARCADE_IDRAW_HPP

#include <memory>
#include <src/std/Rect.hpp>
#include "src/std/Vertex.hpp"

namespace arc {
	class IDraw {
	public:
		virtual ~IDraw() = default;

		virtual std::shared_ptr<IDraw> &getParent() = 0;
		virtual IDraw &getChild(size_t pos) = 0;
		virtual size_t nbChild() const = 0;
		virtual void addChild(std::unique_ptr<IDraw> child) = 0;
		virtual RectF getGeometry() const = 0;
		virtual RectF &getrGeometry() = 0;
		virtual void setGeometry(const RectF &rect) = 0;

		virtual RectI winPos() const = 0;

		virtual void draw() const = 0;
		virtual std::unique_ptr<IDraw> clone() = 0;
	};
}

#endif /* CPP_ARCADE_IDRAW_HPP */