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
#include "src/games/IGame.hpp"
#include "src/graphic/shape/ShapeCircle.hpp"
#include "src/graphic/shape/ShapeText.hpp"
#include "src/graphic/shape/ShapeRect.hpp"

#define DIR_GAME "../games"
#define DIR_GRAPHIC "../graphics"

namespace arc {
	class MainMenu : public virtual IGame {
	public:
		static std::unique_ptr<IGame> &getInstance();
		virtual std::shared_ptr<IShape> start() override;
		virtual std::shared_ptr<IShape> update(
			EventHandler &event) override;

	private:
		std::shared_ptr<IShape> _displayListGraphic(const arc::RectF &pos);
		std::shared_ptr<IShape> _displayListGame(const arc::RectF &pos);

		std::vector<std::string> _initListGraphic();
		std::vector<std::string> _initListGame();
		std::vector<std::string> _listGraphic;
		std::vector<std::string> _listGame;
	};
}

#endif /* CPP_ARCADE_MENU_HPP */