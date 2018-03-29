/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
** aaaah
*/

#include <criterion/criterion.h>
#include "src/exception/Exception.hpp"

Test(exception, raise_default)
{
	try {
		throw arc::Exception();
	} catch (arc::Exception e) {
		cr_assert_str_eq(e.what(), "Undefined: Unknown Error");
	}
}

Test(exception, raise_custom)
{
	try {
		throw arc::Exception("aled", "oskour");
	} catch (arc::Exception e) {
		cr_assert_str_eq(e.what(), "aled: oskour");
	}
}
