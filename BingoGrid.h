#pragma once

#include "Grid.h"

class BingoGrid : public Grid<BingoElement>
{
public:
	// Constructors
	BingoGrid(size_t size);

	// Methods
	bool checkElement(size_t x, size_t y);

private:
	
};