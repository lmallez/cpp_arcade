/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
** aaaah
*/

#include <string.h>
#include <iostream>
#include <algorithm>
#include "ScoreHandler.hpp"

arc::ScoreHandler::ScoreHandler(const std::string &game)
{
	setGame(game);
}

arc::ScoreHandler::~ScoreHandler()
{
}

std::string arc::ScoreHandler::getLinkedLib(const std::string &path)
{
	if (path.empty())
		return "";
	std::ifstream f(SCORES_LINK_FILE);
	if (!f)
		return path;
	std::string line;
	while(std::getline(f, line)) {
		size_t pos = line.find(";");
		if (line.substr(0, pos) == path)
			return line.substr(pos + 1);
	}
	return path;
}

void arc::ScoreHandler::setGame(const std::string &game)
{
	_game = game;
	if (!_game.empty()) {
		std::ofstream f(std::string(SCORES_DIR) + "/" + _game, std::ofstream::app);
		if (!f && mkdir(("./" + std::string(SCORES_DIR)).c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) != 0)
			throw arc::Exception("ScoreHandler", strerror(errno));
	}
}

void arc::ScoreHandler::addScore(const std::pair<const std::string &, int> &entry)
{
	if (_game.empty())
		throw arc::Exception("ScoreHandler", "game name not set");
	std::ofstream f(std::string(SCORES_DIR) + "/" + _game,
			std::ofstream::app);
	if (!f)
		throw arc::Exception("ScoreHandler", "could not load score"
				"file for " + _game);
	_leaderBoard.push_back(entry);
	sortScores();
	f << entry.first << ";" << entry.second << std::endl;
}

void arc::ScoreHandler::addScore(const std::string &player, int score)
{
	const std::pair<const std::string &, int> &entry = std::make_pair(player, score);

	addScore(entry);
}

std::vector<std::pair<std::string, int>> arc::ScoreHandler::initScores()
{
	std::string line;
	std::pair<std::string, int> pair;
	std::vector<std::pair<std::string, int>> ret;
	if (_game.empty())
		throw arc::Exception("ScoreHandler", "game name not set");
	std::ifstream f(std::string(SCORES_DIR) + "/" + _game);

	if (f.fail())
		throw arc::Exception("ScoreHandler", "could not load score"
				"file for " + _game);
	while(std::getline(f, line)) {
		size_t pos = line.find_last_of(";");
		pair.first = line.substr(0, pos);
		pair.second = std::stoi(line.substr(pos + 1));
		ret.push_back(pair);
	}
	_leaderBoard = ret;
	sortScores();
	return (_leaderBoard);
}

void arc::ScoreHandler::sortScores()
{
	auto a = [](const auto &a, const auto &b) {return a.second > b.second;};
	std::sort(_leaderBoard.begin(), _leaderBoard.end(), a);
}

std::vector<std::pair<std::string, int>> arc::ScoreHandler::getScores() const
{
	return _leaderBoard;
}

std::pair<std::string, int> arc::ScoreHandler::getHighScore() const
{
	if (_leaderBoard.size() == 0)
		return std::make_pair("Undefined", 0);
	return _leaderBoard[0];
}

std::string arc::ScoreHandler::getHighScoreStr() const
{
	auto a = getHighScore();
	return std::to_string(a.second) + " " + a.first;
}
