/*
Local Binary Pattern (LBP) 

LBP is a type of visual descriptor used for classification in computer vision.
In its simplest form, for a given pixel, the LBP can be constructed in the
following manner:

1) Compare the pixel to each of its 8 neighbours (on its left-top, left-middle,
left-bottom, right-top, etc.). Follow the pixels along a circle, i.e. clockwise
or counter-clockwise.

2) Where the center pixel's value is greater than the neighbour's value, write
"0". Otherwise, write "1". This gives an 8-digit binary number.

Now, given an unsigned char input image (variable cv::Mat image) of dimensions
WIDTH and HEIGHT, compute the LBP for a list of pixels. You can use any order
that you prefer for the LBP (clockwise or counter-clockwise) but please specify.
Please implement a square LBP with a "radius" of 1 pixel. Please use unsigned
char type to represent LBP.

To access a pixel at a location (x,y) in the cv::Mat image you can use the
following syntax: image.at<unsigned char>(y,x).

To access the WIDTH of an image, use: image.cols()

To access the HEIGHT of an image, use: image.rows()
*/

#include <opencv2/core/mat.hpp>
#include <vector>

void computeLBP(const cv::Mat& image,
                const std::vector<cv::Point2i>& pixels,
                std::vector<unsigned char>& LBP_values)
{
	size_t c = image.cols();
	size_t r = image.rows();
	
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
		unsigned char cp = image.at(c.y, c.x); // Current pixels value 'cp'
		unsigned char clbp = 0; // Current pixels lbp 'clbp'
		for (size_t j = 0; j < nc; j++) {
			cv::Point2i nei = {.x = c.x + noffs[i].x, .y = c.y + noffs[i].y}; // neighbour's co-ordinates 'nei'
			clbp <<= 1; // Shift the value by 1 bit for the next neighbour.
			// Bit7 - Top-left, Bit6: Top-center, Bit5: Top-right, Bit4: right
			// Bit3 - Bottom-right, Bit2: Bottom - center, Bit1: Bottom-left, Bit0: left
			if (nei.x >= 0 && nei.x < r && nei.y >= 0 && nei.y < c) { // If the neigbour pixel is within the image boundaries.
				unsigned char neip = image.at(nei.y, nei.x); // neighbour's pixel value 'neip'
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

