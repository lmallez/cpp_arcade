//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// BasicGame.hpp
//

#ifndef CPP_ARCADE_BASICGAME_HPP
#define CPP_ARCADE_BASICGAME_HPP

#include "src/graphic/shape/ShapeCircle.hpp"
#include "src/graphic/shape/ShapeText.hpp"
#include "src/graphic/shape/ShapeRect.hpp"
#include "IGame.hpp"

namespace arc {
	class BasicGame : public virtual IGame {
	public:
		BasicGame();
		virtual std::shared_ptr<IShape> start() override;
		virtual std::shared_ptr<IShape> update(
			EventHandler &event) override;

	private:
		RectF playerPos;
	};
}

#endif /* CPP_ARCADE_BASICGAME_HPP */