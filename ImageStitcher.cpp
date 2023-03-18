#include "ImageStitcher.h"


// Constructors
ImageStitcher::ImageStitcher()
{
	m_result = fs::current_path();
	m_images = fs::current_path();
	m_images /= "images";
}

// Accessors
void ImageStitcher::setImagespath(fs::path& images)
{
	m_images = images;
}

fs::path ImageStitcher::getImagespath()
{
	return m_images;
}

void ImageStitcher::setResultpath(fs::path& result)
{
	m_result = result;
}

fs::path ImageStitcher::getResultpath()
{
	return m_result;
}

// Methods

void ImageStitcher::stitch()
{
	for (const auto& entry : fs::directory_iterator(m_images))
		std::cout << entry.path() << std::endl;
}