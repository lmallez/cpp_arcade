//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// GameEvent.hpp
//

#ifndef CPP_ARCADE_GAMEEVENT_HPP
#define CPP_ARCADE_GAMEEVENT_HPP

#include <vector>
#include <string>
#include "src/main.hpp"

namespace arc {
	class GameEvent {
	public:
		GameEvent(
			const std::string &graphic,
			const std::string &game
		);

		std::vector<std::string> loadListGames();
		std::vector<std::string> loadListGraphics();
		const std::vector<std::string> &getListGames() const;
		const std::vector<std::string> &getListGraphics() const;

		bool isMenu() const;
		void setMenu(bool menu);
		bool isExit() const;
		void setExit(bool exit);

		void prevGame();
		void nextGame();
		void setGame();
		void setGame(size_t pos);

		void prevGraphic();
		void nextGraphic();
		void setGraphic();
		void setGraphic(size_t pos);

		std::pair<std::string, bool> & getReloadGame();
		std::pair<std::string, bool> & getReloadGraphic();

		size_t getPosGame() const;
		size_t getPosGraphic() const;

		void setPlayerName(const std::string &name);
		const std::string &playerName() const;

	private:
		size_t _posGame = 0;
		size_t _posGraphic = 0;

		std::vector<std::string> _listGames;
		std::vector<std::string> _listGraphics;
		std::pair<std::string, bool> _reloadGame;
		std::pair<std::string, bool> _reloadGraphic;
		bool _menu;
		bool _exit;

		std::string _playerName = "Undefined";
	};
}

#endif /* CPP_ARCADE_GAMEEVENT_HPP */
