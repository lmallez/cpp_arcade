//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SolarFoxGame.hpp
//

#ifndef CPP_ARCADE_SOLARFOXGAME_HPP
#define CPP_ARCADE_SOLARFOXGAME_HPP

#include "src/games/utils/ScoreHandler.hpp"
#include "src/core/corebuild/CoreClock.hpp"
#include "src/games/utils/Controller/SystemController.hpp"
#include "src/games/IGame.hpp"
#include "Ship.hpp"
#include "Monster.hpp"
#include "AObject.hpp"
#include "MapManager.hpp"

#define SHOT_PROBA 20

namespace arc {
	class SolarFoxGame : virtual public IGame, protected SystemController {
	public:
		static IGame &getInstance();
		static void freeInstance();

		std::shared_ptr<IShape> start() override;
		std::shared_ptr<IShape> update(EventHandler &event) override;

	protected:
		typedef void (SolarFoxGame::*SolarFoxEvt_t)(EventHandler &event);
		std::unordered_map<KeyEvent::Key, std::pair<KeyEvent::Status, SolarFoxEvt_t>> _solarForEvent;
		void assignKey(KeyEvent::Key key, KeyEvent::Status status, SolarFoxEvt_t func);
		void execKey(EventHandler &event) override;
		void execKey(EventHandler &event, KeyEvent::Key key) override;

	private:
		SolarFoxGame();

		CoreClock _clock;
		solarfox::Ship _ship;
		std::vector<solarfox::Monster> _monster;
		std::vector<std::shared_ptr<solarfox::AMissile>> _monsterShot;
		std::vector<std::shared_ptr<solarfox::AMissile>> _playerShot;

		void _monsterMissileMove();
		void _playerMissileMove();
		bool _checkObject(const std::shared_ptr<solarfox::AMissile> &shot);

		template <typename T>
		static void deleteMissile(std::vector<std::shared_ptr<T>> &vec, size_t id);

		bool _isOver = false;
		std::shared_ptr<IShape> _game(EventHandler &event);
		std::shared_ptr<IShape> _gameOver(EventHandler &event);
		std::shared_ptr<IShape> _drawGame() const;

		void _shot(EventHandler &event);

		solarfox::MapManager _mapManager;
		std::vector<std::shared_ptr<solarfox::AObject>> _object;

		size_t _score;

		ScoreHandler _scoreboard;
	};
}

#endif /* CPP_ARCADE_SOLARFOXGAME_HPP */