/*
 * sine.cpp
 *
 *  Created on: 19-Dec-2021
 *      Author: yegnesh
 */

#include <iostream>
#include <fstream>
#include <climits>
#include <cmath>
#include "wav_header.h"

#define HZ	1

using namespace std;

short int AMPLITUDE = SHRT_MAX;
unsigned int wav_freq =  1000 * HZ;
unsigned int sample_rate = 48000;
unsigned short num_channels = 2;
unsigned short bits_per_pixel = 16;
unsigned int duration = 10;

int main()
{
	struct wav_header *wh;
	double rotation;
	short int val;
	double grad;
	ofstream w;

	rotation = 2 * M_PI;
	grad = wav_freq * rotation / sample_rate;
	w.open("output.wav", ios::binary | ios::out);

	// Initialize the wav header
	wh = InitWavHeader(num_channels, sample_rate, bits_per_pixel, duration);

	w.write(reinterpret_cast<const char*>(wh), sizeof(struct wav_header));
	// Repeat the loop for duration seconds
	for (unsigned int t = 0; t < duration; t++) {
		// single rotation * number of times = wave freq
		for (unsigned int b = 0; b <= wav_freq; b ++) {
			// Data for a single rotation
			for (double theta = 0; theta < rotation; theta += grad) {
				val = AMPLITUDE * sin(theta);
				w.write(reinterpret_cast<const char*>(&val), sizeof(val));
				w.write(reinterpret_cast<const char*>(&val), sizeof(val));
			}
		}
	}
	w.close();
}
