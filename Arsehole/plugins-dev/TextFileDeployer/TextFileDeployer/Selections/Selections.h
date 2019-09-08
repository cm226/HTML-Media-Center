#pragma once

#include "Selection.h"

class Selections
{
private:
	struct SelectionMarkerChunk
	{
		bool bit1: 1;
		bool bit2: 1;
		bool bit3: 1;
		bool bit4: 1;
		bool bit5: 1;
		bool bit6: 1;
		bool bit7: 1;
		bool bit8: 1;
	};

	int filesize;
	SelectionMarkerChunk* selectionChunks;

public:
	Selections(int fileSize);
	~Selections(void);

	void add(Selection selection);
	Selection nextSelection(); 
};

