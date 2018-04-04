/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
** aaaah
*/

#include "ScoreHandler.hpp"

ScoreHandler::ScoreHandler(const std::string &game)
{
	_game = game;
}

ScoreHandler::~ScoreHandler()
{
}

void ScoreHandler::setGame(const std::string &game)
{
	_game = game;
}

void ScoreHandler::addScore(const std::pair<const std::string &, int> &entry)
{
	mkdir(SCORES_DIR, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	if (_game.empty())
		throw arc::Exception("ScoreHandler", "game name not set");
	std::ofstream f(std::string(SCORES_DIR) + "/" + _game,
			std::ofstream::app);

	if (!f)
		throw arc::Exception("ScoreHandler", "could not load score"
				"file for " + _game);
	f << entry.first << ";" << entry.second << std::endl;
}

std::vector<std::pair<std::string, int>> ScoreHandler::getScores() const
{
	std::string line;
	std::pair<std::string, int> pair;
	std::vector<std::pair<std::string, int>> ret;
	if (_game.empty())
		throw arc::Exception("ScoreHandler", "game name not set");
	std::ifstream f(std::string(SCORES_DIR) + "/" + _game);

	if (!f)
		throw arc::Exception("ScoreHandler", "could not load score"
				"file for " + _game);
	while(std::getline(f, line)) {
		size_t pos = line.find_last_of(";");
		pair.first = line.substr(0, pos);
		pair.second = std::stoi(line.substr(pos + 1));
		ret.push_back(pair);
	}
	return (ret);
}
