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
	// Get the path of all the images we'll stitch together
	std::vector<fs::path> img_paths;

	for (const auto& entry : fs::directory_iterator(m_images))
	{
		if (is_valid_ext(entry.path().extension().string()))
		{
			// The file is an image, we add it to the list
			img_paths.push_back(entry.path());
		}
	}

	// We create a support image with the right size
}

// Other helpful functions

// from https://stackoverflow.com/questions/11635/case-insensitive-string-comparison-in-c
bool iequals(const std::string& a, const std::string& b)
{
	return std::equal(a.begin(), a.end(),
		b.begin(), b.end(),
		[](char a, char b) {
			return tolower(a) == tolower(b);
		});
}

bool is_valid_ext(const std::string& str)
{
	// List of valid extension as of now, might put them in a .json in the future as I test different image formats
	std::vector<std::string> valid_image_format{ ".png", ".jpg", ".jpeg" };

	for (auto it = valid_image_format.begin(); it != valid_image_format.end(); it++)
		if (iequals(str, *it))
			return true;

	return false;
}