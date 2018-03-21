//
// EPITECH PROJECT, 2018
// cpp_arcade - SFMainWindow.hpp
// File description:
// Created by Faudil Puttilli
//

#ifndef CPP_ARCADE_SFMAINWINDOW_HPP
#define CPP_ARCADE_SFMAINWINDOW_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <src/graphic/IGraphic.hpp>
#include <src/std/Vertex.hpp>

namespace arc
{

	class SFMainWindow {
	public:
		static SFMainWindow &getInstance();
		void setWindowSize(size_t x, size_t y);
		void draw(const sf::Drawable &);
		void display();
		VertexF getSize() const;
		void close();
	private:
		explicit SFMainWindow(VertexI = {400, 400});
		std::unique_ptr<sf::RenderWindow> _window;
	};

}

#endif //CPP_ARCADE_SFMAINWINDOW_HPP
