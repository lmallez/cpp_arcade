//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// IGraphic.hpp
//

#ifndef CPP_ARCADE_IGRAPHIC_HPP
#define CPP_ARCADE_IGRAPHIC_HPP

#include <memory>
#include <src/core/shape/IShape.hpp>
#include "src/exception/Exception.hpp"
#include "IDrawLoader.hpp"

#define WNAME "Arcade"

namespace arc {
	class EventHandler;
	class IDraw;

	class IGraphic {
	public:
		virtual ~IGraphic() = default;

		virtual const IDrawLoader &getDrawLoader() const = 0;
		virtual void draw(const std::shared_ptr<IShape> &shape) const = 0;
		virtual void display() const = 0;
	};
}

#endif /* CPP_ARCADE_IGRAPHIC_HPP */