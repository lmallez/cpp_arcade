/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
** aaaah
*/

#include <dlfcn.h>
#include "CacaGraphic.hpp"
#include "src/graphic/IGraphic.hpp"

extern "C" arc::IGraphic &getIGraphic()
{
	return arc::CacaGraphic::getInstance();
}

extern "C" arc::IGraphic &freeIGraphic()
{
	return arc::CacaGraphic::getInstance(false);
}
