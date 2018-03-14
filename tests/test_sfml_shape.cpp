//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// test_sfml_shape.cpp
//

#include <memory>
#include <src/graphic/sfml/SFGraphic.hpp>
#include <src/graphic/sfml/draw/SFDrawRect.hpp>

int main(int ac, char **av)
{
	std::unique_ptr<arc::SFGraphic> &aled = arc::SFGraphic::initialize();
	arc::RectF oskour(0.5, 0.5, 0.5, 0.5);
	arc::RectF aledz(0.1, 0.1, 0.5, 0.5);
	arc::SFDrawRect shape(oskour, nullptr);
	arc::SFDrawRect shape2(aledz, nullptr);

	shape.draw();
	shape2.draw();
	aled->display();
	while (1);
}