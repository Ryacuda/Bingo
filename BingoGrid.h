#pragma once

#include "Grid.h"

class BingoGrid : public Grid<BingoElement>
{
public:
	// Constructors
	BingoGrid(size_t size);

	// Methods
	void checkElement(size_t x, size_t y);

	void evaluate();

	// Accessors

	unsigned short getBingo();

private:
	unsigned short m_bingo;
};