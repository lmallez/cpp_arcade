//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SFDrawRect.hpp
//

#ifndef CPP_ARCADE_SFDRAWRECT_HPP
#define CPP_ARCADE_SFDRAWRECT_HPP

#include <SFML/Graphics/RectangleShape.hpp>
#include "SFDraw.hpp"
#include "src/std/Rect.hpp"
#include "src/graphic/sfml/operator.hpp"

namespace arc {
	class SFDrawRect : public SFDraw {
	public:
		explicit SFDrawRect(
			const VertexF &pos = VertexF(0, 0),
			const VertexF &size = VertexF(0, 0),
			std::shared_ptr<IDraw> parent = nullptr);
		explicit SFDrawRect(const RectF &rect,
			std::shared_ptr<IDraw> parent = nullptr);
		SFDrawRect(const SFDrawRect &ex);
		~SFDrawRect() = default;

		virtual void draw() const override;
		virtual std::unique_ptr<IDraw> clone() override;

	private:
		sf::Color _color;
	};
}

#endif /* CPP_ARCADE_SFDRAWRECT_HPP */