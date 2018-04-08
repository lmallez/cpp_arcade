//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// WolfGame.hpp
//

#ifndef CPP_ARCADE_WOLFGAME_HPP
#define CPP_ARCADE_WOLFGAME_HPP

#include <src/games/utils/Controller/SystemController.hpp>
#include "src/games/IGame.hpp"
#include "src/games/Wolf3D/Map.hpp"
#include "src/games/Wolf3D/Player.hpp"
#include "src/games/Wolf3D/Ray.hpp"

#define NB_RAY 100
#define ANGLE 120
#define SPEED float(0.01)

namespace arc {
	class WolfGame : public IGame, protected SystemController {
	public:
		static IGame &getInstance();

		std::shared_ptr<IShape> start() override;
		std::shared_ptr<IShape> update(EventHandler &event) override;

	protected:

		typedef void (WolfGame::*WolfEvt_t)(EventHandler &event);
		std::unordered_map<KeyEvent::Key,
			std::pair<KeyEvent::Status, WolfEvt_t>> _wolfEvent;
		void assignKey(KeyEvent::Key,
			KeyEvent::Status status, WolfEvt_t);
		void execKey(EventHandler &event) override;
		void execKey(EventHandler &event, KeyEvent::Key key) override;

	private:
		WolfGame();

		wolf::Map _map;
		wolf::Player _player;
		std::vector<std::SPTR<wolf::Ray>> _ray;

		void _moveUp(EventHandler &event);
		void _moveDown(EventHandler &event);
		void _moveLeft(EventHandler &event);
		void _moveRight(EventHandler &event);
	};
}

#endif /* CPP_ARCADE_WOLFGAME_HPP */