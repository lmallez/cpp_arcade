//
// EPITECH PROJECT, 2018
// cpp_arcade - IShape.hpp
// File description:
// Created by Faudil Puttilli
//

#ifndef CPP_ARCADE_ISHAPE_HPP
#define CPP_ARCADE_ISHAPE_HPP

#include <memory>

namespace arc
{
	class IDraw;
	class IShapeLoader;

	class IShape
	{
	public:
		virtual ~IShape() {};

		virtual std::unique_ptr<IDraw>
		convert(std::unique_ptr<IShapeLoader> &) = 0;
		virtual std::unique_ptr<IShape> clone() = 0;
		virtual std::unique_ptr<IShape> getChild(size_t id) = 0;

		virtual std::unique_ptr<IShape> operator[](size_t id) = 0;
	};

}

#endif //CPP_ARCADE_ISHAPE_HPP
