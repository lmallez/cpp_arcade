//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// BasicGame.cpp
//

#include <variant>
#include <src/events/EventHandler.hpp>
#include <src/games/utils/Controller/SystemController.hpp>
#include "BasicGame.hpp"

arc::IGame &arc::BasicGame::getInstance()
{
	if (!_instance)
		_instance = (new BasicGame());
	return *_instance;
}

void arc::BasicGame::freeInstance()
{
	_instance = nullptr;
}

arc::BasicGame::BasicGame():
	PlayerController({0.01, 0.01}, arc::KeyEvent::PRESSED, true, {0, 0}, {true, arc::RectF(0, 0, 1, 1)}),
	_playerPos(arc::RectF(0, 0, 0.01, 0.01))
{
	assignKey(arc::KeyEvent::P, arc::KeyEvent::JUSTPRESSED, &arc::BasicGame::_startGrown);
	assignKey(arc::KeyEvent::O, arc::KeyEvent::JUSTPRESSED, &arc::BasicGame::_stopGrown);
	assignKey(arc::KeyEvent::I, arc::KeyEvent::JUSTPRESSED, &arc::BasicGame::_unGrown);
}

void arc::BasicGame::assignKey(arc::KeyEvent::Key key,
	arc::KeyEvent::Status status,
	arc::BasicGame::BasicGameEvent_t func)
{
	auto a = std::make_pair(key, std::make_pair(status, func));
	_keyEvent.insert(a);
}

void arc::BasicGame::execKey(arc::EventHandler &event)
{
	PlayerController::execKey(event);
	SystemController::execKey(event);
	for (auto key : _keyEvent) {
		arc::BasicGame::execKey(event, key.first);
	}
}

void arc::BasicGame::execKey(arc::EventHandler &event, arc::KeyEvent::Key key)
{
	switch (_keyEvent[key].first) {
	case arc::KeyEvent::Status::PRESSED:
		if (event.keyEvent().isKeyPressed(key))
			(this->*(_keyEvent[key].second))(event);
		break;
	case arc::KeyEvent::Status::RELEASED:
		if (!event.keyEvent().isKeyPressed(key))
			(this->*(_keyEvent[key].second))(event);
		break;
	case arc::KeyEvent::Status::JUSTPRESSED:
		if (event.keyEvent().isKeyjustPressed(key))
			(this->*(_keyEvent[key].second))(event);
		break;
	case arc::KeyEvent::Status::JUSTRELEASED:
		if (event.keyEvent().isKeyjustPressed(key))
			(this->*(_keyEvent[key].second))(event);
		break;
	}
}

std::shared_ptr<arc::IShape> arc::BasicGame::start()
{
	arc::Texture basic(arc::Color::Red, arc::Color::Blue);

	std::shared_ptr s1 = std::make_shared<arc::ShapeCircle>(nullptr, basic, _playerPos);

	/*std::shared_ptr s2 = std::make_shared<arc::ShapeCircle>(s1, basic, _playerPos);
	s1->addChild(s2);*/
	_frame = 0;
	return s1;
}

std::shared_ptr<arc::IShape> arc::BasicGame::update(EventHandler &event)
{
	arc::Texture basic(arc::Color::Red, arc::Color::Blue);
	_playerPos.rsize() = _playerPos.size() + _playerPos.size() * _grownCoef;
	_frame++;

	execKey(event);
	_playerPos.rpos() = _pCtrlPos;
	std::shared_ptr s1 = std::make_shared<arc::ShapeCircle>(nullptr, basic, _playerPos);
	std::shared_ptr s2 = std::make_shared<arc::ShapeText>(s1,
		arc::Texture(arc::Color::Yellow), RectF(0.5, 0.5, 0.25, 0.25), std::to_string(_frame));
	std::shared_ptr s3 = std::make_shared<arc::ShapeRect>(s1,
		arc::Texture(arc::Color::Red, arc::Color::Cyan), RectF(0.1, 0.2, 0.25, 0.25));
	std::shared_ptr s4 = std::make_shared<arc::ShapeRect>(s1,
		arc::Texture(arc::Color::Red, arc::Color::Cyan), RectF(0.9 - 0.25, 0.2, 0.25, 0.25));
	std::shared_ptr s5 = std::make_shared<arc::ShapeRect>(s1,
		arc::Texture(arc::Color::Red, arc::Color::Black), RectF(0.1, 0.6, 0.75, 0.25));
	s1->addChild(s2);
	s1->addChild(s3);
	s1->addChild(s4);
	s1->addChild(s5);
	return s1;
}

void arc::BasicGame::_startGrown(arc::EventHandler &event[[maybe_unused]])
{
	_grownCoef = 0;
}

void arc::BasicGame::_stopGrown(arc::EventHandler &event[[maybe_unused]])
{
	_grownCoef = 0.001;
}

void arc::BasicGame::_unGrown(arc::EventHandler &event[[maybe_unused]])
{
	_grownCoef = -0.001;
}

arc::IGame *arc::BasicGame::_instance = nullptr;