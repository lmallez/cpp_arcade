//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SFDrawRect.hpp
//

#ifndef CPP_ARCADE_SFDRAWRECT_HPP
#define CPP_ARCADE_SFDRAWRECT_HPP

#include <SFML/Graphics/RectangleShape.hpp>
#include "src/std/Rect.hpp"
#include "src/graphic/sfml/SFDraw.hpp"
#include "src/graphic/sfml/operator.hpp"

namespace arc {
	class SFDrawRect : public virtual SFDraw {
	public:
		explicit SFDrawRect(
			const VertexS &pos = VertexS(0, 0),
			const VertexS &size = VertexS(0, 0));
		explicit SFDrawRect(const RectS &rect);
		~SFDrawRect() = default;

		void setGeometry(const VertexS &pos, const VertexS &size);
		void setGeometry(const RectS &rect);
		RectS &getGeometry();
		virtual void draw() const override;

	private:
		RectS _geometry;
	};
}

#endif /* CPP_ARCADE_SFDRAWRECT_HPP */