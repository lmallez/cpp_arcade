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

#define KEY_ZQSD {arc::KeyEvent::Z, arc::KeyEvent::Q, arc::KeyEvent::S, arc::KeyEvent::D}
#define KEY_WASD {arc::KeyEvent::W, arc::KeyEvent::A, arc::KeyEvent::S, arc::KeyEvent::D}
#define KEY_ARROW {arc::KeyEvent::UP, arc::KeyEvent::LEFT, arc::KeyEvent::RIGHT, arc::KeyEvent::DOWN}

namespace arc {
	class PlayerController {
		typedef void (PlayerController::*playerController_t)(EventHandler &event);
	public:
		enum Direction {
			NONE,
			UP,
			DOWN,
			LEFT,
			RIGHT
		};

		explicit PlayerController(
			const VertexF &speed = arc::VertexF(1, 1),
			arc::KeyEvent::Status execStatus = arc::KeyEvent::JUSTPRESSED,
			const VertexF &initialPos = VertexF(0, 0),
			const std::pair<bool, RectF> &limit = {false, RectF(0, 0, 0, 0)},
			std::array<KeyEvent::Key, 4> key = KEY_ZQSD);

		virtual void assignKey(arc::KeyEvent::Key key,
			arc::KeyEvent::Status status,
			arc::PlayerController::playerController_t func);
		virtual void execKey(EventHandler &event);
		virtual void execKey(EventHandler &event, KeyEvent::Key key);

		arc::VertexF _pCtrlSpeed;
		arc::VertexF _pCtrlPos;
		std::pair<bool, RectF> _pCtrlLimit;
		Direction _pCtrlDir = NONE;
		bool _pCtrlHaveMove = false;

		void _moveUp(EventHandler &event);
		void _moveLeft(EventHandler &event);
		void _moveDown(EventHandler &event);
		void _moveRigth(EventHandler &event);

	private:
		std::unordered_map<KeyEvent::Key, std::pair<KeyEvent::Status, playerController_t>> _playerKey;
	};
}

#endif /* CPP_ARCADE_PLAYERCONTROLLER_HPP */