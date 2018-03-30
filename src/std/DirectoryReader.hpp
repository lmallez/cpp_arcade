//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// DirectoryReader.hpp
//

#ifndef CPP_ARCADE_DIRECTORYREADER_HPP
#define CPP_ARCADE_DIRECTORYREADER_HPP

#include <string>
#include <vector>
#include <dirent.h>
#include "src/exception/Exception.hpp"

namespace arc {
	class DirectoryReader {
	public:
		explicit DirectoryReader(const std::string &directory = "");

		void openDir(const std::string &directory);
		std::vector<std::string> fileName();
		void closeDir();

	private:
		DIR *_dir;
	};
}

#endif /* CPP_ARCADE_DIRECTORYREADER_HPP */