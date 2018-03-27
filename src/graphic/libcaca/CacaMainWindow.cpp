/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
** aaaah
*/

#include "CacaMainWindow.hpp"

arc::CacaMainWindow &arc::CacaMainWindow::getInstance()
{
	static std::unique_ptr<arc::CacaMainWindow> instance = nullptr;

	if (instance == nullptr)
		instance.reset(new CacaMainWindow(arc::VertexI(700 / 10, 700 / 20)));
	return *instance;
}

arc::CacaMainWindow::CacaMainWindow(arc::VertexI size) :
	_canvas(NULL, caca_free_canvas),
	_window(NULL, caca_free_display)
{
	_canvas.reset(caca_create_canvas(size.x(), size.y()));
	_window.reset(caca_create_display(_canvas.get()));

	if (_window == nullptr)
		throw arc::Exception("Caca Graphic", "Can't open the Main "
			"Window");
}

void arc::CacaMainWindow::setWindowSize(size_t x, size_t y)
{
	caca_set_canvas_size(_canvas.get(), x, y);
}

std::unique_ptr<caca_canvas, int (*)(caca_canvas_t*)>
&arc::CacaMainWindow::getCanvas()
{
	return _canvas;
}

void arc::CacaMainWindow::close()
{
	caca_free_display(_window.get());
	caca_free_canvas(_canvas.get());
}

arc::VertexF arc::CacaMainWindow::getSize() const
{
	if (_window != nullptr)
		return VertexF(caca_get_display_width(_window.get()),
			       caca_get_display_height(_window.get()));
	return {0, 0};
}

void arc::CacaMainWindow::display()
{
	caca_refresh_display(_window.get());
	caca_clear_canvas(_canvas.get());
}

