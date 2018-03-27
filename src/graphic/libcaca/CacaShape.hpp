/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
** aaaah
*/

#ifndef CPP_ARCADE_CacaTEST_HPP
#define CPP_ARCADE_CacaTEST_HPP

#include "src/graphic/shape/AShape.hpp"
#include "src/graphic/libcaca/CacaGraphic.hpp"

namespace arc {
	class CacaShape : virtual public IShape {
	public:
		CacaShape();

	protected:
		arc::RectF winGeometry() const;
		void setColor(const arc::Color &c1, const arc::Color &c2) const;
//		void _colorItem(sf::Shape &item) const;
//		void _displayItem(const sf::Drawable &item) const;
	};
}

#endif /* CPP_ARCADE_CacaTEST_HPP */
