//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SnakeGame.hpp
//

#ifndef CPP_ARCADE_SNAKEGAME_HPP
#define CPP_ARCADE_SNAKEGAME_HPP

#include "src/graphic/shape/ShapeCircle.hpp"
#include "src/graphic/shape/ShapeText.hpp"
#include "src/graphic/shape/ShapeRect.hpp"
#include "../IGame.hpp"

namespace arc {
	class SnakeGame : public virtual IGame {
	public:
		static std::unique_ptr<IGame> &getInstance();
		virtual std::shared_ptr<IShape> start() override;
		virtual std::shared_ptr<IShape> update(
			EventHandler &event) override;

	private:
		SnakeGame();
		RectF playerPos;
		size_t frame = 0;

		std::shared_ptr<arc::IShape> _map;
	};
}

#endif /* CPP_ARCADE_SNAKEGAME_HPP */