#include <Magick++.h>
#include <iostream>
#include <filesystem>
#include <algorithm>
#include <string>


namespace fs = std::filesystem;

#pragma once

class ImageStitcher
{
public:
	// Constructors
	ImageStitcher();

	// Accessors
	void setImagespath(fs::path& images);

	fs::path getImagespath();

	void setResultpath(fs::path& result);

	fs::path getResultpath();

	// Methods

	void stitch();

private:
	fs::path m_images;
	fs::path m_result;
	unsigned short m_cellwidth;
	unsigned short m_cellheight;
};

// Other helpful functions

bool iequals(const std::string& a, const std::string& b);

bool is_valid_ext(const std::string& str);