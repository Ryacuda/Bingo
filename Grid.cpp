#include "Grid.h"

// Constructors
template <typename T>
Grid<T>::Grid(size_t width, size_t height)
{
	if (width <= 0 || height <= 0)
		throw std::invalid_argument("Grid<T>::Grid : arguments must be strictly positive.");

	m_array = std::vector<std::vector<T>>(width, std::vector<T>(height));
}

// Accessors
template <typename T>
size_t Grid<T>::getWidth()
{
	return m_array.size();
}

template <typename T>
size_t Grid<T>::getHeight()
{
	// index 0 cannot fail since the vector are always of size >= 1
	return m_array[0].size();
}

template <typename T>
T Grid<T>::getElement(size_t x, size_t y)
{
	if (x > m_array.size() || y > m_array[0].size())
		throw std::invalid_argument("Grid<T>::getElement : Index out of range.");

	return m_array[x][y];
}

// Methods

template <typename T>
void Grid<T>::populate(const std::vector<T>& v)
{
	if (v.size() < getHeight() * getWidth())
		throw std::invalid_argument("Grid<T>::populate : vector argument has too few elements.");

	// Fill the grid line by line
	for (size_t i = 0; i < v.size(); i++)
	{
		size_t x = i % getWidth();
		size_t y = i / getWidth();

		m_array[y][x] = v[i];
	}
}

// explicit instantiations
// we can only use Grid<Event>
template class Grid<Event>;