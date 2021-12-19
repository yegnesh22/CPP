/*
 * wav_header.h
 *
 *  Created on: 19-Dec-2021
 *      Author: yegnesh
 */

#ifndef SRC_WAV_HEADER_H_
#define SRC_WAV_HEADER_H_

#include <cstring>

struct __attribute__ ((packed)) wav_header {
	unsigned char chunkID[4];
	unsigned int chunkSize;
	unsigned char fileTypeHeader[4];
	unsigned char subChunk1ID[4];
	unsigned int subChunk1Size;
	unsigned short audioFormat;
	unsigned short numChannels;
	unsigned int sampleRate;
	unsigned int byteRate;
	unsigned short blockAlign;
	unsigned short bitsPerSample;
	unsigned char subChunk2ID[4];
	unsigned int subChunk2Size;
};

struct wav_header* InitWavHeader(unsigned short ch, unsigned int sr,
									unsigned short bpp, unsigned int t)
{
	struct wav_header *w = new struct wav_header;

	memcpy(w->chunkID, "RIFF", sizeof(w->chunkID));
	memcpy(w->fileTypeHeader, "WAVE", sizeof(w->fileTypeHeader));
	memcpy(w->subChunk1ID, "fmt ", sizeof(w->subChunk1ID));
	w->subChunk1Size = 16;
	w->audioFormat = 1;
	w->numChannels = ch;
	w->sampleRate = sr;
	w->byteRate = ch * sr * (bpp / 8);
	w->blockAlign = ch * (bpp / 8);
	w->bitsPerSample = bpp;
	memcpy(w->subChunk2ID, "data", sizeof(w->subChunk2ID));
	w->subChunk2Size = sr * ch * (bpp/8) * t;
	w->chunkSize = sizeof(struct wav_header) + w->subChunk2Size;

	return w;
}


#endif /* SRC_WAV_HEADER_H_ */
