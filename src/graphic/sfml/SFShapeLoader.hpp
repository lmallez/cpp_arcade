//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SFDrawLoader.hpp
//

#ifndef CPP_ARCADE_SFDRAWLOADER_HPP
#define CPP_ARCADE_SFDRAWLOADER_HPP

#include "src/graphic/shape/ShapeCircle.hpp"
#include "src/graphic/IShapeLoader.hpp"
#include "src/graphic/AShapeLoader.hpp"
#include "src/graphic/shape/ShapeRect.hpp"

namespace arc {
	class SFShapeLoader : public AShapeLoader {
	public:
		SFShapeLoader();
		virtual std::unique_ptr<IShape>
		load(const arc::ShapeRect &item) const override;

		virtual std::unique_ptr<IShape>
		load(const arc::ShapeCircle &item) const override;

		virtual std::unique_ptr<IShape>
		load(const arc::ShapeText &item) const override;
	};
}

#endif /* CPP_ARCADE_SFDRAWLOADER_HPP */