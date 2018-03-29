/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
** aaaah
*/

#include <criterion/criterion.h>
#include "src/std/Rect.hpp"

Test(RectS, get_values_from_values)
{
	arc::RectS r(1, 2, 3, 4);

	cr_assert(r.pos().x() == 1);
	cr_assert(r.pos().y() == 2);
	cr_assert(r.size().x() == 3);
	cr_assert(r.size().y() == 4);
	cr_assert(r.rpos().x() == 1);
	cr_assert(r.rpos().y() == 2);
	cr_assert(r.rsize().x() == 3);
	cr_assert(r.rsize().y() == 4);
}

Test(RectS, get_values_from_vertexes)
{
	arc::RectS r1(1, 2, 3, 4);
	arc::RectS r(r1.pos(), r1.size());

	cr_assert(r.pos().x() == 1);
	cr_assert(r.pos().y() == 2);
	cr_assert(r.size().x() == 3);
	cr_assert(r.size().y() == 4);
}

Test(RectS, get_values_from_rectf)
{
	arc::RectS r1(1, 2, 3, 4);
	arc::RectS r(r1);

	cr_assert(r.pos().x() == 1);
	cr_assert(r.pos().y() == 2);
	cr_assert(r.size().x() == 3);
	cr_assert(r.size().y() == 4);
}

Test(RectS, get_values_from_assign)
{
	arc::RectS r1(1, 2, 3, 4);
	arc::RectS r;
	r = r1;

	cr_assert(r.pos().x() == 1);
	cr_assert(r.pos().y() == 2);
	cr_assert(r.size().x() == 3);
	cr_assert(r.size().y() == 4);
}

Test(RectS, get_values_from_int_mult)
{
	arc::RectS r(1, 2, 3, 4);
	r = r * 2;

	cr_assert(r.pos().x() == 1);
	cr_assert(r.pos().y() == 2);
	cr_assert(r.size().x() == 3 * 2);
	cr_assert(r.size().y() == 4 * 2);
}

Test(RectS, get_values_from_vert_mult)
{
	arc::VertexS r1(2, 3);
	arc::RectS r(1, 2, 3, 4);
	r = r * r1;

	cr_assert(r.pos().x() == 1 * 2);
	cr_assert(r.pos().y() == 2 * 3);
	cr_assert(r.size().x() == 3 * 2);
	cr_assert(r.size().y() == 4 * 3);
}

Test(RectS, get_values_from_rect_mult)
{
	arc::RectS r1(1, 2, 3, 4);
	arc::RectS r(1, 2, 3, 4);
	r = r * r1;

	cr_assert(r.pos().x() == 1);
	cr_assert(r.pos().y() == 2 * 2);
	cr_assert(r.size().x() == 3 * 3);
	cr_assert(r.size().y() == 4 * 4);
}

Test(RectS, get_values_from_int_div)
{
	arc::RectS r(1, 2, 3, 4);
	r = r / 2;

	cr_assert(r.pos().x() == 1);
	cr_assert(r.pos().y() == 2);
	cr_assert(r.size().x() == 3 / 2);
	cr_assert(r.size().y() == 4 / 2);
}

Test(RectS, get_values_from_vert_div)
{
	arc::VertexS r1(2, 3);
	arc::RectS r(1, 2, 3, 4);
	r = r / r1;

	cr_assert_eq(r.pos().x(), 1 + 2 / 3);
	cr_assert_eq(r.pos().y(), 2 + 3 / 4);
	cr_assert_eq(r.size().x(), 3 / 2);
	cr_assert_eq(r.size().y(), 4 / 3);
}

Test(RectS, get_values_from_int_add)
{
	arc::RectS r(1, 2, 3, 4);
	r = r + 2;

	cr_assert(r.pos().x() == 1 + 2);
	cr_assert(r.pos().y() == 2 + 2);
	cr_assert(r.size().x() == 3);
	cr_assert(r.size().y() == 4);
}

Test(RectS, get_values_from_vert_add)
{
	arc::VertexS r1(2, 3);
	arc::RectS r(1, 2, 3, 4);
	r = r + r1;

	cr_assert_eq(r.pos().x(), 1 + 2);
	cr_assert_eq(r.pos().y(), 2 + 3);
	cr_assert_eq(r.size().x(), 3);
	cr_assert_eq(r.size().y(), 4);
}

Test(RectS, get_values_from_int_sub)
{
	arc::RectS r(1, 2, 3, 4);
	r = r - 2;

	cr_assert(r.pos().x() == 1 - 2);
	cr_assert(r.pos().y() == 2 - 2);
	cr_assert(r.size().x() == 3);
	cr_assert(r.size().y() == 4);
}

Test(RectS, get_values_from_vert_sub)
{
	arc::VertexS r1(2, 3);
	arc::RectS r(1, 2, 3, 4);
	r = r - r1;

	cr_assert_eq(r.pos().x(), 1 - 2);
	cr_assert_eq(r.pos().y(), 2 - 3);
	cr_assert_eq(r.size().x(), 3);
	cr_assert_eq(r.size().y(), 4);
}
