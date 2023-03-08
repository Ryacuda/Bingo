#include "BingoElement.h"

// Constructors

BingoElement::BingoElement() : m_name("0")
{

}

BingoElement::BingoElement(const std::string& name) : m_name(name)
{

}

// Accessors

std::string BingoElement::getName()
{
	return m_name;
}

void BingoElement::setName(const std::string& name)
{
	m_name = name;
}

bool BingoElement::checked()
{
	return m_checked;
}

// Other functions

bool BingoElement::check()
{
	m_checked = !m_checked;
	return m_checked;
}

std::vector<BingoElement> generateBasicElements(int n)
{
	std::vector<BingoElement> v(n);

	for (size_t i = 0; i < n; i++)
	{
		v[i].setName(std::to_string(i + 1));
	}

	return v;
}