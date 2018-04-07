//
// EPITECH PROJECT, 2018
// cpp_arcade - SFMainWindow.hpp
// File description:
// Created by Faudil Puttilli
//

#ifndef CPP_ARCADE_SFMAINWINDOW_HPP
#define CPP_ARCADE_SFMAINWINDOW_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <unordered_map>
#include "src/graphic/IGraphic.hpp"
#include "src/std/Vertex.hpp"

namespace arc
{
	class SFMainWindow {
	public:
		static SFMainWindow &getInstance();
		void setWindowSize(size_t x, size_t y);
		void display();
		VertexF getSize() const;
		void close();
		void draw(const sf::Drawable &toDraw);
		void pollEvent(arc::EventHandler &);
		bool TextureInCache(const std::string &) const;
		std::SPTR<sf::Texture> getTextureCache(
			const std::string &) const;
		void addTexture(const std::string &);
	private:
		explicit SFMainWindow(VertexI = {400, 400});
		std::UPTR<sf::RenderWindow> _window;
		static std::unordered_map<sf::Keyboard::Key, arc::KeyEvent::Key> _keyMap;
		static std::unordered_map<sf::Mouse::Button, arc::MouseEvent::MouseButton> _mouseMap;
		arc::Vertex<float > _tranformMousePos(const sf::Vector2i &)
		const;
		std::unordered_map<std::string, std::SPTR<sf::Texture>>
			_textureCache;
	};

}

#endif //CPP_ARCADE_SFMAINWINDOW_HPP
