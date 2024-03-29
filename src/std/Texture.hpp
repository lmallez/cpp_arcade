//
// EPITECH PROJECT, 2018
// cpp_arcade - Texture.hpp
// File description:
// Created by Faudil Puttilli
//

#ifndef CPP_ARCADE_TEXTURE_HPP
#define CPP_ARCADE_TEXTURE_HPP

#include <iostream>
#include "Color.hpp"

namespace arc
{

	class Texture
	{
	public:
		explicit Texture(
			const std::string &texture,
			const arc::Color &line = arc::Color::Transparent,
			const arc::Color &fill = arc::Color::Transparent
		);
		explicit Texture(
			const arc::Color &line = arc::Color::Transparent,
			const arc::Color &fill = arc::Color::Transparent
		);
		~Texture() {};
		Texture(const arc::Texture &);
		arc::Texture &operator=(const arc::Texture &);
		std::string getFilePath() const;
		arc::Color bgColor() const;
		arc::Color lineColor() const;
	private:
		arc::Color _backgroundColor;
		arc::Color _lineColor;
		std::string _filePath;

	};

}

#endif //CPP_ARCADE_TEXTURE_HPP
