//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// TamagotchiGame.hpp
//

#ifndef CPP_ARCADE_TAMAGOTCHIGAME_HPP
#define CPP_ARCADE_TAMAGOTCHIGAME_HPP

#include "src/games/utils/Controller/SystemController.hpp"
#include "src/games/IGame.hpp"
#include "src/games/Tamagotchi/Tamago.hpp"

#define TAMAGO_ASSETS_DIR std::string(ASSETS_DIR + "/tamagotchi")

namespace arc {
	class TamagotchiGame : virtual public IGame,
	protected SystemController {
	public:
		static IGame &getInstance();

		std::shared_ptr<IShape> start() override;
		std::shared_ptr<IShape>
		update(EventHandler &event) override;

	private:
		TamagotchiGame();

		tamago::Tamago _tamago;
	};
}

#endif /* CPP_ARCADE_TAMAGOTCHIGAME_HPP */