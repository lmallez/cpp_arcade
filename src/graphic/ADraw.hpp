//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// ADraw.hpp
//

#ifndef CPP_ARCADE_ADRAW_HPP
#define CPP_ARCADE_ADRAW_HPP

#include <vector>
#include "IDraw.hpp"

namespace arc {
	class ADraw : public virtual IDraw {
	public:
		explicit ADraw(
			std::shared_ptr<IDraw> parent,
			const RectF &geometry);
		virtual ~ADraw() = default;

		virtual const std::shared_ptr<IDraw> &getParent() const override;
		virtual IDraw &getChild(size_t pos) override;
		virtual void addChild(std::unique_ptr<IDraw> child) override;
		virtual size_t nbChild() const override;
		virtual RectF getGeometry() const override;
		virtual RectF &getrGeometry() override;
		virtual void setGeometry(const RectF &rect) override;

		virtual IDraw &operator [](size_t pos);
		virtual RectF &operator *();

	protected:
		std::shared_ptr<IDraw> _parent;
		RectF _geometry;

	private:
		std::vector<std::shared_ptr<IDraw>> _children;
	};
}

#endif /* CPP_ARCADE_ADRAW_HPP */