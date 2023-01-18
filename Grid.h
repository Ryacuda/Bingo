#pragma once

#include <vector>
#include <stdexcept>

/*
* A simple two dimensionnal vector with set dimensions. Can store most base types (?).
* 
* Set dimensions means that you have to specify them at creation, and can't change them after that.
*/
template <class T>
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

private:
	std::vector<std::vector<T>> m_array;
};
