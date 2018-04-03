//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SnakeGame.hpp
//

#ifndef CPP_ARCADE_SNAKEGAME_HPP
#define CPP_ARCADE_SNAKEGAME_HPP

#include "src/games/Controller/SystemController.hpp"
#include "src/games/Controller/PlayerController.hpp"
#include "src/graphic/shape/ShapeCircle.hpp"
#include "src/graphic/shape/ShapeText.hpp"
#include "src/graphic/shape/ShapeRect.hpp"
#include "src/core/corebuild/CoreClock.hpp"
#include "Snake.hpp"
#include "../IGame.hpp"

#define MAP_SIZE 20

namespace arc {
	class SnakeGame : public virtual IGame, protected SystemController {
	public:
		static IGame &getInstance();
		static void freeInstance();

		std::shared_ptr<IShape> start() override;
		std::shared_ptr<IShape> update(EventHandler &event) override;

	protected:

		typedef void (SnakeGame::*SnakeGame_t)(EventHandler &event);
		std::unordered_map<KeyEvent::Key, std::pair<KeyEvent::Status, SnakeGame_t>> _snakeEvent;
		void assignKey(KeyEvent::Key, KeyEvent::Status status, SnakeGame_t);
		void execKey(EventHandler &event) override;
		void execKey(EventHandler &event, KeyEvent::Key) override;

	private:
		static SnakeGame *_instance;
		SnakeGame();

		RectF _map;
		snake::Snake _snake;

		VertexS _flowerPos;
		void _genFlower();

		CoreClock _clock;
		long _score = 0;
		void _move(EventHandler &event);
		void _move(EventHandler &event, snake::Snake &snake);

		bool _isOver;


		std::shared_ptr<arc::IShape> _game(EventHandler &event);
		std::shared_ptr<IShape> _drawSnake() const;

		std::shared_ptr<IShape> _gameOver(EventHandler &event);
	};
}

#endif /* CPP_ARCADE_SNAKEGAME_HPP */