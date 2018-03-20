//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SFShape.hpp
//

#ifndef CPP_ARCADE_SFTEST_HPP
#define CPP_ARCADE_SFTEST_HPP

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Shape.hpp>
#include "src/graphic/shape/AShape.hpp"
#include "src/graphic/sfml/SFGraphic.hpp"

#define SFML_BORDER_SIZE 0.01

namespace arc {
	class SFShape : virtual public IShape {
	public:
		SFShape();

	protected:
		sf::FloatRect winGeometry() const;
		void _colorItem(sf::Shape &item) const;
		void _displayItem(const sf::Drawable &item) const;
	};
}

#endif /* CPP_ARCADE_SFTEST_HPP */