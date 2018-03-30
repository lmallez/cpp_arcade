//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// BasicGame.hpp
//

#ifndef CPP_ARCADE_BASICGAME_HPP
#define CPP_ARCADE_BASICGAME_HPP

#include "src/games/SystemGame.hpp"
#include "src/graphic/shape/ShapeCircle.hpp"
#include "src/graphic/shape/ShapeText.hpp"
#include "src/graphic/shape/ShapeRect.hpp"
#include "../IGame.hpp"

namespace arc {
	class BasicGame : public virtual IGame, protected SystemGame {
	public:
		static IGame &getInstance();
		static void freeInstance();
		std::shared_ptr<IShape> start() override;
		std::shared_ptr<IShape> update(EventHandler &event) override;
	private:
		static arc::IGame *_instance;
		BasicGame();
		RectF playerPos;
		size_t frame = 0;
	};
}

#endif /* CPP_ARCADE_BASICGAME_HPP */