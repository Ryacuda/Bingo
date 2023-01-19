#pragma once

#include <string>
#include "json.hpp"

class Event
{
public:
	// Constructors
	Event();

	Event(const std::string& name);

	// Accessors
	std::string getName();

	void setName(const std::string& name);

private:
	std::string m_name;
	bool m_checked;
	// image
	// description
};

// Other functions

std::vector<Event> generateBasicEvents(int n);