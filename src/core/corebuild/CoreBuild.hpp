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

#define CLOCK_TIME 0.016

namespace arc {
	class CoreBuild {
	public:
		CoreBuild(const std::string &lib = "",
			const std::string &game = "");
		bool setGraphic(const std::string &name);
		bool setGame(const std::string &name);

		void start();
		void update();
		void run();
		void menu();

	private:
		GameLoader _loaderGame;
		LibLoader _loaderGraphic;
		EventHandler _event;
		CoreClock _clock;
	};
}

#endif /* CPP_ARCADE_CORELOADER_HPP */