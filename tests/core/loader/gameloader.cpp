/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
** aaaah
*/

#include <criterion/criterion.h>
#include "src/core/loader/GameLoader.hpp"
#include "src/exception/Exception.hpp"

Test(GameLoader, creation_and_loading)
{
	arc::GameLoader l;
	arc::GameLoader l1("./games/libGAME_SNAKE.so");
	arc::GameLoader l2("aled");
	cr_assert(!l);
	cr_assert(!(!l1));
	cr_assert(!l2);
	cr_assert(!(l.unload()));
	try {
		l.getIGame();
	} catch (arc::Exception e) {
		cr_assert(std::string(e.what()) == "run: Invalid Game library");
	}
	l1.getIGame();
	cr_assert(l1.unload());
	cr_assert(l.load("lib/libGRAPHIC_SFML.so"));
}
