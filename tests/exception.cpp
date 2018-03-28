/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
** aaaah
*/

#include <criterion/criterion.h>
#include "src/exception/Exception.hpp"

void raise_exc(void)
{
	throw arc::Exception("aled", "oskour");
}

Test(exception, raise_std)
{
	try {
		raise_exc();
	} catch (arc::Exception e) {
		cr_assert_str_eq(e.what(), "aled: oskour");
	}
}
