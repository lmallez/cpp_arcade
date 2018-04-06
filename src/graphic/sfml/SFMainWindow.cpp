//
// EPITECH PROJECT, 2018
// cpp_arcade - SFMainWindow.cpp
// File description:
// Created by Faudil Puttilli
//

#include "SFMainWindow.hpp"

std::unordered_map<sf::Keyboard::Key, arc::KeyEvent::Key> arc::SFMainWindow::_keyMap = {
	{sf::Keyboard::A, arc::KeyEvent::Key::A},
	{sf::Keyboard::B, arc::KeyEvent::Key::B},
	{sf::Keyboard::C, arc::KeyEvent::Key::C},
	{sf::Keyboard::D, arc::KeyEvent::Key::D},
	{sf::Keyboard::E, arc::KeyEvent::Key::E},
	{sf::Keyboard::F, arc::KeyEvent::Key::F},
	{sf::Keyboard::G, arc::KeyEvent::Key::G},
	{sf::Keyboard::H, arc::KeyEvent::Key::H},
	{sf::Keyboard::I, arc::KeyEvent::Key::I},
	{sf::Keyboard::J, arc::KeyEvent::Key::J},
	{sf::Keyboard::K, arc::KeyEvent::Key::K},
	{sf::Keyboard::L, arc::KeyEvent::Key::L},
	{sf::Keyboard::M, arc::KeyEvent::Key::M},
	{sf::Keyboard::N, arc::KeyEvent::Key::N},
	{sf::Keyboard::O, arc::KeyEvent::Key::O},
	{sf::Keyboard::P, arc::KeyEvent::Key::P},
	{sf::Keyboard::Q, arc::KeyEvent::Key::Q},
	{sf::Keyboard::R, arc::KeyEvent::Key::R},
	{sf::Keyboard::S, arc::KeyEvent::Key::S},
	{sf::Keyboard::T, arc::KeyEvent::Key::T},
	{sf::Keyboard::U, arc::KeyEvent::Key::U},
	{sf::Keyboard::V, arc::KeyEvent::Key::V},
	{sf::Keyboard::W, arc::KeyEvent::Key::W},
	{sf::Keyboard::X, arc::KeyEvent::Key::X},
	{sf::Keyboard::Y, arc::KeyEvent::Key::Y},
	{sf::Keyboard::Z, arc::KeyEvent::Key::Z},
	{sf::Keyboard::Left, arc::KeyEvent::Key::LEFT},
	{sf::Keyboard::Right, arc::KeyEvent::Key::RIGHT},
	{sf::Keyboard::Up, arc::KeyEvent::Key::UP},
	{sf::Keyboard::Down, arc::KeyEvent::Key::DOWN},
	{sf::Keyboard::Escape, arc::KeyEvent::Key::ESCAPE},
	{sf::Keyboard::Space, arc::KeyEvent::Key::SPACE},
	{sf::Keyboard::LShift, arc::KeyEvent::Key::LSHIFT},
	{sf::Keyboard::RShift, arc::KeyEvent::Key::RSHIFT},
	{sf::Keyboard::Tab, arc::KeyEvent::Key::TAB},
	{sf::Keyboard::Return, arc::KeyEvent::Key::RETURN},
	{sf::Keyboard::Num0, arc::KeyEvent::Key::NUM0},
	{sf::Keyboard::Num1, arc::KeyEvent::Key::NUM1},
	{sf::Keyboard::Num2, arc::KeyEvent::Key::NUM2},
	{sf::Keyboard::Num3, arc::KeyEvent::Key::NUM3},
	{sf::Keyboard::Num4, arc::KeyEvent::Key::NUM4},
	{sf::Keyboard::Num5, arc::KeyEvent::Key::NUM5},
	{sf::Keyboard::Num6, arc::KeyEvent::Key::NUM6},
	{sf::Keyboard::Num7, arc::KeyEvent::Key::NUM7},
	{sf::Keyboard::Num8, arc::KeyEvent::Key::NUM8},
	{sf::Keyboard::Num9, arc::KeyEvent::Key::NUM9},
};

std::unordered_map<sf::Mouse::Button, arc::MouseEvent::MouseButton> arc::SFMainWindow::_mouseMap = {
	{sf::Mouse::Button::Right, arc::MouseEvent::RIGHT_BUTTON},
	{sf::Mouse::Button::Left, arc::MouseEvent::LEFT_BUTTON},
	{sf::Mouse::Button::Middle, arc::MouseEvent::MIDDLE_BUTTON}
};

arc::SFMainWindow &arc::SFMainWindow::getInstance()
{
	static std::unique_ptr<SFMainWindow> instance = nullptr;

	if (instance == nullptr)
		instance.reset(new SFMainWindow(arc::VertexI(700, 700)));
	else if (!instance->_window->isOpen())
		instance->_window->create(sf::VideoMode(700, 700), WNAME);
	return *instance;
}

arc::SFMainWindow::SFMainWindow(arc::VertexI size)
{
	_window = std::make_unique<sf::RenderWindow>();
	_window->create(sf::VideoMode(size.x(), size.y()), WNAME);
	if (!_window->isOpen())
		throw arc::Exception("SF Graphic", "Can't open the Window");
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
	evtHandler.keyEvent().makeOld();
	while (_window->pollEvent(evt)) {
		switch (evt.type) {
		case sf::Event::KeyPressed:
			evtHandler.keyEvent().setKeyPressed(_keyMap[evt.key.code]);
			break;
		case sf::Event::KeyReleased:
			evtHandler.keyEvent().setKeyReleased(_keyMap[evt.key.code]);
			break;
		case sf::Event::MouseMoved:
			evtHandler.mouseEvent()
				.setPos(_tranformMousePos(sf::Mouse::
				getPosition()));
			__attribute__ ((fallthrough));
		case sf::Event::MouseButtonPressed:
			evtHandler.mouseEvent().setButtonPressed(_mouseMap[evt.mouseButton.button]);
			break;
		default:
			break;
		}
	}
}

bool arc::SFMainWindow::TextureInCache(const std::string &str) const
{
	return _textureCache.find(str) != _textureCache.end();
}

std::shared_ptr<sf::Texture> arc::SFMainWindow::getTextureCache(
	const std::string &str)
const
{
	return _textureCache.at(str);
}

void arc::SFMainWindow::addTexture(const std::string &filePath)
{
	_textureCache[filePath] = std::make_unique<sf::Texture>();
	auto tc = _textureCache[filePath];
	tc->loadFromFile(filePath);
}
