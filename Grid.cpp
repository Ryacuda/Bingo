#include "Grid.h"

// Constructors
template <class T>
Grid<T>::Grid(size_t width, size_t height)
{
	if (width <= 0 || height <= 0)
		throw std::invalid_argument("Grid<T>::Grid arguments must be strictly positive.");

	m_array = std::vector<std::vector<T>>(width, std::vector<T>(height));
}

// Accessors
template <class T>
size_t Grid<T>::getWidth()
{
	return m_array.size();
}

template <class T>
size_t Grid<T>::getHeight()
{
	// index 0 cannot fail since the vector are always of size >= 1
	return m_array[0].size();
}

template <class T>
T Grid<T>::getElement(size_t x, size_t y)
{
	if (x > m_array.size() || y > m_array[0].size())
		throw std::invalid_argument("Index out of range.");

	return m_array[x][y];
}

// Methods