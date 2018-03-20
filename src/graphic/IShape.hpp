/*
** EPITECH PROJECT, 2018
** cpp_arcade
** File description:
** IDraw.hpp
*/

#ifndef CPP_ARCADE_IDRAW_HPP
#define CPP_ARCADE_IDRAW_HPP

#include <memory>
#include "IShapeLoader.hpp"
#include "src/std/Rect.hpp"
#include "src/std/Vertex.hpp"
#include "src/std/Texture.hpp"

namespace arc {
	class IShape {
	public:
		virtual ~IShape() = default;

		virtual const std::shared_ptr<IShape> &getParent() const = 0;
		virtual IShape &getChild(size_t pos) const = 0;
		virtual size_t nbChild() const = 0;
		virtual void addChild(std::unique_ptr<IShape> child) = 0;
		virtual void addChild(std::shared_ptr<IShape> child) = 0;

		virtual void setTexture(const Texture &texture) = 0;
		virtual const Texture &getTexture() const = 0;
		virtual void setGeometry(const RectF &rect) = 0;
		virtual const RectF &getGeometry() const = 0;

		virtual arc::RectF winPos() const = 0;
		virtual void draw() const = 0;
		virtual std::unique_ptr<IShape> convert(const arc::IShapeLoader &loader) const = 0;

		virtual IShape &operator[](size_t pos) const = 0;
		virtual void operator<<(std::unique_ptr<IShape> child) = 0;
		virtual void operator<<(std::shared_ptr<IShape> child) = 0;

	protected:
		virtual void drawChild() const = 0;
	};
}

#endif /* CPP_ARCADE_IDRAW_HPP */