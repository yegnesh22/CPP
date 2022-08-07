/* 
 * Generate a sine wave audio wav file with specified frequency and
 * sample rate. Default frequency 1KHz, sample rate 48000, amplitude
 * 1024 and which plays for a duration of 10 secs.
 * Author: Yegnesh S Iyer <yegnesh22@gmail.com>
 */

#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <getopt.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define DEF_FREQ	1000
#define DEF_RATE	48000
#define DEF_AMPL	powf(2,14)

#ifdef DEBUG
#define SINE_DEBUG(...) printf(__VA_ARGS__)
#else
#define SINE_DEBUG(...)
#endif

/* WAV file header */
struct WAV_Header {
	char riff_head[4];
	unsigned int file_size;
	char wave_desc[4];
	char fmt_desc[4];
	unsigned int wav_sec_size;
	unsigned short type;
	unsigned short channels;
	unsigned int sample_rate;
	unsigned int bytes_per_sec;
	unsigned short block_align;
	unsigned short bits_per_sample;
	char data_desc[4];
	unsigned int data_size;
};

/* Function to fill in the wave file header with appropriate values */
void fill_header(struct WAV_Header* header, unsigned short channels, 
		unsigned int sample_rate, unsigned int data_size)
{
	header->riff_head[0] = 'R';
	header->riff_head[1] = 'I';
	header->riff_head[2] = 'F';
	header->riff_head[3] = 'F';
	header->file_size = data_size + sizeof(struct WAV_Header) - 8;
	header->wave_desc[0] = 'W';
	header->wave_desc[1] = 'A';
	header->wave_desc[2] = 'V';
	header->wave_desc[3] = 'E';
	header->fmt_desc[0] = 'f';
	header->fmt_desc[1] = 'm';
	header->fmt_desc[2] = 't';
	header->fmt_desc[3] = ' ';
	header->wav_sec_size = 0x10;
	header->type =0x01;
	header->channels = channels;
	header->sample_rate = sample_rate;
	/* bytes_per_sec = sample rate * num channels * bytes per sample */
	header->bytes_per_sec = header->sample_rate * channels * 2;
	/* block_align = bytes per sample * number of channels */
	header->block_align = 2 * channels;
	header->bits_per_sample = 0x10;
	header->data_desc[0] = 'd';
	header->data_desc[1] = 'a';
	header->data_desc[2] = 't';
	header->data_desc[3] = 'a';
	header->data_size = data_size;
}

int main(int argc, char **argv)
{
	struct WAV_Header header;
	unsigned char file_name[128] = {0};
	float amplitude = DEF_AMPL;
	float angle;
	float samples_per_cycle;
	float sloop;
	int fd;
	unsigned int sampling_rate = DEF_RATE;
	unsigned int freq = DEF_FREQ;
	unsigned int num_channels = 2;
	unsigned int tsecs = 10;
	unsigned int tloop;
	unsigned int wloop;
	unsigned int cloop;
	unsigned int data_size;
	short value;
	char opt;

	while ((opt = getopt(argc, argv, "f:t:s:c:")) != -1) {
		switch (opt) {
			case 'f':
				SINE_DEBUG("frequency %s specified\n", optarg);
				freq = atoi(optarg);
				break;
			case 't':
				SINE_DEBUG("time %s specified\n", optarg);
				tsecs = atoi(optarg);
				break;
			case 's':
				SINE_DEBUG("sampling %s specified\n", optarg);
				sampling_rate = atoi(optarg);
				break;
			case 'c':
				SINE_DEBUG("channels %s specified\n", optarg);
				num_channels = atoi(optarg);
				break;
			default:
				printf("Usage: ./sine_wave_gen" 
					"[-t <time in secs>] |"
					"[-f <wave freq in Hz>] |"
					"[-s <sampling rate in Hz>]\n");
				exit(EXIT_FAILURE);
		}
	}

	sprintf(file_name, "sine_%d_%dchannel_%dHz_%dsecs.wav",
			sampling_rate, num_channels, freq, tsecs);
	unlink(file_name);
	fd = open(file_name, O_CREAT | O_RDWR, 0666);
	samples_per_cycle = (float) sampling_rate / (float)freq;
	/*
		Each sample is 2 bytes. 
		2 bytes * num_channels = 1 sample for each channel.
		1 sample for each channel * number of samples per second = 
			total bytes of data in 1 sec.
		Total bytes of data in 1 sec * total time = total data size.
	*/
	data_size = tsecs *  sampling_rate * num_channels * 2;
	SINE_DEBUG("data_size=%d\n", data_size);
	SINE_DEBUG("header size = %d\n", sizeof(struct WAV_Header));
	fill_header(&header, num_channels, sampling_rate, data_size);
	write(fd,&header,sizeof(header));

	for (tloop = 0; tloop < tsecs; tloop++) {
		for (wloop = 0; wloop < freq; wloop++) {
			for (sloop = 0.0; sloop < samples_per_cycle; sloop += 1.0) {
				/* Angle changes from 0-2pi in 1 cycle */
				angle = (sloop * 2 * M_PI) / samples_per_cycle;
				value = (short) (amplitude * sinf(angle));
				SINE_DEBUG("angle=%f value=%d\n", angle, value);
				for(cloop = 0; cloop < num_channels; cloop++)
					write(fd, &value, sizeof(value));
			}
		}
	}

	close(fd);
	printf("Generated file name: %s\n", file_name);

	exit(EXIT_SUCCESS);
}
