#include "BingoGrid.h"

// Constructors

BingoGrid::BingoGrid(size_t size) : Grid<BingoElement>(size, size), m_bingo(0)
{

}

// Methods

void BingoGrid::checkElement(size_t line, size_t column)
{
	// Invert the check status of the BingoElement in line, column
	m_array[line][column].check();

	evaluate();
}

void BingoGrid::evaluate()
{
	// the width and the height of the grid are the same for a BingoGrid, we save a few function calls by storing this value
	const size_t size = getWidth();

	unsigned short bingo_line = 0;
	unsigned short bingo_columns = 0;

	// Evaluate if there is any bingo in the lines and columns
	for (size_t i = 0; i < size; i++)
	{
		// flag booleans for lines & column
		bool bc = true;		// column
		bool bl = true;		// line
	
		for (size_t j = 0; j < size; j++)
		{
			bl &= m_array[i][j].checked();
			bc &= m_array[j][i].checked();
		}		

		bingo_line += bl;
		bingo_columns += bc;
	}

	// Evaluate if there is any bingo in the diagonals
	unsigned short bingo_diagonals = 0;

	bool bd1 = true;
	bool bd2 = true;

	for (size_t i = 0; i < size; i++)
	{
		bd1 &= m_array[i][i].checked();
		bd2 &= m_array[i][size - i - 1].checked();
	}

	bingo_diagonals += bd1;
	bingo_diagonals += bd2;

	m_bingo = bingo_columns + bingo_diagonals + bingo_line;
}

// Accessors

unsigned short BingoGrid::getBingo()
{
	return m_bingo;
}