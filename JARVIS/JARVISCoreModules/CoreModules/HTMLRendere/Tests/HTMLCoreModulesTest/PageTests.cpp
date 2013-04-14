#include "stdafx.h"
#include "../../../HTMLRendere/Elements/Lable.h"
#include "../../../HTMLRendere/Page.h"

BOOST_AUTO_TEST_CASE(pageConstructor)
{
	BOOST_CHECK_NO_THROW(Page p());
}


BOOST_AUTO_TEST_CASE(pageElements)
{

	Lable* l = new Lable("lable");
	l->setText("testText");

	Lable* l2 = new Lable("lable");
	l2->setText("testText");

	Page p;
	std::string renderedPage;

	p.addElement(l);
	p.addElement(l2);
	p.buildPage(&renderedPage);
	BOOST_CHECK_EQUAL(renderedPage.compare("<p id=\"lable\">testText</p><p id=\"lable\">testText</p>"),0);


	p.freePage();



}

