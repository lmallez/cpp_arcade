//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// SFDraw.hpp
//

#ifndef CPP_ARCADE_SFDRAW_HPP
#define CPP_ARCADE_SFDRAW_HPP

#include <vector>
#include "src/graphic/ADraw.hpp"
#include "src/graphic/sfml/SFGraphic.hpp"
#include "src/std/Vertex.hpp"

namespace arc {
	class SFDraw : public ADraw {
	public:
<<<<<<< HEAD

		virtual RectI winPos() const override;

=======
		explicit SFDraw(std::unique_ptr<IDraw> parent = nullptr);
		~SFDraw();
		virtual std::unique_ptr<IDraw> getParent() const override;
		virtual std::vector<std::unique_ptr<IDraw>> getChild() const override;
		virtual void addChild(std::unique_ptr<IDraw> child) override;
		virtual VertexI getPos() const override;
>>>>>>> 34bb4e4bed88d6bffcd3e55aea907741c18f14e4
	protected:
		VertexF _pos;
		VertexF _size;
	};
}

#endif /* CPP_ARCADE_SFDRAW_HPP */