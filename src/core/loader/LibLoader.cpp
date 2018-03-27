//
// EPITECH PROJECT, 2018
// cpp_arcade - LibLoader.cpp
// File description:
// Created by Faudil Puttilli
//

#include "LibLoader.hpp"

arc::LibLoader::LibLoader(const std::string &libName) :
	_libName(libName), _sym(nullptr), _getIGraphic(nullptr)
{
	if (!libName.empty())
		load(libName);
}

bool arc::LibLoader::operator!() const
{
	return _sym == nullptr;
}

bool arc::LibLoader::load(const std::string &libName)
{
	_libName = libName;

	_sym = dlopen(libName.c_str(), RTLD_LAZY);
	char *err_msg = dlerror();
	if (err_msg == nullptr)
		return true;
	std::cerr << err_msg << std::endl;
	return false;
}

bool arc::LibLoader::unload()
{
	if (_sym == nullptr)
		return false;
	dlclose(_sym);
	_sym = nullptr;
	_libName = "";
	_getIGraphic = nullptr;
	return true;
}

std::unique_ptr<arc::IGraphic> &arc::LibLoader::getIGraphic()
{
	std::unique_ptr<arc::IGraphic> graph = nullptr;

	if (_getIGraphic == nullptr)
		_getIGraphic = (std::unique_ptr<arc::IGraphic> &(*)())
			dlsym(_sym, "getIGraphic");
	return _getIGraphic();
}
