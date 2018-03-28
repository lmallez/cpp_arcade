/*
** EPITECH PROJECT, 2018
** cpp_arcade
** File description:
** main.cpp
*/

#include "src/core/corebuild/CoreBuild.hpp"

int main(int ac, char **av)
{
	if (ac < 3)
		return 84;
	arc::CoreBuild core(av[1], av[2]);

	try {
		core.menu();
	}  catch (arc::Exception &e) {
		std::cerr << av[0] << ": " << e.what() << std::endl;
		return 84;
	}
	return 0;
}