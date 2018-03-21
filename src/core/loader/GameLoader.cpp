//
// EPITECH PROJECT, 2018
// cpp_arcade - GameLoader.cpp
// File description:
// Created by Faudil Puttilli
//

#include "GameLoader.hpp"

arc::GameLoader::GameLoader(const std::string &libName) :
	_libName(libName), _sym(nullptr), _getIGame(nullptr)
{
	load(libName);
}

bool arc::GameLoader::operator!() const
{
	return _sym == nullptr;
}

bool arc::GameLoader::load(const std::string &libName)
{
	_libName = libName;

	_sym = dlopen(libName.c_str(), RTLD_LAZY);
	char *err_msg = dlerror();
	if (err_msg == nullptr)
		return true;
	std::cerr << err_msg << std::endl;
	return false;
}

bool arc::GameLoader::unload()
{
	if (_sym == nullptr)
		return false;
	dlclose(_sym);
	_sym = nullptr;
	_libName = "";
	_getIGame = nullptr;
	return true;
}

std::unique_ptr<arc::IGame> &arc::GameLoader::getIGame()
{
	std::unique_ptr<arc::IGame> graph = nullptr;

	if (_getIGame == nullptr)
		_getIGame = (std::unique_ptr<arc::IGame> &(*)())
			dlsym(_sym, "getIGame");
	return _getIGame();
}
