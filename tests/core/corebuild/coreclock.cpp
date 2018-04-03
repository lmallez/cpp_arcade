/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
** aaaah
*/

#include <criterion/criterion.h>
#include "src/core/corebuild/CoreClock.hpp"

Test(CoreClock, creation_and_incr)
{
	arc::CoreClock c(500);
	c.waitTime();
}

Test(CoreClock, creation_and_incr_from_std_chrono_duration)
{
	std::chrono::duration<double> d(500);
	arc::CoreClock c(d);
	c.waitTime();
}
