//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SFDraw.hpp
//

#ifndef CPP_ARCADE_SFDRAW_HPP
#define CPP_ARCADE_SFDRAW_HPP

#include <vector>
#include <SFML/Graphics/Rect.hpp>
#include "src/graphic/ADraw.hpp"
#include "src/graphic/sfml/SFGraphic.hpp"
#include "src/graphic/sfml/operator.hpp"
#include "src/std/Vertex.hpp"
#include "src/std/Rect.hpp"

namespace arc {
	class SFDraw : public ADraw {
	public:
		explicit SFDraw(
			std::shared_ptr<IDraw> parent,
			const RectF &geometry);
		explicit SFDraw(
			std::shared_ptr<IDraw> parent,
			const VertexF &pos,
			const VertexF &size);
		explicit SFDraw(
			const ADraw &ex);

		virtual RectF winPos() const override;

	protected:
		sf::FloatRect _winGeometry() const;
		virtual void _displayItem(const sf::Drawable &item) const;
	};
}

#endif /* CPP_ARCADE_SFDRAW_HPP */