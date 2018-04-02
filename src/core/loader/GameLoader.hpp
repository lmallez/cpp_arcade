//
// EPITECH PROJECT, 2018
// cpp_arcade - GameLoader.hpp
// File description:
// Created by Faudil Puttilli
//

#ifndef CPP_ARCADE_GAMELOADER_HPP
#define CPP_ARCADE_GAMELOADER_HPP

#include <dlfcn.h>
#include "src/exception/Exception.hpp"
#include "src/games/IGame.hpp"

namespace arc
{

	class GameLoader
	{
	public:
		explicit GameLoader(const std::string & = "");
		bool operator!() const;
		bool load(const std::string &);
		bool unload();
		IGame & getIGame();

	private:
		std::string _libName;
		void *_sym;
		arc::IGame &(*_getIGame)();
	};

}

#endif //CPP_ARCADE_GAMELOADER_HPP
