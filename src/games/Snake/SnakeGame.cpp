//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SnakeGame.cpp
//

#include "SnakeGame.hpp"

arc::IGame & arc::SnakeGame::getInstance()
{
	static arc::IGame *instance = nullptr;
	if (instance == nullptr)
		instance = new SnakeGame();
	return *instance;
}

std::shared_ptr<arc::IShape> arc::SnakeGame::start()
{
}

std::shared_ptr<arc::IShape> arc::SnakeGame::update(arc::EventHandler &event)
{
}

arc::SnakeGame::SnakeGame()
{
}