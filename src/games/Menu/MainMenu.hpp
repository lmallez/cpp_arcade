//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// Menu.hpp
//

#ifndef CPP_ARCADE_MENU_HPP
#define CPP_ARCADE_MENU_HPP

#include <vector>
#include <dirent.h>
#include <map>
#include "src/games/utils/Controller/SystemController.hpp"
#include "src/games/IGame.hpp"
#include "src/graphic/shape/ShapeCircle.hpp"
#include "src/graphic/shape/ShapeText.hpp"
#include "src/graphic/shape/ShapeRect.hpp"

#define TEXT_PADDING 0.2

namespace arc {
	class MainMenu : virtual public IGame, public SystemController {
		typedef void (arc::MainMenu::*MainMenuEvent_t)(arc::EventHandler &event);
	public:
		static IGame &getInstance();
		~MainMenu() = default;
		std::SPTR<IShape> start() override;
		std::SPTR<IShape> update(EventHandler &event) override;

	private:
		MainMenu();
		std::unordered_map<KeyEvent::Key, std::pair<KeyEvent::Status, MainMenuEvent_t>> _keyEvent;
		void assignKey(arc::KeyEvent::Key, arc::KeyEvent::Status status, MainMenuEvent_t);
		void execKey(arc::EventHandler &event);
		void execKey(arc::EventHandler &event, arc::KeyEvent::Key key);

		std::SPTR<arc::IShape> _startButton;
		std::SPTR<arc::IShape> _displayStartButton(EventHandler &event);
		std::SPTR<arc::IShape> _displayListGraphic(EventHandler &event, const arc::RectF &pos);
		std::SPTR<arc::IShape> _displayListGame(EventHandler &event, const arc::RectF &pos);
		arc::Texture _getListTexture(size_t pos, size_t selected, size_t col);

		arc::VertexS _userPos = arc::VertexS(0, 0);
		void _pressedStart(EventHandler &event);
		void _moveCol(EventHandler &event);
		void _moveUp(EventHandler &event);
		void _moveDown(EventHandler &event);
	};
}

#endif /* CPP_ARCADE_MENU_HPP */