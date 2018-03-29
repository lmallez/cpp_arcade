/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
** aaaah
*/

#include <criterion/criterion.h>
#include "src/std/Vertex.hpp"

Test(VertexD, get_values_from_values)
{
	arc::VertexD r(1, 2);

	cr_assert(r.x() == 1);
	cr_assert(r.y() == 2);
	cr_assert(r.rx() == 1);
	cr_assert(r.ry() == 2);
}

Test(VertexD, get_values_from_vertexf)
{
	arc::VertexD r1(1, 2);
	arc::VertexD r(r1);

	cr_assert(r.x() == 1);
	cr_assert(r.y() == 2);
	cr_assert(r.rx() == 1);
	cr_assert(r.ry() == 2);
}

Test(VertexD, get_values_from_assign)
{
	arc::VertexD r1(1, 2);
	arc::VertexD r;
	r = r1;

	cr_assert(r.x() == 1);
	cr_assert(r.y() == 2);
	cr_assert(r.rx() == 1);
	cr_assert(r.ry() == 2);
}

Test(VertexD, get_values_from_float_mult)
{
	arc::VertexD r(1, 2);
	r = r * 2;

	cr_assert(r.x() == 2);
	cr_assert(r.y() == 4);
}

Test(VertexD, get_values_from_vert_mult)
{
	arc::VertexD r1(2, 3);
	arc::VertexD r(1, 2);
	r = r * r1;

	cr_assert(r.x() == 1 * 2);
	cr_assert(r.y() == 2 * 3);
}

Test(VertexD, get_values_from_float_div)
{
	arc::VertexD r(2, 4);
	r = r / 2;

	cr_assert(r.x() == 1);
	cr_assert(r.y() == 2);
}

Test(VertexD, get_values_from_vert_div)
{
	arc::VertexD r1(2, 3);
	arc::VertexD r(2, 3);
	r = r / r1;

	cr_assert_eq(r.x(), 1);
	cr_assert_eq(r.y(), 1);
}

Test(VertexD, get_values_from_float_add)
{
	arc::VertexD r(1, 2);
	r = r + 2;

	cr_assert(r.x() == 1 + 2);
	cr_assert(r.y() == 2 + 2);
}

Test(VertexD, get_values_from_vert_add)
{
	arc::VertexD r1(2, 3);
	arc::VertexD r(1, 2);
	r = r + r1;

	cr_assert_eq(r.x(), 1 + 2);
	cr_assert_eq(r.y(), 2 + 3);
}

Test(VertexD, get_values_from_float_sub)
{
	arc::VertexD r(1, 2);
	r = r - 2;

	cr_assert(r.x() == 1 - 2);
	cr_assert(r.y() == 2 - 2);
}

Test(VertexD, get_values_from_vert_sub)
{
	arc::VertexD r1(2, 3);
	arc::VertexD r(1, 2);
	r = r - r1;

	cr_assert_eq(r.x(), 1 - 2);
	cr_assert_eq(r.y(), 2 - 3);
}
