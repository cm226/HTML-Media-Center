#include "LineBreak.h"

LineBreak::LineBreak(std::string name) : IElement(name)
{

}

LineBreak::~LineBreak()
{

}

std::string LineBreak::getTagText()
{
	return "br";
}

std::string LineBreak::getTagContent()
{
	return "";
}
