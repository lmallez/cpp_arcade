//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// BasicGame.hpp
//

#ifndef CPP_ARCADE_BASICGAME_HPP
#define CPP_ARCADE_BASICGAME_HPP

#include "src/games/utils/Controller/PlayerController.hpp"
#include "src/games/utils/Controller/SystemController.hpp"
#include "src/graphic/shape/ShapeCircle.hpp"
#include "src/graphic/shape/ShapeText.hpp"
#include "src/graphic/shape/ShapeRect.hpp"
#include "src/games/IGame.hpp"

namespace arc {
	class BasicGame : public virtual IGame,
		protected SystemController, protected PlayerController {
		typedef void (arc::BasicGame::*BasicGameEvent_t)
			(arc::EventHandler &event);
	public:
		static IGame &getInstance();
		static void freeInstance();
		std::SPTR<IShape> start() override;
		std::SPTR<IShape> update(EventHandler &event) override;

	private:
		static arc::IGame *_instance;
		BasicGame();

		std::unordered_map<KeyEvent::Key,
			std::pair<KeyEvent::Status, BasicGameEvent_t>>
			_keyEvent;
		void assignKey(arc::KeyEvent::Key key,
			arc::KeyEvent::Status status, BasicGameEvent_t func);
		void execKey(arc::EventHandler &event);
		void execKey(arc::EventHandler &event, arc::KeyEvent::Key key);
		RectF _playerPos;
		float _grownCoef = 0.001;
		size_t _frame = 0;

		void _startGrown(arc::EventHandler &event);
		void _stopGrown(arc::EventHandler &event);
		void _unGrown(arc::EventHandler &event);
	};
}

#endif /* CPP_ARCADE_BASICGAME_HPP */