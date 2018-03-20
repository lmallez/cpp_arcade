//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// IGame.hpp
//

#ifndef CPP_ARCADE_IGAME_HPP
#define CPP_ARCADE_IGAME_HPP

#include "src/events/EventHandler.hpp"
#include "src/graphic/IShape.hpp"

namespace arc {
	class IGame {
	public:
		virtual std::shared_ptr<IShape> start() = 0;
		virtual std::shared_ptr<IShape> update(
			EventHandler &event) = 0;
	};
}

#endif /* CPP_ARCADE_IGAME_HPP */