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

#define DIR_GAME "../games"
#define DIR_GRAPHIC "../graphics"

namespace arc {
	class GameEvent {
	public:
		GameEvent();

		std::vector<std::string> loadListGames();
		std::vector<std::string> loadListGraphics();
		const std::vector<std::string> &getListGames() const;
		const std::vector<std::string> &getListGraphics() const;

		const std::pair<std::string, bool> &getReloadGame() const;
		void
		setReloadGame(const std::pair<std::string, bool> &reloadGame);
		void setReloadGame(const std::string &first, bool second);
		const std::pair<std::string, bool> &getReloadGraphic() const;
		void setReloadGraphic(
			const std::pair<std::string, bool> &newReloadGraphic);
		void setReloadGraphic(const std::string &first, bool second);
		bool isMenu() const;
		void setMenu(bool menu);
		bool isExit() const;
		void setExit(bool exit);

	private:
		std::vector<std::string> _listGames;
		std::vector<std::string> _listGraphics;
		std::pair<std::string, bool> _reloadGame;
		std::pair<std::string, bool> _reloadGraphic;
		bool menu;
		bool exit;
	};
}

#endif /* CPP_ARCADE_GAMEEVENT_HPP */