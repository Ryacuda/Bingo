#include "BingoGrid.h"

// Constructors

BingoGrid::BingoGrid(size_t size) : Grid<BingoElement>(size, size)
{

}

// Methods

bool BingoGrid::checkElement(size_t line, size_t column)
{
	// the width and the height of the grid are the same for a BingoGrid, we save a few function calls by storing this value
	const size_t size = getWidth();

	// Invert the check status of the BingoElement in line, column
	if (!m_array[line][column].check())
	{
		// if the m_check value turned to false, a new bingo cannot happen
		return false;
	}

	// Check lines, column, diagonals where the check value is now true

	// line
	bool bingo = true;
	for (size_t y = 0; y < size; y++)
	{
		if (!m_array[line][y].checked())
		{
			bingo = false;
		}
	}

	if (bingo)
	{
		return true;
	}

	// column
	bingo = true;
	for (size_t x = 0; x < size; x++)
	{
		if (!m_array[x][column].checked())
		{
			bingo = false;
		}
	}

	if (bingo)
	{
		return true;
	}

	// Test to see if the Event at line, column is in one of the diagonals that can house a bingo

	// top left - bottom right diagonal
	bingo = true;
	if (line == column)						// all the elements of the (top left - bottom right) diagonal of a square grid have their x and y coordinates equal
	{
		for (size_t x = 0; x < size; x++)
		{
			if (!m_array[x][x].checked())
			{
				bingo = false;
			}
		}
	}

	if (bingo)
	{
		return true;
	}

	// top right - bottom left diagonal
	bingo = true;
	if (line + column + 1 == size)			// all the elements of the (top right - bottom left) diagonal of a square grid have the sum of their x and y coordinates equal to the width of the grid - 1
	{
		for (size_t x = 0; x < size; x++)
		{
			size_t y = size - x - 1;		// size = x + y + 1
			if (!m_array[x][y].checked())
			{
				bingo = false;
			}
		}
	}

	return bingo;
}