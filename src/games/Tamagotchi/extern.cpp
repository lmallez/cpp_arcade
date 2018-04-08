/*
** EPITECH PROJECT, 2018
** cpp_arcade
** File description:
** extern.cpp
*/

#include <dlfcn.h>
#include <memory>
#include "src/games/IGame.hpp"
#include "TamagotchiGame.hpp"

extern "C" arc::IGame &getIGame()
{
	return arc::TamagotchiGame::getInstance();
}