/*
** EPITECH PROJECT, 2018
** Arcade
** File description:
** aaaah
*/

#include <memory>
#include <criterion/criterion.h>
#include "src/exception/Exception.hpp"
#include "src/graphic/shape/ShapeText.hpp"

Test(ShapeText, base_values)
{
	arc::Texture t(arc::Color::White, arc::Color::Black);
	arc::Texture t1(arc::Color::Black, arc::Color::White);
	arc::RectF r(0, 0, 1, 1);
	arc::RectF r1(0, 1, 1, 1);
	std::shared_ptr<arc::ShapeText> c = std::make_shared<arc::ShapeText>(nullptr, t, r, "aled");
	std::shared_ptr<arc::ShapeText> c1 = std::make_shared<arc::ShapeText>(*c);
	cr_assert(c->getText() == "aled");
	cr_assert(c1->getText() == "aled");
	cr_assert(c->nbChild() == 0);
	cr_assert(c->getParent() == nullptr);
	cr_assert(c->getGeometry().pos().x() == r.pos().x());
	cr_assert(c->getGeometry().pos().y() == r.pos().y());
	cr_assert(c->getGeometry().size().x() == r.size().x());
	cr_assert(c->getGeometry().size().y() == r.size().y());
	cr_assert(c->getTexture().lineColor().values() == t.lineColor().values());
	cr_assert(c->getTexture().bgColor().values() == t.bgColor().values());
	cr_assert(c->winPos().pos().x() == r.pos().x());
	cr_assert(c->winPos().pos().y() == r.pos().y());
	cr_assert(c->winPos().size().x() == r.size().x());
	cr_assert(c->winPos().size().y() == r.size().y());
	c->setGeometry(r1);
	cr_assert(c->getGeometry().pos().x() == r1.pos().x());
	cr_assert(c->getGeometry().pos().y() == r1.pos().y());
	cr_assert(c->getGeometry().size().x() == r1.size().x());
	cr_assert(c->getGeometry().size().y() == r1.size().y());
	c->setTexture(t1);
	cr_assert(c->getTexture().lineColor().values() == t1.lineColor().values());
	cr_assert(c->getTexture().bgColor().values() == t1.bgColor().values());
}

Test(ShapeText, children)
{
	arc::Texture t(arc::Color::White, arc::Color::Black);
	arc::RectF r(0, 0, 1, 1);
	std::shared_ptr<arc::ShapeText> c = std::make_shared<arc::ShapeText>(nullptr, t, r, "aled");
	std::shared_ptr<arc::ShapeText> c1 = std::make_shared<arc::ShapeText>(c, t, r, "aled");

	try {
		c->getChild(0);
	} catch (const arc::Exception &e) {
		cr_assert_str_eq(e.what(), "IShape: Invalid pos Child");
	}
	try {
		(*c)[0];
	} catch (const arc::Exception &e) {
		cr_assert_str_eq(e.what(), "IShape: Invalid pos Child");
	}
	c->addChild(c1);
	c->getChild(0);
	(*c)[0];
	*c << c1;
	(*c)[1].getParent() == c;
	(*c)[1].winPos();
	c->draw();
}
