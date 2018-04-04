/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
** aaaah
*/

#ifndef SCOREHANDLER_HPP_
	#define SCOREHANDLER_HPP_

	#include <string>
	#include <vector>
	#include <utility>
	#include <fstream>
	#include <sys/stat.h>
	#include "src/exception/Exception.hpp"

	#define SCORES_DIR	".scores.arcade"

class ScoreHandler {
public:
	ScoreHandler(const std::string &game = "");
	~ScoreHandler();

	void setGame(const std::string &game);
	void addScore(const std::pair<const std::string &, int> &entry);
	std::vector<std::pair<std::string, int>> getScores() const;

protected:

private:
	std::string _game;
};

#endif /* !SCOREHANDLER_HPP_ */
