/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
** aaaah
*/

#include <dlfcn.h>
#include "CacaGraphic.hpp"
#include "../IGraphic.hpp"

extern "C" arc::IGraphic &getIGraphic()
{
	return arc::CacaGraphic::getInstance();
}
