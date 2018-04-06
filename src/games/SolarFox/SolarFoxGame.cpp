//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SolarFoxGame.cpp
//

#include "SolarFoxGame.hpp"

arc::IGame &arc::SolarFoxGame::getInstance()
{
	static arc::IGame *instance = nullptr;
	if (instance == nullptr)
		instance = new SolarFoxGame();
	return *instance;
}

void arc::SolarFoxGame::freeInstance()
{
}

arc::SolarFoxGame::SolarFoxGame():
	_clock(0.02),
	_ship({1, 1}, {0.05, 0.05}, 10),
	_mapManager("../assets/solarfox"),
	_scoreboard("solarfox")
{
	assignKey(arc::KeyEvent::A, arc::KeyEvent::JUSTPRESSED, &arc::SolarFoxGame::_playerShot);
}

void arc::SolarFoxGame::assignKey(arc::KeyEvent::Key key,
	arc::KeyEvent::Status status, arc::SolarFoxGame::SolarFoxEvt_t func)
{
	auto a = std::make_pair(key, std::make_pair(status, func));
	_solarForEvent.insert(a);
}

void arc::SolarFoxGame::execKey(arc::EventHandler &event)
{
	SystemController::execKey(event);
	_ship.execKey(event);
	for (auto a : _solarForEvent)
		execKey(event, a.first);
}

void arc::SolarFoxGame::execKey(arc::EventHandler &event, arc::KeyEvent::Key key)
{
	switch (_solarForEvent[key].first) {
	case arc::KeyEvent::Status::PRESSED:
		if (event.keyEvent().isKeyPressed(key))
			(this->*(_solarForEvent[key].second))(event);
		break;
	case arc::KeyEvent::Status::RELEASED:
		if (!event.keyEvent().isKeyPressed(key))
			(this->*(_solarForEvent[key].second))(event);
		break;
	case arc::KeyEvent::Status::JUSTPRESSED:
		if (event.keyEvent().isKeyjustPressed(key))
			(this->*(_solarForEvent[key].second))(event);
		break;
	case arc::KeyEvent::Status::JUSTRELEASED:
		if (event.keyEvent().isKeyjustPressed(key))
			(this->*(_solarForEvent[key].second))(event);
		break;
	}
}

std::shared_ptr <arc::IShape> arc::SolarFoxGame::start()
{
	srandom(time(nullptr));
	_isOver = false;
	_monster.push_back(solarfox::Monster(UP, {0.1, 0.05}));
	_monster.push_back(solarfox::Monster(LEFT, {0.1, 0.05}));
	_monster.push_back(solarfox::Monster(DOWN, {0.1, 0.05}));
	_monster.push_back(solarfox::Monster(RIGHT, {0.1, 0.05}));
	_object = _mapManager.initMap(0);
	_score = 0;
	_scoreboard.initScores();
	return std::make_shared<arc::ShapeContainer>();
}

std::shared_ptr <arc::IShape> arc::SolarFoxGame::update(EventHandler &event)
{
	return _isOver ? _gameOver(event) : _game(event);
}

std::shared_ptr<arc::IShape> arc::SolarFoxGame::_game(arc::EventHandler &event)
{
	std::shared_ptr all = std::make_shared<arc::ShapeContainer>();

	execKey(event);
	if (_clock.updateTime()) {
		for (auto &monster : _monster) {
			monster.move(0.01);
			if (random() % 1000 < SHOT_PROBA)
				_monsterMissile.push_back(monster.shot());
		}
		_monsterMissileMove();
		_playerMissileMove();
		if (_object.size() == 0) {
			_isOver = _mapManager.lastLvl();
			if (!_isOver)
				_object = _mapManager.nextMap();
		}
	}
	all->addChild(_drawGame());
	all->addChild(std::make_shared<arc::ShapeText>(nullptr, arc::Texture(arc::Color::White), arc::RectF(0.1, 0, 0.1, 0.4), "Score: " + std::to_string(_score)));
	all->addChild(std::make_shared<arc::ShapeText>(nullptr, arc::Texture(arc::Color::White), arc::RectF(0.5, 0, 0.1, 0.4), ("HightScore: " + std::to_string(_scoreboard.getHightScore().second)) + " " + _scoreboard.getHightScore().first));
	if (_isOver)
		_scoreboard.addScore(event.gameEvent().playerName(), (int)_score);
	return all;
}

void arc::SolarFoxGame::_monsterMissileMove()
{
	for (size_t i = 0; i < _monsterMissile.size(); i++) {
		if (!_monsterMissile[i]->move(0.01)) {
			_monsterMissile.erase(_monsterMissile.begin() + i);
			i--;
		} else if (_monsterMissile[i]->collision(_ship.getPos())) {
			_isOver = _ship.moveLife(-1);
			_monsterMissile.erase(_monsterMissile.begin() + i);
			i--;
		}
	}
}

void arc::SolarFoxGame::_playerMissileMove()
{
	for (size_t i = 0; i < _playerMissile.size(); i++) {
		if (!_playerMissile[i] || !_playerMissile[i]->move(0.01)) {
			_playerMissile.erase(_playerMissile.begin() + i);
			i--;
		} else {
			for (size_t j = 0; j < _object.size(); j++)
				if (_object[j]->collision(_playerMissile[i]->getPos())) {
					if (_object[j]->getHealth() <= 0) {
						_object.erase(_object.begin() + j);
						_score += 1;
					}
					_playerMissile.erase(_playerMissile.begin() + i);
					i--;
					break;
				}

		}
	}
}

std::shared_ptr<arc::IShape> arc::SolarFoxGame::_gameOver(
	arc::EventHandler &event)
{
	arc::SystemController::execKey(event);
	std::shared_ptr all = std::make_shared<arc::ShapeContainer>();

	all->addChild(std::make_shared<arc::ShapeText>(nullptr, arc::Texture(arc::Color::White), arc::RectF(0.4, 0.4, 0.2, 0.4), "Game Over"));
	all->addChild(std::make_shared<arc::ShapeText>(nullptr, arc::Texture(arc::Color::White), arc::RectF(0.4, 0.6, 0.1, 0.4), "Score: " + std::to_string(_score)));
	return all;
}

std::shared_ptr<arc::IShape> arc::SolarFoxGame::_drawGame() const
{
	std::shared_ptr map = std::make_shared<arc::ShapeRect>(nullptr, arc::Texture(arc::Color::Red), arc::RectF(0.1, 0.1, 0.8, 0.8));

	for (auto &monster : _monster)
		map->addChild(monster.draw(map));
	for (auto &missile : _monsterMissile)
		map->addChild(missile->draw(map));
	for (auto &missile : _playerMissile)
		map->addChild(missile->draw(map));
	for (auto &obj : _object)
		map->addChild(obj->draw(map));
	map->addChild(_ship.drawShip(map));
	map->addChild(_ship.drawLife(map, arc::RectF(0, 1.05, 0.5, 0.07)));
	return map;
}

void arc::SolarFoxGame::_playerShot(arc::EventHandler &event[[maybe_unused]])
{
	_playerMissile.push_back(_ship.shot());
}
