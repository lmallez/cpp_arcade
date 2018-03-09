//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// IGraphic.hpp
//

#ifndef CPP_ARCADE_IGRAPHIC_HPP
#define CPP_ARCADE_IGRAPHIC_HPP

#include <bits/unique_ptr.h>
#include "src/exception/Exception.hpp"

#define WNAME "Arcade"

namespace arc {
	class EventHandler;
	class IDraw;
	class IShapeLoader;

	class IGraphic {
	public:
		virtual ~IGraphic() = default;

		//virtual void catchEvent(EventHandler &event) = 0;
		//virtual void display(std::unique_ptr<IDraw> elem) = 0;
		//virtual IShapeLoader getLoader() = 0;
	};
}

#endif /* CPP_ARCADE_IGRAPHIC_HPP */