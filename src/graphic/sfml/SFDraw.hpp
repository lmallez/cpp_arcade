//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SFDraw.hpp
//

#ifndef CPP_ARCADE_SFDRAW_HPP
#define CPP_ARCADE_SFDRAW_HPP

#include <vector>
#include "src/graphic/IDraw.hpp"
#include "src/graphic/sfml/SFGraphic.hpp"

namespace arc {
	class SFDraw : public IDraw {
	public:
		explicit SFDraw(std::unique_ptr<IDraw> parent = nullptr);
		~SFDraw();
		virtual std::unique_ptr<IDraw> getParent() const override;
		virtual std::vector<std::unique_ptr<IDraw>> getChild() const override;
		virtual void addChild(std::unique_ptr<IDraw> child) override;
		virtual VertexI getPos() const override;
	protected:
		std::unique_ptr<IDraw> _parent;

	private:
		std::vector<std::unique_ptr<IDraw>> _child;
		VertexF _pos;
	};
}

#endif /* CPP_ARCADE_SFDRAW_HPP */