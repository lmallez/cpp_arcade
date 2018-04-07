//
// EPITECH PROJECT, 2018
// cpp_arcade - extern.cpp
// File description:
// Created by Faudil Puttilli
//

#include <dlfcn.h>
#include "SDLGraphic.hpp"
#include "../IGraphic.hpp"

extern "C" arc::IGraphic &getIGraphic()
{
	return arc::SDLGraphic::getInstance();
}

extern "C" void freeIGraphic()
{
	arc::SDLGraphic::getInstance(true);
}

