//
// EPITECH PROJECT, 2018
// cpp_arcade - extern.cpp
// File description:
// Created by Faudil Puttilli
//

#include <dlfcn.h>
#include "SFGraphic.hpp"
#include "../IGraphic.hpp"

extern "C" std::unique_ptr<arc::IGraphic> &getIGraphic()
{
	return arc::SFGraphic::getInstance();
}