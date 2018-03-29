/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
** aaaah
*/

#include <criterion/criterion.h>
#include "src/std/Vertex.hpp"

Test(VertexI, get_values_from_values)
{
	arc::VertexI r(1, 2);

	cr_assert(r.x() == 1);
	cr_assert(r.y() == 2);
	cr_assert(r.rx() == 1);
	cr_assert(r.ry() == 2);
}

Test(VertexI, get_values_from_vertexf)
{
	arc::VertexI r1(1, 2);
	arc::VertexI r(r1);

	cr_assert(r.x() == 1);
	cr_assert(r.y() == 2);
	cr_assert(r.rx() == 1);
	cr_assert(r.ry() == 2);
}

Test(VertexI, get_values_from_assign)
{
	arc::VertexI r1(1, 2);
	arc::VertexI r;
	r = r1;

	cr_assert(r.x() == 1);
	cr_assert(r.y() == 2);
	cr_assert(r.rx() == 1);
	cr_assert(r.ry() == 2);
}

Test(VertexI, get_values_from_float_mult)
{
	arc::VertexI r(1, 2);
	r = r * 2;

	cr_assert(r.x() == 2);
	cr_assert(r.y() == 4);
}

Test(VertexI, get_values_from_vert_mult)
{
	arc::VertexI r1(2, 3);
	arc::VertexI r(1, 2);
	r = r * r1;

	cr_assert(r.x() == 1 * 2);
	cr_assert(r.y() == 2 * 3);
}

Test(VertexI, get_values_from_float_div)
{
	arc::VertexI r(2, 4);
	r = r / 2;

	cr_assert(r.x() == 1);
	cr_assert(r.y() == 2);
}

Test(VertexI, get_values_from_vert_div)
{
	arc::VertexI r1(2, 3);
	arc::VertexI r(2, 3);
	r = r / r1;

	cr_assert_eq(r.x(), 1);
	cr_assert_eq(r.y(), 1);
}

Test(VertexI, get_values_from_float_add)
{
	arc::VertexI r(1, 2);
	r = r + 2;

	cr_assert(r.x() == 1 + 2);
	cr_assert(r.y() == 2 + 2);
}

Test(VertexI, get_values_from_vert_add)
{
	arc::VertexI r1(2, 3);
	arc::VertexI r(1, 2);
	r = r + r1;

	cr_assert_eq(r.x(), 1 + 2);
	cr_assert_eq(r.y(), 2 + 3);
}

Test(VertexI, get_values_from_float_sub)
{
	arc::VertexI r(1, 2);
	r = r - 2;

	cr_assert(r.x() == 1 - 2);
	cr_assert(r.y() == 2 - 2);
}

Test(VertexI, get_values_from_vert_sub)
{
	arc::VertexI r1(2, 3);
	arc::VertexI r(1, 2);
	r = r - r1;

	cr_assert_eq(r.x(), 1 - 2);
	cr_assert_eq(r.y(), 2 - 3);
}
