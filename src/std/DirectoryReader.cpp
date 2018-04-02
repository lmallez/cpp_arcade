//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// DirectoryReader.cpp
//

#include <iostream>
#include "DirectoryReader.hpp"

arc::DirectoryReader::DirectoryReader(const std::string &directory):
	_dir(nullptr)
{
	if (!directory.empty())
		openDir(directory);
}

void arc::DirectoryReader::openDir(const std::string &directory)
{
	_dir = opendir(directory.c_str());
	if (!_dir)
		throw arc::Exception("OpenDdir", "can't open " + directory);
}

std::vector<std::string> arc::DirectoryReader::fileName()
{
	std::vector<std::string> string;
	std::string fileName = "";

	if (!_dir)
		throw arc::Exception("FileName", "no directory open");
	for (struct dirent *file = readdir(_dir); file; file = readdir(_dir)) {
		fileName = std::string(file->d_name);
		if (fileName != "." && fileName != "..")
			string.push_back(fileName);
	}
	closeDir();
	return string;
}

void arc::DirectoryReader::closeDir()
{
	if (!_dir)
		throw arc::Exception("CloseDir", "can't close dir");
	closedir(_dir);
}
