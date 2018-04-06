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

	#define SCORES_DIR	"scores.arcade"

namespace arc {
	class ScoreHandler {
	public:
		explicit ScoreHandler(const std::string &game = "");
		~ScoreHandler();

		void setGame(const std::string &game);
		void addScore(const std::pair<const std::string &, int> &entry);
		void addScore(const std::string &player, int score);
		std::vector<std::pair<std::string, int>> initScores();
		void sortScores();

		std::vector<std::pair<std::string, int>> getScores() const;
		std::pair<std::string, int> getHighScore() const;


	private:
		std::string _game;
		std::vector<std::pair<std::string, int>> _leaderBoard;
	};
}

#endif /* !SCOREHANDLER_HPP_ */
