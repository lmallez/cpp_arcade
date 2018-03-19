//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// AGraphic.hpp
//

#ifndef CPP_ARCADE_AGRAPHIC_HPP
#define CPP_ARCADE_AGRAPHIC_HPP

#include "IGraphic.hpp"
#include "IDrawLoader.hpp"

namespace arc {
	class AGraphic : virtual IGraphic {
	public:
		explicit AGraphic(const std::unique_ptr<IDrawLoader> &loader);

	private:
		virtual const IDrawLoader &getDrawLoader() const override;

	public:
		virtual void
		draw(const std::shared_ptr<IShape> &shape) const override;

	protected:
		std::shared_ptr<IDrawLoader> _drawLoader;
	};
}

#endif /* CPP_ARCADE_AGRAPHIC_HPP */