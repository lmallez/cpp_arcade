//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// ShapeLoader.hpp
//

#ifndef CPP_ARCADE_SHAPELOADER_HPP
#define CPP_ARCADE_SHAPELOADER_HPP

#include <memory>
#include "src/main.hpp"

namespace arc {
	class IShape;
	class ShapeRect;
	class ShapeCircle;
	class ShapeText;

	class IShapeLoader {
	public:
		virtual std::UPTR<arc::IShape> load(
			const arc::ShapeRect &item) const = 0;
		virtual std::UPTR<arc::IShape> load(
			const arc::ShapeCircle &item) const = 0;
		virtual std::UPTR<arc::IShape> load(
			const arc::ShapeText &item) const = 0;
		virtual void loadChild(const arc::IShape &from,
			std::UPTR<IShape> &dest) const = 0;
	};
}

#endif /* CPP_ARCADE_SHAPELOADER_HPP */
