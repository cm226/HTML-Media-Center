/*
 * MediaImagesPlugin.cpp
 *
 *  Created on: Nov 22, 2012
 *      Author: craig
 */

#include "MediaImagesPlugin.h"

MediaImagesPlugin::MediaImagesPlugin(CoreModules* framework) : Plugin(framework)
{
	this->name = "Media Images";
}

MediaImagesPlugin::~MediaImagesPlugin()
{

}

bool MediaImagesPlugin::whatDoYouLookLike(Page* page)
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

const char* MediaImagesPlugin::pluginName()
{
	return this->name.c_str();
}
