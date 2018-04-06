//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SnakeGame.hpp
//

#ifndef CPP_ARCADE_SNAKEGAME_HPP
#define CPP_ARCADE_SNAKEGAME_HPP

#include <vector>
#include "src/games/utils/Controller/SystemController.hpp"
#include "src/games/utils/Controller/PlayerController.hpp"
#include "src/games/utils/ScoreHandler.hpp"
#include "src/graphic/shape/ShapeCircle.hpp"
#include "src/graphic/shape/ShapeText.hpp"
#include "src/graphic/shape/ShapeRect.hpp"
#include "src/core/corebuild/CoreClock.hpp"
#include "Snake.hpp"
#include "src/games/IGame.hpp"
#include "MapManager.hpp"
#include "src/main.hpp"

#define MAP_SIZE 20
#define NIBBLER_ASSETS_DIR std::string(ASSETS_DIR) + "/nibbler"

#define SPECIAL_FLOWER_RATE 5
#define SPECIAL_FLOWER_DURATION 20

namespace arc {
	class SnakeGame : public virtual IGame, protected SystemController {
	public:
		static IGame &getInstance();
		static void freeInstance();

		std::SPTR<IShape> start() override;
		std::SPTR<IShape> update(EventHandler &event) override;

	protected:

		typedef void (SnakeGame::*SnakeEvt_t)(EventHandler &event);
		std::unordered_map<KeyEvent::Key, std::pair<KeyEvent::Status, SnakeEvt_t>> _snakeEvent;
		void assignKey(KeyEvent::Key, KeyEvent::Status status, SnakeEvt_t);
		void execKey(EventHandler &event) override;
		void execKey(EventHandler &event, KeyEvent::Key key) override;

	private:
		SnakeGame();

		ScoreHandler _scoreboard;
		RectF _map;
		snake::Snake _snake;
		VertexS _flowerPos;
		void _genFlower();
		std::pair<VertexS, size_t> _specialFlower;
		void _genSpecialFlower();
		CoreClock _clock;
		long _score = 0;
		void _move(EventHandler &event);
		void _move(EventHandler &event, snake::Snake &snake);
		bool _isOver;
		std::SPTR<arc::IShape> _game(EventHandler &event);
		std::SPTR<IShape> _drawSnake() const;
		std::SPTR<IShape> _drawObstacle() const;

		bool _collideObstacle(const VertexS &pos) const;

		std::SPTR<IShape> _gameOver(EventHandler &event);

		snake::MapManager _mapManager;
		std::vector<arc::VertexS> _obstacle;
	};
}

#endif /* CPP_ARCADE_SNAKEGAME_HPP */