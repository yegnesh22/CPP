#include <opencv2/core/mat.hpp>
#include <vector>

void computeLBP(const cv::Mat& image,
                const std::vector<cv::Point2i>& pixels,
                std::vector<unsigned char>& LBP_values)
{
	cv::Point2i iLimits = {.x = image.rows, .y = image.cols};

	// Neighbour pixel's offset -- Clockwise traverse
	std::vector<cv::Point2i> noffs = { 
		{.x = -1, .y = -1}, // Top - left
		{.x = -1, .y = 0,}, // Top - center
		{.x = -1, .y = 1}, // Top - right
		{.x = 0, .y = 1}, // right
		{.x = 1, .y = 1}, // Bottom - right
		{.x = 1, .y = 0}, // Bottom - Center
		{.x = 1, .y = -1}, // Bottom - left
		{.x = 0, .y = -1}, // left
	};
	size_t nc = noffs.size();
	size_t np = pixels.size();

	for (size_t i = 0; i < np; i++) {
		cv::Point2i c = pixels[i]; // Current pixels's co-ordinates 'c'
		unsigned char cp = image.at<unsigned char>(c.y, c.x); // Current pixels value 'cp'
		unsigned char clbp = 0; // Current pixels lbp 'clbp'
		for (size_t j = 0; j < nc; j++) {
			cv::Point2i nei = {.x = c.x + noffs[i].x, .y = c.y + noffs[i].y}; // neighbour's co-ordinates 'nei'
			clbp <<= 1; // Shift the value by 1 bit for the next neighbour.
			// Bit7 - Top-left, Bit6: Top-center, Bit5: Top-right, Bit4: right
			// Bit3 - Bottom-right, Bit2: Bottom - center, Bit1: Bottom-left, Bit0: left
			if (nei.x >= 0 && nei.x < iLimits.x && nei.y >= 0 && nei.y < iLimits.y) { // If the neigbour pixel is within the image boundaries.
				unsigned char neip = image.at<unsigned char>(nei.y, nei.x); // neighbour's pixel value 'neip'
				if (cp < neip) // If current pixel's value < neighbour's pixel value, set the bit as 1.
					clbp |= 1;
			} else {
				// I am not sure what should be done if for the border pixels (0,0) --> (0,c), --> (r,c) --> (r,0).
			}
		}
		LBP_values.push_back(clbp);
	}

	return;
}

int main()
{
	return 0;
}

