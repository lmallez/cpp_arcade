//
// EPITECH PROJECT, 2018
// cpp_arcade - LibLoader.hpp
// File description:
// Created by Faudil Puttilli
//

#ifndef CPP_ARCADE_LIBLOADER_HPP
#define CPP_ARCADE_LIBLOADER_HPP

#include <dlfcn.h>
#include <iostream>
#include "src/graphic/IGraphic.hpp"

namespace arc
{

	class LibLoader
	{
	public:
		explicit LibLoader(const std::string & = "");

		bool operator!() const;
		bool load(const std::string &);
		bool unload();
		IGraphic & getIGraphic();

	private:
		std::string _libName;
		void *_sym;
		arc::IGraphic &(*_getIGraphic)();
	};

}

#endif //CPP_ARCADE_LIBLOADER_HPP
