#include "Selections.h"


Selections::Selections(int filesize)
{
	int filePadding = (filesize%8) - 8;
	int numberOfChunksRequired = (filesize + filePadding) / 8;

	selectionChunks = new SelectionMarkerChunk[numberOfChunksRequired];
}


Selections::~Selections(void)
{
	delete[] selectionChunks;
	selectionChunks = NULL;
}

void Selections::add(Selection selection)
{
	selection.getSelectionStart()
}

Selection Selections::nextSelection()
{

}
