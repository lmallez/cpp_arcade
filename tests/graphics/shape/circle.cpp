/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
** aaaah
*/

#include <memory>
#include <criterion/criterion.h>
#include "src/graphic/shape/ShapeCircle.hpp"

Test(ShapeCircle, base_values)
{
	arc::Texture t(arc::Color::White, arc::Color::Black);
	arc::RectF r(0, 0, 1, 1);
	std::unique_ptr<arc::IShape> c = std::make_unique<arc::ShapeCircle>(nullptr, t, r);
	cr_assert(c->nbChild() == 0);
}
