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
			const std::shared_ptr<IShape> &parent,
			const Texture &texture,
			RectF geometry,
			const std::string &text);
		ShapeText(const ShapeText &ex);

		const std::string &getText() const;

		virtual std::unique_ptr<IShape>
		convert(const arc::IShapeLoader &loader) const override;

	private:
		std::string _text;
	};
}

#endif /* CPP_ARCADE_SHAPETEXT_HPP */