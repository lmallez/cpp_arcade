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

extern "C" arc::IGame &getIGame()
{
	return arc::BasicGame::getInstance();
}