/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
** aaaah
*/

#include <criterion/criterion.h>
#include "src/std/Texture.hpp"

Test(Texture, creation)
{
	arc::Texture t(arc::Color::White, arc::Color::Black);
	arc::Texture t1("aled");
	arc::Texture t2(t);
	t = t2;
}

Test(Texture, values)
{
	arc::Texture t(arc::Color::White, arc::Color::Black);
	arc::Texture t1("aled");
	arc::Texture t2(t);
	t = t2;
	cr_assert(t.lineColor().values() == arc::Color::Black.values());
	cr_assert(t.bgColor().values() == arc::Color::White.values());
	cr_assert(t1.getFilePath() == "aled");
	cr_assert(t2.lineColor().values() == arc::Color::Black.values());
	cr_assert(t2.bgColor().values() == arc::Color::White.values());
}
