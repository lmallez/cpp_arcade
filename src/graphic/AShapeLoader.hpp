//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// AShapeLoader.hpp
//

#ifndef CPP_ARCADE_ASHAPELOADER_HPP
#define CPP_ARCADE_ASHAPELOADER_HPP

#include "IShape.hpp"
#include "IShapeLoader.hpp"

namespace arc {
	class AShapeLoader : virtual public IShapeLoader {
	protected:
		virtual void
		loadChild(const arc::IShape &from,
			std::UPTR<IShape> &dest) const override;
	};
}

#endif /* CPP_ARCADE_ASHAPELOADER_HPP */