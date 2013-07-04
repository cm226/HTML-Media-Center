#pragma once
#include "../../Selection.h"
#include <istream>


class ConsecutiveSpaceSelectionCreator
{
	private:
		bool createingSelection;
		bool haveSelection;

		std::streampos temp_Start;
		std::streampos temp_End;

	public:
		ConsecutiveSpaceSelectionCreator();
		virtual ~ConsecutiveSpaceSelectionCreator();

		void space(std::streampos at);
		void notSpace(std::streampos at);
		bool selectionCreated();
		Selection getSelection();
};

