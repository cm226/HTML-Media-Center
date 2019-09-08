#include "stdafx.h"
#include "../../arseholeCoreModules/CoreModules/HTMLRendere/Elements/Lable.h"
#include "../../arseholeCoreModules/CoreModules/HTMLRendere/Page.h"

BOOST_AUTO_TEST_CASE(pageConstructor)
{
	BOOST_CHECK_NO_THROW(Page p);
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
	BOOST_CHECK_EQUAL(renderedPage.compare("<div id=\"lable\">testText</div><div id=\"lable\">testText</div>"),0);


	p.freePage();



}

