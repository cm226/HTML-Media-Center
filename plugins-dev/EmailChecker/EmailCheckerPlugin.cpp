/*
 * EmailCheckerPlugin.cpp
 *
 *  Created on: Sep 21, 2012
 *      Author: craig
 */

#include "EmailCheckerPlugin.h"

#include <stdio.h>

EmailCheckerPlugin::EmailCheckerPlugin(CoreModules* framework): Plugin(framework)
{
	// TODO Auto-generated constructor stub

}

EmailCheckerPlugin::~EmailCheckerPlugin()
{
	// TODO Auto-generated destructor stub
}

bool EmailCheckerPlugin::whatDoYouLookLike(Page* page)
{
	Form* form = new Form("Form");

	Lable* lable = new Lable ("name");
	lable->setText("Email Address:");

	TextBox* emailAddres = new TextBox("email");
	FormSubmit* submitBttn = new FormSubmit("Submit");

	form->addElement(lable);
	form->addElement(emailAddres);
	form->addElement(submitBttn);

	page->addElement(form);

	return true;
}
