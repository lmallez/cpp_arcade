//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SDLShape.cpp
//

#include "SDLShape.hpp"
#include "SDLMainWindow.hpp"

arc::SDLShape::SDLShape()
{
}

SDL_Rect arc::SDLShape::winGeometry() const
{
	arc::RectF geo = winPos() * arc::SDLMainWindow::getInstance().getSize();
	SDL_Rect ret = {(int)geo.pos().x(), (int)geo.pos().y(),
			(int)geo.size().x(), (int) geo.size().y()};
	return ret;
}

SDL_Texture *arc::SDLShape::getTexture(const std::string &tStr) const
{
	SDLMainWindow &mainWin = arc::SDLMainWindow::getInstance();

	if (!mainWin.TextureInCache(tStr))
		mainWin.addTexture(tStr);
	return mainWin.getTextureCache(tStr);
}
