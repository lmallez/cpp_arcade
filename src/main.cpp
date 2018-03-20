/*
** EPITECH PROJECT, 2018
** cpp_arcade
** File description:
** main.cpp
*/

#include <iostream>
#include <src/core/loader/LibLoader.hpp>

int main(int ac, char **av)
{
	arc::LibLoader libLoader("./libSFArcade.so");

	std::unique_ptr<arc::IGraphic> &graph = libLoader.getIGraphic();
	return 0;
}