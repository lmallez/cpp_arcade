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

		virtual const std::SPTR<IShape> &getParent() const = 0;
		virtual IShape &getChild(size_t pos) const = 0;
		virtual size_t nbChild() const = 0;
		virtual void addChild(std::UPTR<IShape> child) = 0;
		virtual void addChild(std::SPTR<IShape> child) = 0;

		virtual void setTexture(const Texture &texture) = 0;
		virtual const Texture &getTexture() const = 0;
		virtual void setGeometry(const RectF &rect) = 0;
		virtual const RectF &getGeometry() const = 0;
		virtual void setText(const std::string &text) = 0;

		virtual arc::RectF winPos() const = 0;
		virtual void draw() const = 0;
		virtual std::UPTR<IShape> convert(
				const arc::IShapeLoader &loader) const = 0;

		virtual IShape &operator[](size_t pos) const = 0;
		virtual void operator<<(std::UPTR<IShape> child) = 0;
		virtual void operator<<(std::SPTR<IShape> child) = 0;

	protected:
		virtual void drawChild() const = 0;
	};
}

#endif /* CPP_ARCADE_IDRAW_HPP */
