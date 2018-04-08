//
// EPITECH PROJECT, 2018
// cpp_arcade - Texture.cpp
// File description:
// Created by Faudil Puttilli
//

#include "Texture.hpp"

arc::Texture::Texture(const std::string &filePath,
	const arc::Color &line, const arc::Color &bg) :
	_backgroundColor(bg), _lineColor(line), _filePath(filePath)
{
}

arc::Texture::Texture(const arc::Color &line, const arc::Color &bg) :
	_backgroundColor(bg), _lineColor(line), _filePath("")
{
}

arc::Texture::Texture(const arc::Texture &cpy) :
	_backgroundColor(cpy.bgColor()), _lineColor(cpy.lineColor()),
	_filePath(cpy.getFilePath())
{
}

arc::Texture &arc::Texture::operator=(const arc::Texture &arg)
{
	_lineColor = arg.lineColor();
	_backgroundColor = arg.bgColor();
	_filePath = arg.getFilePath();
	return *this;
}

std::string arc::Texture::getFilePath() const
{
	return _filePath;
}

arc::Color arc::Texture::bgColor() const
{
	return _backgroundColor;
}

arc::Color arc::Texture::lineColor() const
{
	return _lineColor;
}