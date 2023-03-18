#include <Magick++.h>
#include <iostream>
#include <filesystem>
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