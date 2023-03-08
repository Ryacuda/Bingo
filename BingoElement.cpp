#include "BingoElement.h"

// Constructors

BingoElement::BingoElement() : m_name("0"), m_checked(false)
{

}

BingoElement::BingoElement(const std::string& name) : m_name(name), m_checked(false)
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