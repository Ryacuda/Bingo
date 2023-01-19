#include "Event.h"

// Constructors

Event::Event() : m_name("0")
{

}

Event::Event(const std::string& name) : m_name(name)
{

}

// Accessors

std::string Event::getName()
{
	return m_name;
}

void Event::setName(const std::string& name)
{
	m_name = name;
}

// Other functions

std::vector<Event> generateBasicEvents(int n)
{
	std::vector<Event> v(n);

	for (size_t i = 0; i < n; i++)
	{
		v[i].setName(std::to_string(i + 1));
	}

	return v;
}