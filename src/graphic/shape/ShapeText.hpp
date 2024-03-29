//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// ShapeText.hpp
//

#ifndef CPP_ARCADE_SHAPETEXT_HPP
#define CPP_ARCADE_SHAPETEXT_HPP

#include "src/graphic/IShape.hpp"
#include "AShape.hpp"

namespace arc {
	class ShapeText : public AShape {
	public:
		ShapeText(
			const std::SPTR<IShape> &parent,
			const Texture &texture,
			RectF geometry,
			const std::string &text);
		ShapeText(const ShapeText &ex);

		void setText(const std::string &text);
		const std::string &getText() const;

		virtual std::UPTR<IShape>
		convert(const arc::IShapeLoader &loader) const override;

	private:
		std::string _text;
	};
}

#endif /* CPP_ARCADE_SHAPETEXT_HPP */
