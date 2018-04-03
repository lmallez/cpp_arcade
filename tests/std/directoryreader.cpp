/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
** aaaah
*/

#include <criterion/criterion.h>
#include "src/std/DirectoryReader.hpp"
#include "src/exception/Exception.hpp"

Test(DirectoryReader, aled)
{
	arc::DirectoryReader d("tests");
	arc::DirectoryReader d2;
	d.fileName();

	try {
		arc::DirectoryReader d1("aled");
	} catch (arc::Exception e){}
	try {
		d2.fileName();
	} catch (arc::Exception e){}
	try {
		d2.closeDir();
	} catch (arc::Exception e){}
}
