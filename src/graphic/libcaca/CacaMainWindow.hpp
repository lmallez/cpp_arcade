/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
** aaaah
*/
#ifndef CPP_ARCADE_CACAMAINWINDOW_HPP
#define CPP_ARCADE_CACAMAINWINDOW_HPP

#include <caca.h>
#include <src/graphic/IGraphic.hpp>
#include <src/std/Vertex.hpp>

namespace arc
{
	class CacaMainWindow {
	public:
		static CacaMainWindow &getInstance();
		void setWindowSize(size_t x, size_t y);
		std::unique_ptr<caca_canvas_t,
			int (*)(caca_canvas_t*)> &getCanvas();
		void display();
		VertexF getSize() const;
		void close();
	private:
		explicit CacaMainWindow(VertexI = {400, 400});
		std::unique_ptr<caca_canvas_t,
			int (*)(caca_canvas_t*)> _canvas;
		std::unique_ptr<caca_display_t,
			int (*)(caca_display_t*)> _window;
	};
}

#endif //CPP_ARCADE_CACAMAINWINDOW_HPP

