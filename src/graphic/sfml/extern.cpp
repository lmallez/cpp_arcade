//
// EPITECH PROJECT, 2018
// cpp_arcade - extern.cpp
// File description:
// Created by Faudil Puttilli
//

#include <dlfcn.h>
#include <src/graphic/IGraphic.hpp>
#include "SFGraphic.hpp"

extern "C" std::unique_ptr<arc::IGraphic> &getIGraphic()
{
	return arc::SFGraphic::getInstance();
}