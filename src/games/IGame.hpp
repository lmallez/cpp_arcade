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
		virtual std::SPTR<IShape> start() = 0;
		virtual std::SPTR<IShape> update(
			EventHandler &event) = 0;
	};
}

#endif /* CPP_ARCADE_IGAME_HPP */