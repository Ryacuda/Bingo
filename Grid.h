#pragma once

#include <vector>
#include <stdexcept>
#include "BingoElement.h"

/*
* A simple two dimensionnal vector with set dimensions. Can store most base types (?).
* 
* Set dimensions means that you have to specify them at creation, and can't change them after that.
*/
template <typename T = void>
class Grid
{
public:
	// Constructors
	Grid(size_t width, size_t height);

	// Accessors
	size_t getWidth();

	size_t getHeight();

	T getElement(size_t x, size_t y);

	// Methods

	void populate(const std::vector<T>& v);

	// Members
	std::vector<std::vector<T>> m_array;
};
