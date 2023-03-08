#include <iostream>
#include "BingoGrid.h"

int main()
{
	std::vector<BingoElement> test = generateBasicElements(25);

	BingoGrid test_bg(5, 5);

	test_bg.populate(test);

	return 0;
}