/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
** aaaah
*/

#include <criterion/criterion.h>
#include "src/core/loader/LibLoader.hpp"
#include "src/exception/Exception.hpp"

Test(LibLoader, creation_and_loading)
{
	arc::LibLoader l;
	arc::LibLoader l1("./lib/lib_arcade_caca.so");
	arc::LibLoader l2("aled");
	cr_assert(!l);
	cr_assert(!(!l1));
	cr_assert(!l2);
	cr_assert(!(l.unload()));
	try {
		l.getIGraphic();
	} catch (arc::Exception e) {
		cr_assert(std::string(e.what()) == "run: Invalid Graphic library");
	}
	l1.getIGraphic();
	cr_assert(l1.unload());
	cr_assert(l.load("lib/lib_arcade_sdl.so"));
}
