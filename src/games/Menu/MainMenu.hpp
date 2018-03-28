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
#include "src/games/IGame.hpp"
#include "src/graphic/shape/ShapeCircle.hpp"
#include "src/graphic/shape/ShapeText.hpp"
#include "src/graphic/shape/ShapeRect.hpp"

#define DIR_GAME "../games"
#define DIR_GRAPHIC "../graphics"

#define TEXT_PADDING 0.2

namespace arc {
	class MainMenu : virtual public IGame {
	public:
		static std::unique_ptr<IGame> &getInstance();
		virtual std::shared_ptr<IShape> start() override;
		virtual std::shared_ptr<IShape> update(
			EventHandler &event) override;

	private:
		typedef void (arc::MainMenu::*aled_t)(arc::EventHandler &);
		std::map<arc::KeyEvent::Key, aled_t> _keyEvent;
		void assignKey(arc::KeyEvent::Key, aled_t);
		void execKey(arc::EventHandler &event);
		void execKey(arc::EventHandler &event, arc::KeyEvent::Key);

		std::shared_ptr<IShape> _displayListGraphic(const arc::RectF &pos);
		std::shared_ptr<IShape> _displayListGame(const arc::RectF &pos);

		arc::VertexS _userPos = arc::VertexS(0, 0);

		size_t _selectGraphic = 1;
		size_t _selectGame = 1;
		std::vector<std::string> _initListGraphic();
		std::vector<std::string> _initListGame();
		std::vector<std::string> _listGraphic;
		std::vector<std::string> _listGame;

		void _moveCol(arc::EventHandler &event);
		void _moveLineUp(arc::EventHandler &event);
		void _moveLineDown(arc::EventHandler &event);
		void _selectWord(arc::EventHandler &event);
	};
}

#endif /* CPP_ARCADE_MENU_HPP */