/*
** EPITECH PROJECT, 2018
** cpp_arcade
** File description:
** extern.cpp
*/

#include <dlfcn.h>
#include <memory>
#include "../IGame.hpp"
#include "BasicGame.hpp"

extern "C" std::unique_ptr<arc::IGame> &getIGame()
{
	std::unique_ptr<arc::IGame> a = std::make_unique<arc::BasicGame>();
	return a;
}