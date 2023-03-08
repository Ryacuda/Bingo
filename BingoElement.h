#pragma once

#include <string>
#include "json.hpp"

class BingoElement
{
public:
	// Constructors
	BingoElement();

	BingoElement(const std::string& name);

	// Accessors
	std::string getName();

	void setName(const std::string& name);

	bool checked();

	// Methods

	/*
	* Inverts the m_check boolean, and returns its new value.
	*/
	bool check();

private:
	std::string m_name;
	bool m_checked;
	// image
	// description
};

// Other functions

std::vector<BingoElement> generateBasicElements(int n);