//
// EPITECH PROJECT, 2018
// cpp_arcade - extern.cpp
// File description:
// Created by Faudil Puttilli
//

#include <dlfcn.h>
#include "SFGraphic.hpp"
#include "src/graphic/IGraphic.hpp"

extern "C" arc::IGraphic &getIGraphic()
{
	return arc::SFGraphic::getInstance();
}

extern "C" void freeIGraphic()
{
	arc::SFGraphic::getInstance(true);
}