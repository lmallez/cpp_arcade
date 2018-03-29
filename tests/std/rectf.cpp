/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
** aaaah
*/

#include <criterion/criterion.h>
#include "src/std/Rect.hpp"

Test(RectF, get_values_from_values)
{
	arc::RectF r(1, 2, 3, 4);

	cr_assert(r.pos().x() == 1);
	cr_assert(r.pos().y() == 2);
	cr_assert(r.size().x() == 3);
	cr_assert(r.size().y() == 4);
	cr_assert(r.rpos().x() == 1);
	cr_assert(r.rpos().y() == 2);
	cr_assert(r.rsize().x() == 3);
	cr_assert(r.rsize().y() == 4);
}

Test(RectF, get_values_from_vertexes)
{
	arc::RectF r1(1, 2, 3, 4);
	arc::RectF r(r1.pos(), r1.size());

	cr_assert(r.pos().x() == 1);
	cr_assert(r.pos().y() == 2);
	cr_assert(r.size().x() == 3);
	cr_assert(r.size().y() == 4);
}

Test(RectF, get_values_from_rectf)
{
	arc::RectF r1(1, 2, 3, 4);
	arc::RectF r(r1);

	cr_assert(r.pos().x() == 1);
	cr_assert(r.pos().y() == 2);
	cr_assert(r.size().x() == 3);
	cr_assert(r.size().y() == 4);
}

Test(RectF, get_values_from_assign)
{
	arc::RectF r1(1, 2, 3, 4);
	arc::RectF r;
	r = r1;

	cr_assert(r.pos().x() == 1);
	cr_assert(r.pos().y() == 2);
	cr_assert(r.size().x() == 3);
	cr_assert(r.size().y() == 4);
}

Test(RectF, get_values_from_float_mult)
{
	arc::RectF r(1, 2, 3, 4);
	r = r * 2;

	cr_assert(r.pos().x() == 1);
	cr_assert(r.pos().y() == 2);
	cr_assert(r.size().x() == 3 * 2);
	cr_assert(r.size().y() == 4 * 2);
}

Test(RectF, get_values_from_vert_mult)
{
	arc::VertexF r1(2, 3);
	arc::RectF r(1, 2, 3, 4);
	r = r * r1;

	cr_assert(r.pos().x() == 1 * 2);
	cr_assert(r.pos().y() == 2 * 3);
	cr_assert(r.size().x() == 3 * 2);
	cr_assert(r.size().y() == 4 * 3);
}

Test(RectF, get_values_from_rect_mult)
{
	arc::RectF r1(1, 2, 3, 4);
	arc::RectF r(1, 2, 3, 4);
	r = r * r1;

	cr_assert(r.pos().x() == 1);
	cr_assert(r.pos().y() == 2 * 2);
	cr_assert(r.size().x() == 3 * 3);
	cr_assert(r.size().y() == 4 * 4);
}

Test(RectF, get_values_from_float_div)
{
	arc::RectF r(1, 2, 3, 4);
	r = r / 2;

	cr_assert(r.pos().x() == 1);
	cr_assert(r.pos().y() == 2);
	cr_assert(r.size().x() == 3. / 2.);
	cr_assert(r.size().y() == 4 / 2);
}

Test(RectF, get_values_from_vert_div)
{
	arc::VertexF r1(2, 3);
	arc::RectF r(1, 2, 3, 4);
	r = r / r1;

	cr_assert_float_eq(r.pos().x(), 1. + 2. / 3., 0.001);
	cr_assert_float_eq(r.pos().y(), 2. + 3. / 4., 0.001);
	cr_assert_float_eq(r.size().x(), 3. / 2., 0.001);
	cr_assert_float_eq(r.size().y(), 4. / 3., 0.001);
}

Test(RectF, get_values_from_float_add)
{
	arc::RectF r(1, 2, 3, 4);
	r = r + 2;

	cr_assert(r.pos().x() == 1 + 2);
	cr_assert(r.pos().y() == 2 + 2);
	cr_assert(r.size().x() == 3);
	cr_assert(r.size().y() == 4);
}

Test(RectF, get_values_from_vert_add)
{
	arc::VertexF r1(2, 3);
	arc::RectF r(1, 2, 3, 4);
	r = r + r1;

	cr_assert_float_eq(r.pos().x(), 1 + 2, 0.001);
	cr_assert_float_eq(r.pos().y(), 2 + 3, 0.001);
	cr_assert_float_eq(r.size().x(), 3, 0.001);
	cr_assert_float_eq(r.size().y(), 4, 0.001);
}

Test(RectF, get_values_from_float_sub)
{
	arc::RectF r(1, 2, 3, 4);
	r = r - 2;

	cr_assert(r.pos().x() == 1 - 2);
	cr_assert(r.pos().y() == 2 - 2);
	cr_assert(r.size().x() == 3);
	cr_assert(r.size().y() == 4);
}

Test(RectF, get_values_from_vert_sub)
{
	arc::VertexF r1(2, 3);
	arc::RectF r(1, 2, 3, 4);
	r = r - r1;

	cr_assert_float_eq(r.pos().x(), 1 - 2, 0.001);
	cr_assert_float_eq(r.pos().y(), 2 - 3, 0.001);
	cr_assert_float_eq(r.size().x(), 3, 0.001);
	cr_assert_float_eq(r.size().y(), 4, 0.001);
}
