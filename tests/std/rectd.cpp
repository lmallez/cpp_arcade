/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
** aaaah
*/

#include <criterion/criterion.h>
#include "src/std/Rect.hpp"

Test(RectD, get_values_from_values)
{
	arc::RectD r(1, 2, 3, 4);

	cr_assert(r.pos().x() == 1);
	cr_assert(r.pos().y() == 2);
	cr_assert(r.size().x() == 3);
	cr_assert(r.size().y() == 4);
	cr_assert(r.rpos().x() == 1);
	cr_assert(r.rpos().y() == 2);
	cr_assert(r.rsize().x() == 3);
	cr_assert(r.rsize().y() == 4);
}

Test(RectD, get_values_from_vertexes)
{
	arc::RectD r1(1, 2, 3, 4);
	arc::RectD r(r1.pos(), r1.size());

	cr_assert(r.pos().x() == 1);
	cr_assert(r.pos().y() == 2);
	cr_assert(r.size().x() == 3);
	cr_assert(r.size().y() == 4);
}

Test(RectD, get_values_from_rectf)
{
	arc::RectD r1(1, 2, 3, 4);
	arc::RectD r(r1);

	cr_assert(r.pos().x() == 1);
	cr_assert(r.pos().y() == 2);
	cr_assert(r.size().x() == 3);
	cr_assert(r.size().y() == 4);
}

Test(RectD, get_values_from_assign)
{
	arc::RectD r1(1, 2, 3, 4);
	arc::RectD r;
	r = r1;

	cr_assert(r.pos().x() == 1);
	cr_assert(r.pos().y() == 2);
	cr_assert(r.size().x() == 3);
	cr_assert(r.size().y() == 4);
}

Test(RectD, get_values_from_double_mult)
{
	arc::RectD r(1, 2, 3, 4);
	r = r * 2;

	cr_assert(r.pos().x() == 1);
	cr_assert(r.pos().y() == 2);
	cr_assert(r.size().x() == 3 * 2);
	cr_assert(r.size().y() == 4 * 2);
}

Test(RectD, get_values_from_vert_mult)
{
	arc::VertexD r1(2, 3);
	arc::RectD r(1, 2, 3, 4);
	r = r * r1;

	cr_assert(r.pos().x() == 1 * 2);
	cr_assert(r.pos().y() == 2 * 3);
	cr_assert(r.size().x() == 3 * 2);
	cr_assert(r.size().y() == 4 * 3);
}

Test(RectD, get_values_from_rect_mult)
{
	arc::RectD r1(1, 2, 3, 4);
	arc::RectD r(1, 2, 3, 4);
	r = r * r1;

	cr_assert(r.pos().x() == 1);
	cr_assert(r.pos().y() == 2 * 2);
	cr_assert(r.size().x() == 3 * 3);
	cr_assert(r.size().y() == 4 * 4);
}

Test(RectD, get_values_from_double_div)
{
	arc::RectD r(1, 2, 3, 4);
	r = r / 2;

	cr_assert(r.pos().x() == 1);
	cr_assert(r.pos().y() == 2);
	cr_assert(r.size().x() == 3. / 2.);
	cr_assert(r.size().y() == 4 / 2);
}

Test(RectD, get_values_from_vert_div)
{
	arc::VertexD r1(2, 3);
	arc::RectD r(1, 2, 3, 4);
	r = r / r1;

	cr_assert_float_eq(r.pos().x(), 1. + 2. / 3., 0.001);
	cr_assert_float_eq(r.pos().y(), 2. + 3. / 4., 0.001);
	cr_assert_float_eq(r.size().x(), 3. / 2., 0.001);
	cr_assert_float_eq(r.size().y(), 4. / 3., 0.001);
}

Test(RectD, get_values_from_double_add)
{
	arc::RectD r(1, 2, 3, 4);
	r = r + 2;

	cr_assert(r.pos().x() == 1 + 2);
	cr_assert(r.pos().y() == 2 + 2);
	cr_assert(r.size().x() == 3);
	cr_assert(r.size().y() == 4);
}

Test(RectD, get_values_from_vert_add)
{
	arc::VertexD r1(2, 3);
	arc::RectD r(1, 2, 3, 4);
	r = r + r1;

	cr_assert_float_eq(r.pos().x(), 1 + 2, 0.001);
	cr_assert_float_eq(r.pos().y(), 2 + 3, 0.001);
	cr_assert_float_eq(r.size().x(), 3, 0.001);
	cr_assert_float_eq(r.size().y(), 4, 0.001);
}

Test(RectD, get_values_from_double_sub)
{
	arc::RectD r(1, 2, 3, 4);
	r = r - 2;

	cr_assert(r.pos().x() == 1 - 2);
	cr_assert(r.pos().y() == 2 - 2);
	cr_assert(r.size().x() == 3);
	cr_assert(r.size().y() == 4);
}

Test(RectD, get_values_from_vert_sub)
{
	arc::VertexD r1(2, 3);
	arc::RectD r(1, 2, 3, 4);
	r = r - r1;

	cr_assert_float_eq(r.pos().x(), 1 - 2, 0.001);
	cr_assert_float_eq(r.pos().y(), 2 - 3, 0.001);
	cr_assert_float_eq(r.size().x(), 3, 0.001);
	cr_assert_float_eq(r.size().y(), 4, 0.001);
}
