//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// PlayerController.hpp
//


#ifndef CPP_ARCADE_PLAYERCONTROLLER_HPP
#define CPP_ARCADE_PLAYERCONTROLLER_HPP

#include <unordered_map>
#include <algorithm>
#include "src/games/IGame.hpp"

#define KEY_ZQSD {KeyEvent::Z, KeyEvent::Q, KeyEvent::S, KeyEvent::D}
#define KEY_WASD {KeyEvent::W, KeyEvent::A, KeyEvent::S, KeyEvent::D}
#define KEY_ARROW {KeyEvent::UP, KeyEvent::LEFT, KeyEvent::RIGHT, KeyEvent::DOWN}

namespace arc {
	class PlayerController {
		typedef void (PlayerController::*playerController_t)
			(EventHandler &event);
	protected:

		explicit PlayerController(
			const VertexF &speed = VertexF(1, 1),
			KeyEvent::Status execStatus = KeyEvent::JUSTPRESSED,
			bool canGoBack = false,
			const VertexF &initialPos = VertexF(0, 0),
			const std::pair<bool, RectF> &limit = {false,
				RectF(0, 0, 0, 0)},
			std::array<KeyEvent::Key, 4> key = KEY_ZQSD
		);

		virtual void assignKey(KeyEvent::Key key,
			KeyEvent::Status status,
			PlayerController::playerController_t func);
		virtual void execKey(EventHandler &event);
		virtual void execKey(EventHandler &event, KeyEvent::Key key);

		bool _pCtrlCanGoBack = true;

		VertexF _pCtrlSpeed;
		VertexF _pCtrlPos;
		std::pair<bool, RectF> _pCtrlLimit;
		Direction _pCtrlDir = NONE;
		bool _pCtrlHaveMove = false;

		void _moveDir(EventHandler &event,
			std::pair<bool, Direction> dir = {false, NONE},
			std::pair<bool, VertexF> speed = {false, {0, 0}});

		void _moveUp(EventHandler &event);
		void _moveLeft(EventHandler &event);
		void _moveDown(EventHandler &event);
		void _moveRigth(EventHandler &event);

	private:
		std::unordered_map<KeyEvent::Key,
			std::pair<KeyEvent::Status,
				playerController_t>> _playerKey;
	};
}

#endif /* CPP_ARCADE_PLAYERCONTROLLER_HPP */
