//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// CoreLoader.hpp
//

#ifndef CPP_ARCADE_CORELOADER_HPP
#define CPP_ARCADE_CORELOADER_HPP

#include <memory>
#include <src/core/loader/GameLoader.hpp>
#include <src/core/loader/LibLoader.hpp>
#include "CoreClock.hpp"

#define CLOCK_TIME 0.0016

namespace arc {
	class CoreBuild {
	public:
		explicit CoreBuild(const std::string &lib,
			const std::string &game = "");
		~CoreBuild();
		bool setGraphic(const std::string &name);
		void setGraphic();
		bool setGame(const std::string &name);
		void setGame();

		void start();
		void update();
		void menu();
		void run();

	private:
		bool _checkEvent(GameEvent &event);
		bool _menu = true;

		GameLoader _loaderGame;
		LibLoader _loaderGraphic;
		EventHandler _event;
		CoreClock _clock;
	};
}

#endif /* CPP_ARCADE_CORELOADER_HPP */