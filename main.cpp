#include <iostream>
#include "BingoGrid.h"

int main()
{
	std::vector<Event> test = generateBasicEvents(25);

	BingoGrid test_bg(5, 5);

	test_bg.populate(test);

	return 0;
}