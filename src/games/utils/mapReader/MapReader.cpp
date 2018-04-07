//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// MapReader.cpp
//

#include <fstream>
#include <sstream>
#include "src/exception/Exception.hpp"
#include "MapReader.hpp"

arc::MapReader::MapReader(const std::string &pathFile):
	_name(pathFile)
{
}

std::vector<std::pair<arc::VertexS, int>>
arc::MapReader::readMap(const std::string &path)
{
	std::cout << "[" << path << "]" << std::endl;
	std::vector<std::pair<arc::VertexS, int>> map;
	std::string line;
	std::ifstream f(std::string(ASSETS_DIR) + "/" + path);
	arc::VertexS pos(0, 0);

	if (!f)
		throw arc::Exception("readMap", "bad file");
	while (!f.eof()) {
		f >> line;
		std::stringstream ss(line);
		while(ss.good())
		{
			std::string substr;
			getline(ss, substr, ';');
			if (!substr.empty()) {
				map.push_back(std::make_pair(pos, std::stoi(substr)));
				pos.rx() += 1;
			}
		}
		pos.rx() = 0;
		pos.ry()++;
	}
	return map;
}

std::vector<std::pair<arc::VertexS, int>> arc::MapReader::readMap() const
{
	if (_name.empty())
		throw arc::Exception("readMap", "Not file to open");
	return readMap(_name);
};