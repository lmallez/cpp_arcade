//
// EPITECH PROJECT, 2018
// cpp_arcade - SFMainWindow.cpp
// File description:
// Created by Faudil Puttilli
//

#include "SFMainWindow.hpp"

arc::SFMainWindow &arc::SFMainWindow::getInstance()
{
	static std::unique_ptr<SFMainWindow> instance = nullptr;

	if (instance == nullptr)
		instance.reset(new SFMainWindow(arc::VertexI(700, 700)));
	return *instance;
}

arc::SFMainWindow::SFMainWindow(arc::VertexI size)
{
	_window = std::make_unique<sf::RenderWindow>();
	_window->create(sf::VideoMode(size.x(), size.y()), WNAME);
	if (!_window->isOpen())
		throw arc::Exception("SF Graphic", "Can't open the Window");
	_keyMap[sf::Keyboard::A] = arc::KeyEvent::Key::A;
	_keyMap[sf::Keyboard::B] = arc::KeyEvent::Key::B;
	_keyMap[sf::Keyboard::C] = arc::KeyEvent::Key::C;
	_keyMap[sf::Keyboard::D] = arc::KeyEvent::Key::D;
	_keyMap[sf::Keyboard::E] = arc::KeyEvent::Key::E;
	_keyMap[sf::Keyboard::F] = arc::KeyEvent::Key::F;
	_keyMap[sf::Keyboard::G] = arc::KeyEvent::Key::G;
	_keyMap[sf::Keyboard::H] = arc::KeyEvent::Key::H;
	_keyMap[sf::Keyboard::I] = arc::KeyEvent::Key::I;
	_keyMap[sf::Keyboard::J] = arc::KeyEvent::Key::J;
	_keyMap[sf::Keyboard::K] = arc::KeyEvent::Key::K;
	_keyMap[sf::Keyboard::L] = arc::KeyEvent::Key::L;
	_keyMap[sf::Keyboard::M] = arc::KeyEvent::Key::M;
	_keyMap[sf::Keyboard::N] = arc::KeyEvent::Key::N;
	_keyMap[sf::Keyboard::O] = arc::KeyEvent::Key::O;
	_setKeyMap();
	_setMouseMap();
}

void arc::SFMainWindow::_setMouseMap()
{
	_mouseMap[sf::Mouse::Button::Right] = arc::MouseEvent::RIGHT_BUTTON;
	_mouseMap[sf::Mouse::Button::Left] = arc::MouseEvent::LEFT_BUTTON;
	_mouseMap[sf::Mouse::Button::Middle] = arc::MouseEvent::MIDDLE_BUTTON;
}

void arc::SFMainWindow::_setKeyMap()
{
	_keyMap[sf::Keyboard::P] = arc::KeyEvent::Key::P;
	_keyMap[sf::Keyboard::Q] = arc::KeyEvent::Key::Q;
	_keyMap[sf::Keyboard::R] = arc::KeyEvent::Key::R;
	_keyMap[sf::Keyboard::S] = arc::KeyEvent::Key::S;
	_keyMap[sf::Keyboard::T] = arc::KeyEvent::Key::T;
	_keyMap[sf::Keyboard::U] = arc::KeyEvent::Key::U;
	_keyMap[sf::Keyboard::V] = arc::KeyEvent::Key::V;
	_keyMap[sf::Keyboard::W] = arc::KeyEvent::Key::W;
	_keyMap[sf::Keyboard::X] = arc::KeyEvent::Key::X;
	_keyMap[sf::Keyboard::Y] = arc::KeyEvent::Key::Y;
	_keyMap[sf::Keyboard::Z] = arc::KeyEvent::Key::Z;
	_keyMap[sf::Keyboard::Left] = arc::KeyEvent::Key::LEFT;
	_keyMap[sf::Keyboard::Right] = arc::KeyEvent::Key::RIGHT;
	_keyMap[sf::Keyboard::Up] = arc::KeyEvent::Key::UP;
	_keyMap[sf::Keyboard::Down] = arc::KeyEvent::Key::DOWN;
	_keyMap[sf::Keyboard::Escape] = arc::KeyEvent::Key::ESCAPE;
	_keyMap[sf::Keyboard::Space] = arc::KeyEvent::Key::SPACE;
	_keyMap[sf::Keyboard::LShift] = arc::KeyEvent::Key::LSHIFT;
	_keyMap[sf::Keyboard::RShift] = arc::KeyEvent::Key::RSHIFT;
	_keyMap[sf::Keyboard::Tab] = arc::KeyEvent::Key::TAB;
	_keyMap[sf::Keyboard::Return] = arc::KeyEvent::Key::RETURN;
}

void arc::SFMainWindow::setWindowSize(size_t x, size_t y)
{
	_window->setSize(sf::Vector2u((unsigned)x, (unsigned)y));
}

void arc::SFMainWindow::draw(const sf::Drawable &toDraw)
{
	_window->draw(toDraw);
}

void arc::SFMainWindow::close()
{
	_window->close();
}

arc::VertexF arc::SFMainWindow::getSize() const
{
	if (_window->isOpen())
		return VertexF(_window->getSize().x, _window->getSize().x);
	return {0, 0};
}

void arc::SFMainWindow::display()
{
	_window->display();
	_window->clear(sf::Color::Black);
}

arc::Vertex<float>
arc::SFMainWindow::_tranformMousePos(const sf::Vector2i &mPos) const
{
	arc::Vertex<float> res;

	res.rx() = mPos.x / _window->getSize().x;
	res.ry() = mPos.y / _window->getSize().y;
	return res;
}

void arc::SFMainWindow::pollEvent(EventHandler &evtHandler)
{
    sf::Event evt;
	while (_window->pollEvent(evt)) {
		switch (evt.type) {
			case sf::Event::KeyPressed:
				evtHandler.keyEvent().setKeyPressed(_keyMap[evt.key.code]);
				break;
			case sf::Event::KeyReleased:
				evtHandler.keyEvent().setKeyReleased
					(_keyMap[evt.key
					.code]);
				break;
			case sf::Event::MouseMoved:
				evtHandler.mouseEvent()
					.setPos(_tranformMousePos(sf::Mouse::
							 getPosition()));
			case sf::Event::MouseButtonPressed:
				evtHandler.mouseEvent().setButtonPressed
					(_mouseMap[evt.mouseButton.button]);
				break;
			default:
				break;
		}
	}
}
