/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
** aaaah
*/

#include <criterion/criterion.h>
#include "src/std/Color.hpp"

Test(Color, constr_and_destr_from_white)
{
	arc::Color c(arc::Color::White);
}

Test(Color, constr_and_destr_from_rgba)
{
	arc::Color c(0xff, 0xff, 0xff, 0xff);
	cr_assert(c.values() == 0xffffffff);
}

Test(Color, constr_from_values)
{
	arc::Color c(0xffffffff);
	cr_assert(c.values() == 0xffffffff);
}

Test(Color, white_values)
{
	arc::Color c(arc::Color::White);
	cr_assert(c.values() == 0xffffffff);
}

Test(Color, white_r)
{
	arc::Color c(arc::Color::White);
	cr_assert(c.r() == 0xff);
}

Test(Color, white_g)
{
	arc::Color c(arc::Color::White);
	cr_assert(c.g() == 0xff);
}

Test(Color, white_b)
{
	arc::Color c(arc::Color::White);
	cr_assert(c.b() == 0xff);
}

Test(Color, white_a)
{
	arc::Color c(arc::Color::White);
	cr_assert(c.a() == 0xff);
}
