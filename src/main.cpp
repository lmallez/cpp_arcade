/*
** EPITECH PROJECT, 2018
** cpp_arcade
** File description:
** main.cpp
*/

#include "src/core/corebuild/CoreBuild.hpp"

int main(int ac, char **av)
{
	if (ac < 2)
		return 84;
	try {
		arc::CoreBuild core(av[1], ac > 2 ? av[2] : "");
		core.run();
	}  catch (std::exception &e) {
		std::cerr << av[0] << ": " << e.what() << std::endl;
		return 84;
	}
	return 0;
}