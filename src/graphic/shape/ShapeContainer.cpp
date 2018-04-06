//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// ShapeEmpty.cpp
//

#include "ShapeContainer.hpp"

arc::ShapeContainer::ShapeContainer(const std::SPTR <IShape> &parent,
	const RectF &geometry):
	AShape(parent, arc::Texture(), geometry)
{
}

arc::ShapeContainer::ShapeContainer(const ShapeContainer &ex):
	AShape(ex)
{
}

std::UPTR<arc::IShape>
arc::ShapeContainer::convert(const arc::IShapeLoader &loader) const
{
	std::UPTR<IShape> cpy = std::MKU<arc::ShapeContainer>(*this);
	loader.loadChild(*this, cpy);
	return cpy;
}
