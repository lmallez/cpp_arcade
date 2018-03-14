//
// EPITECH PROJECT, 2018
// cpp_arcade
// File description:
// test_sfml_shape.cpp
//

#include <memory>
#include <src/graphic/sfml/SFGraphic.hpp>
#include <src/graphic/sfml/draw/SFDrawRect.hpp>
#include <src/graphic/sfml/draw/SFDrawCircle.hpp>

int main(int ac, char **av)
{
	std::unique_ptr<arc::SFGraphic> &aled = arc::SFGraphic::initialize();
	arc::RectF oskour(0.25, 0.25, 0.5, 0.5);
	arc::RectF aledz(0.5, 0.5, 0.5, 0.5);
	arc::RectF bizou(0.5, 0.5, 0.5, 0.5);
	arc::SFDrawCircle shape(oskour, nullptr);
	std::shared_ptr<arc::IDraw> oksour = std::make_shared<arc::SFDrawCircle>(shape);
	arc::SFDrawRect shape2(aledz, oksour);
	std::shared_ptr<arc::IDraw> oksour2 = std::make_shared<arc::SFDrawRect>(shape2);
	arc::SFDrawCircle shape3(bizou, oksour2);

	shape.draw();
	shape2.draw();
	shape3.draw();
	aled->display();
	while (1);
}