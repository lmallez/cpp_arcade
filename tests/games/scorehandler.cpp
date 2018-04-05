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
	arc::ScoreHandler s("tests1");
	arc::ScoreHandler s1;

	s.addScore(std::pair<std::string, int>("aled", 1));
	std::vector<std::pair<std::string, int>> res = s.getScores();
	cr_assert(res[res.size() - 1].first == "aled");
	cr_assert(res[res.size() - 1].second == 1);

	try {
		std::vector<std::pair<std::string, int>> res1 = s1.getScores();
	} catch (arc::Exception e) {}
	s1.setGame("tests2");
	s1.addScore(std::pair<std::string, int>("oskour", 2));
	std::vector<std::pair<std::string, int>> res1 = s1.getScores();
	cr_assert(res1[res1.size() - 1].first == "oskour");
	cr_assert(res1[res1.size() - 1].second == 2);
}
