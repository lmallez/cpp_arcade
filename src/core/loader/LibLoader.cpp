//
// EPITECH PROJECT, 2018
// cpp_arcade - LibLoader.cpp
// File description:
// Created by Faudil Puttilli
//

#include "LibLoader.hpp"

LibLoader::LibLoader(const std::string &libName) :
	_libName(libName), _sym(nullptr)
{
	load(libName);
}

bool LibLoader::operator!() const
{
	return _sym == nullptr;
}

bool LibLoader::load(const std::string &libName)
{
	_libName = libName;

	_sym = dlopen(libName.c_str(), RTLD_LAZY);
	std::string err_msg = dlerror();
	if (err_msg.empty())
		return true;
	std::cerr << err_msg << std::endl;
	return false;
}

bool LibLoader::unload()
{
	if (_sym == nullptr)
		return false;
	dlclose(_sym);
	_sym = nullptr;
	_libName = "";
	return true;
}

const std::unique_ptr<arc::IGraphic> LibLoader::getIGraphic()
{
	std::unique_ptr<arc::IGraphic> _lol;


	return std::unique_ptr<arc::IGraphic>();
}
