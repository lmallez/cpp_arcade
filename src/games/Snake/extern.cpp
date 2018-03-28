/*
** EPITECH PROJECT, 2018
** cpp_arcade
** File description:
** extern.cpp
*/

#include <dlfcn.h>
#include <memory>
#include "../IGame.hpp"
#include "SnakeGame.hpp"

extern "C" std::unique_ptr<arc::IGame> &getIGame()
{
	return arc::SnakeGame::getInstance();
}