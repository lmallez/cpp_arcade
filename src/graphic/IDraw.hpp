/*
** EPITECH PROJECT, 2018
** cpp_arcade
** File description:
** IDraw.hpp
*/

#ifndef CPP_ARCADE_IDRAW_HPP
#define CPP_ARCADE_IDRAW_HPP

#include <bits/unique_ptr.h>
#include "src/std/Vertex.hpp"

namespace arc {
	class IDraw {
	public:
		virtual ~IDraw() = default;

		virtual void draw() = 0;

		virtual VertexI getPos() const = 0;
		virtual std::unique_ptr<IDraw> getParent() const = 0;
		virtual std::vector<std::unique_ptr<IDraw>> getChild() const = 0;
		virtual void addChild(std::unique_ptr<IDraw> child) = 0;
	};
}

#endif /* CPP_ARCADE_IDRAW_HPP */