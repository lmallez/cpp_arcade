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
	std::cout << "LOADING: " << libName << std::endl;
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
	std::cout << "UNLOADING: " << _libName << std::endl;
	if (_sym == nullptr)
		return false;
	void (*destroyer)() = (void(*)()) dlsym(_sym, "freeIGraphic");
	if (destroyer == nullptr)
		throw arc::Exception("LibLoader", dlerror());
	destroyer();
	dlclose(_sym);
	_sym = nullptr;
	_libName = "";
	_getIGraphic = nullptr;
	return true;
}

arc::IGraphic & arc::LibLoader::getIGraphic()
{
	if (_getIGraphic == nullptr)
		_getIGraphic = (arc::IGraphic &(*)())
			dlsym(_sym, "getIGraphic");
	if (_getIGraphic == nullptr)
		throw arc::Exception("run", "Invalid Graphic library");
	return _getIGraphic();
}
