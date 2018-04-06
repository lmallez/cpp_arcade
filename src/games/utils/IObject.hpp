//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// IObject.hpp
//

#ifndef CPP_ARCADE_IOBJECT_HPP
#define CPP_ARCADE_IOBJECT_HPP

#include <memory>
#include "src/graphic/IShape.hpp"

namespace arc {
	class IObject {
	public:
		virtual std::shared_ptr<arc::IShape> draw(const std::shared_ptr<arc::IShape> &parent) const = 0;
		virtual bool collision(const RectF &obj) const = 0;
	};
}

#endif /* CPP_ARCADE_IOBJECT_HPP */