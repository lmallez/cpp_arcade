//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SFDrawText.hpp
//

#ifndef CPP_ARCADE_SFDRAWTEXT_HPP
#define CPP_ARCADE_SFDRAWTEXT_HPP

#include <SFML/Graphics/Text.hpp>
#include "SFDraw.hpp"

#define SFML_TEXT_PADING 1

namespace arc {
	class SFDrawText : public SFDraw {
	public:
		explicit SFDrawText(
			std::shared_ptr<IDraw> parent,
			const arc::Texture &texture,
			const VertexF &pos,
			const VertexF &size,
			const std::string &content);
		explicit SFDrawText(
			std::shared_ptr<IDraw> parent = nullptr,
			const arc::Texture &texture = arc::Texture(),
			const RectF &rect = RectF(0, 0, 0, 0),
			const std::string &content = "");
		SFDrawText(const SFDrawText &ex);

		virtual void draw() const override;
		virtual std::unique_ptr<IDraw> clone() override;

		virtual const IDraw &
		load(const std::shared_ptr<IShape> &model) override;

	private:
		sf::Text _text;
	};

}

#endif /* CPP_ARCADE_SFDRAWTEXT_HPP */