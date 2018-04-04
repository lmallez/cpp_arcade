/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
** aaaah
*/

#include <criterion/criterion.h>
#include "src/games/ScoreHandler.hpp"

Test(ScoreHandler, aled)
{
	ScoreHandler s("tests1");
	ScoreHandler s1;

	s.addScore(std::pair<std::string, int>("aled", 1));
	std::vector<std::pair<std::string, int>> res = s.getScores();
	try {
		std::vector<std::pair<std::string, int>> res1 = s1.getScores();
	} catch (arc::Exception e) {}
	s1.setGame("tests2");
	s1.addScore(std::pair<std::string, int>("oskour", 2));
	std::vector<std::pair<std::string, int>> res1 = s1.getScores();
}
