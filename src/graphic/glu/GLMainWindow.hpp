//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// GLMainWindow.hpp
//

#ifndef CPP_ARCADE_GLMAINWINDOW_HPP
#define CPP_ARCADE_GLMAINWINDOW_HPP

#include <GL/GL.h>
#include "src/std/Vertex.hpp"

namespace arc {

	class GLMainWindow {
	public:
		static GLMainWindow &getInstance();
		void setWindowSize(size_t x, size_t y);
		void display();
		VertexF getSize() const;
		void close();
	private:
		explicit GLMainWindow(VertexI = {400, 400});
		std::UPTR<sf::RenderWindow> _window;
	};
	};
}

#endif /* CPP_ARCADE_GLMAINWINDOW_HPP */