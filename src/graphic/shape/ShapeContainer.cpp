//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// ShapeEmpty.cpp
//

#include "ShapeContainer.hpp"

arc::ShapeContainer::ShapeContainer(const std::shared_ptr <IShape> &parent,
	const RectF &geometry):
	AShape(parent, arc::Texture(), geometry)
{
}

arc::ShapeContainer::ShapeContainer(const ShapeContainer &ex):
	AShape(ex)
{
}

std::unique_ptr<arc::IShape>
arc::ShapeContainer::convert(const arc::IShapeLoader &loader) const
{
	std::unique_ptr<IShape> cpy = std::make_unique<arc::ShapeContainer>(*this);
	loader.loadChild(*this, cpy);
	return cpy;
}
