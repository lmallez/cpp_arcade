//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// PlayerController.cpp
//

#include "src/events/KeyEvent.hpp"
#include "src/events/EventHandler.hpp"
#include "PlayerController.hpp"

arc::PlayerController::PlayerController(
	const VertexF &speed,
	arc::KeyEvent::Status execStatus,
	bool canGoBack,
	const VertexF &initialPos,
	const std::pair<bool, RectF> &limit,
	std::array<KeyEvent::Key, 4> key) :
	_pCtrlCanGoBack(canGoBack), _pCtrlSpeed(speed),
	_pCtrlPos(initialPos), _pCtrlLimit(limit)
{
	assignKey(key[0], execStatus, &arc::PlayerController::_moveUp);
	assignKey(key[1], execStatus, &arc::PlayerController::_moveLeft);
	assignKey(key[2], execStatus, &arc::PlayerController::_moveDown);
	assignKey(key[3], execStatus, &arc::PlayerController::_moveRigth);
}

void arc::PlayerController::assignKey(
	arc::KeyEvent::Key key,
	arc::KeyEvent::Status status,
	arc::PlayerController::playerController_t func)
{
	auto a = std::make_pair(key, std::make_pair(status, func));
	_playerKey.insert(a);
}

void arc::PlayerController::execKey(EventHandler &event)
{
	for (auto key : _playerKey) {
		arc::PlayerController::execKey(event, key.first);
	}
}

void arc::PlayerController::execKey(EventHandler &event, KeyEvent::Key key)
{
	switch (_playerKey[key].first) {
	case arc::KeyEvent::Status::PRESSED:
		if (event.keyEvent().isKeyPressed(key))
			(this->*(_playerKey[key].second))(event);
		break;
	case arc::KeyEvent::Status::RELEASED:
		if (!event.keyEvent().isKeyPressed(key))
			(this->*(_playerKey[key].second))(event);
		break;
	case arc::KeyEvent::Status::JUSTPRESSED:
		if (event.keyEvent().isKeyjustPressed(key))
			(this->*(_playerKey[key].second))(event);
		break;
	case arc::KeyEvent::Status::JUSTRELEASED:
		if (event.keyEvent().isKeyjustPressed(key))
			(this->*(_playerKey[key].second))(event);
		break;
	}
}

void arc::PlayerController::_moveUp(arc::EventHandler &event[[maybe_unused]])
{
	std::cout << "_moveUp" << std::endl;
	if (!_pCtrlCanGoBack && _pCtrlDir == DOWN)
		return;
	_pCtrlHaveMove = (!_pCtrlLimit.first || _pCtrlPos.y() - _pCtrlSpeed.y() >= _pCtrlLimit.second.pos().y());
	if (_pCtrlHaveMove)
		_pCtrlPos.ry() -= _pCtrlSpeed.y();
	_pCtrlDir = UP;
}

void arc::PlayerController::_moveLeft(arc::EventHandler &event[[maybe_unused]])
{
	std::cout << "_moveLeft" << std::endl;
	if (!_pCtrlCanGoBack && _pCtrlDir == RIGHT)
		return;
	_pCtrlHaveMove = (!_pCtrlLimit.first || _pCtrlPos.x() - _pCtrlSpeed.x() >= _pCtrlLimit.second.pos().x());
	if (_pCtrlHaveMove)
		_pCtrlPos.rx() -= _pCtrlSpeed.x();
	_pCtrlDir = LEFT;
}

void arc::PlayerController::_moveDown(arc::EventHandler &event[[maybe_unused]])
{
	std::cout << "_moveDown" << std::endl;
	if (!_pCtrlCanGoBack && _pCtrlDir == UP)
		return;
	_pCtrlHaveMove = (!_pCtrlLimit.first || _pCtrlPos.y() + _pCtrlSpeed.y() <= _pCtrlLimit.second.size().y());
	if (_pCtrlHaveMove)
		_pCtrlPos.ry() += _pCtrlSpeed.y();
	_pCtrlDir = DOWN;
}

void arc::PlayerController::_moveRigth(arc::EventHandler &event[[maybe_unused]])
{
	std::cout << "_moveRigth" << std::endl;
	if (!_pCtrlCanGoBack && _pCtrlDir == LEFT)
		return;
	_pCtrlHaveMove = (!_pCtrlLimit.first || _pCtrlPos.x() + _pCtrlSpeed.x() <= _pCtrlLimit.second.size().x());
	if (_pCtrlHaveMove)
		_pCtrlPos.rx() += _pCtrlSpeed.x();
	_pCtrlDir = RIGHT;
}

void arc::PlayerController::_moveDir(arc::EventHandler &event,
	std::pair<bool, arc::Direction> dir,
	std::pair<bool, arc::VertexF> speed)
{
	auto tmpSpeed = _pCtrlSpeed;

	if (!dir.first)
		dir.second = _pCtrlDir;
	if (speed.first)
		_pCtrlSpeed = speed.second;
	switch (dir.second) {
	case UP:
		_moveUp(event);
		break;
	case LEFT:
		_moveLeft(event);
		break;
	case RIGHT:
		_moveRigth(event);
		break;
	case DOWN:
		_moveDown(event);
		break;
	default:
		break;
	}
	_pCtrlSpeed = tmpSpeed;
}
