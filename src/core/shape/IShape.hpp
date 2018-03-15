//
// EPITECH PROJECT, 2018
// cpp_arcade - IShape.hpp
// File description:
// Created by Faudil Puttilli
//

#ifndef CPP_ARCADE_ISHAPE_HPP
#define CPP_ARCADE_ISHAPE_HPP

#include <memory>
#include <src/std/Texture.hpp>
#include "../../graphic/IDraw.hpp"

namespace arc
{
	class IShapeLoader;

	class IShape
	{
	public:
		virtual ~IShape() = default;
		virtual std::unique_ptr<IDraw>
		convert(std::unique_ptr<IShapeLoader> &) = 0;
		virtual std::unique_ptr<IShape> clone() const = 0;
		virtual IShape &getChild(size_t id) = 0;
		virtual IShape &operator[](size_t id) = 0;
		virtual void addChild(std::unique_ptr<IShape>) = 0;
		virtual void operator<<(std::unique_ptr<IShape>) = 0;
		virtual size_t getChildNbr() const = 0;
		virtual bool operator!() const = 0;
		virtual arc::Texture getTexture() const = 0;
		virtual void setTexture(const arc::Texture &) = 0;
	};
}

#endif //CPP_ARCADE_ISHAPE_HPP
