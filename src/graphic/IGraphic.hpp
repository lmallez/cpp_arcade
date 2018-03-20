//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// IGraphic.hpp
//

#ifndef CPP_ARCADE_IGRAPHIC_HPP
#define CPP_ARCADE_IGRAPHIC_HPP

#include <memory>
#include <src/std/Vertex.hpp>
#include "src/exception/Exception.hpp"

#define WNAME "Arcade"

namespace arc {
	class EventHandler;
	class IShape;

	class IGraphic {
	public:
		virtual ~IGraphic() = default;
		virtual void display() const = 0;
		virtual arc::VertexF getSize() const = 0;
	};
}

#endif /* CPP_ARCADE_IGRAPHIC_HPP */