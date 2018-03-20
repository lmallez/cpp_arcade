//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// AShape.hpp
//

#ifndef CPP_ARCADE_ADRAW_HPP
#define CPP_ARCADE_ADRAW_HPP

#include <vector>
#include "src/std/Texture.hpp"
#include "src/graphic/IShape.hpp"

namespace arc {
	class AShape : public virtual IShape,
		std::enable_shared_from_this<AShape> {
	public:
		explicit AShape(std::shared_ptr<IShape> parent,
			const arc::Texture &texture,
			const RectF &geometry);
		explicit AShape(const IShape &ex);

		virtual ~AShape() = default;

		virtual const std::shared_ptr<IShape> &getParent() const override;
		virtual IShape &getChild(size_t pos) const override;
		virtual void addChild(std::unique_ptr<IShape> child) override;
		virtual void addChild(std::shared_ptr<IShape> child) override;
		virtual size_t nbChild() const override;
		virtual void setGeometry(const RectF &geometry) override;
		virtual void setTexture(const Texture &texture) override;

		virtual const Texture &getTexture() const override;
		virtual const RectF &getGeometry() const override;

		virtual RectF winPos() const override;
		virtual void draw() const override;
		virtual void drawChild() const override;

		virtual IShape &operator[](size_t pos) const override;

		virtual void operator<<(std::unique_ptr<IShape> child) override;
		virtual void operator<<(std::shared_ptr<IShape> child) override;

	protected:
		std::shared_ptr<IShape> _parent;
		RectF _geometry;
		arc::Texture _texture;

	private:
		std::vector<std::shared_ptr<IShape>> _children;
	};
}

#endif /* CPP_ARCADE_ADRAW_HPP */