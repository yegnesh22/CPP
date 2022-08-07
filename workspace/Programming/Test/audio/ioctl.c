#include <stdio.h>
#include <asm-generic/ioctl.h>
#include <linux/types.h>
#include <time.h>
#include <sound/asound.h>

#define PRINT_MACRO(x) printf("%s = %x\n", #x, x);

typedef int s32;
typedef unsigned int u32;
typedef s32	compat_time_t;
typedef long long s64;
typedef unsigned long long int u64;

struct compat_timespec {
        compat_time_t   tv_sec;
        s32             tv_nsec;
};


/*
 */
struct snd_xferi32 {
	s32 result;
	u32 buf;
	u32 frames;
};

/* snd_xfern needs remapping of bufs */
struct snd_xfern32 {
	s32 result;
	u32 bufs;  /* this is void **; */
	u32 frames;
};

struct snd_pcm_channel_info32 {
	u32 channel;
	u32 offset;
	u32 first;
	u32 step;
};

struct snd_pcm_status32 {
	s32 state;
	struct compat_timespec trigger_tstamp;
	struct compat_timespec tstamp;
	u32 appl_ptr;
	u32 hw_ptr;
	s32 delay;
	u32 avail;
	u32 avail_max;
	u32 overrange;
	s32 suspended_state;
	u32 reserved_alignment;
	struct compat_timespec audio_tstamp;
	unsigned char reserved[56-sizeof(struct compat_timespec)];
} __attribute__((packed));

struct snd_pcm_sw_params32 {
	s32 tstamp_mode;
	u32 period_step;
	u32 sleep_min;
	u32 avail_min;
	u32 xfer_align;
	u32 start_threshold;
	u32 stop_threshold;
	u32 silence_threshold;
	u32 silence_size;
	u32 boundary;
	unsigned char reserved[64];
};

struct snd_pcm_hw_params32 {
	u32 flags;
	struct snd_mask masks[SNDRV_PCM_HW_PARAM_LAST_MASK - SNDRV_PCM_HW_PARAM_FIRST_MASK + 1]; /* t    his must be identical */
	struct snd_mask mres[5];        /* reserved masks */
	struct snd_interval intervals[SNDRV_PCM_HW_PARAM_LAST_INTERVAL - SNDRV_PCM_HW_PARAM_FIRST_INTERVAL + 1];
	struct snd_interval ires[9];    /* reserved intervals */
	u32 rmask;
	u32 cmask;
	u32 info;
	u32 msbits;
	u32 rate_num;
	u32 rate_den;
	u32 fifo_size;
	unsigned char reserved[64];
};

struct snd_pcm_mmap_status32 {
	s32 state;
	s32 pad1;
	u32 hw_ptr;
	struct compat_timespec tstamp;
	s32 suspended_state;
	struct compat_timespec audio_tstamp;
} __attribute__((packed));

struct snd_pcm_mmap_control32 {
	u32 appl_ptr;
	u32 avail_min;
};

struct snd_pcm_sync_ptr32 {
	u32 flags;
	union {
		struct snd_pcm_mmap_status32 status;
		unsigned char reserved[64];
	} s;
	union {
		struct snd_pcm_mmap_control32 control;
		unsigned char reserved[64];
	} c;
} __attribute__((packed));

struct snd_ctl_elem_list32 {
	u32 offset;
	u32 space;
	u32 used;
	u32 count;
	u32 pids;
	unsigned char reserved[50];
} /* don't set packed attribute here */;

/* x32 has a different alignment for 64bit values from ia32 */
struct snd_ctl_elem_value_x32 {
	struct snd_ctl_elem_id id;
	unsigned int indirect;	/* bit-field causes misalignment */
	union {
		s32 integer[128];
		unsigned char data[512];
		s64 integer64[64];
	} value;
	unsigned char reserved[128];
};

/*
 * control element info
 * it uses union, so the things are not easy..
 */
struct snd_ctl_elem_info32 {
	struct snd_ctl_elem_id id; // the size of struct is same
	s32 type;
	u32 access;
	u32 count;
	s32 owner;
	union {
		struct {
			s32 min;
			s32 max;
			s32 step;
		} integer;
		struct {
			u64 min;
			u64 max;
			u64 step;
		} integer64;
		struct {
			u32 items;
			u32 item;
			char name[64];
			u64 names_ptr;
			u32 names_length;
		} enumerated;
		unsigned char reserved[128];
	} value;
	unsigned char reserved[64];
} __attribute__((packed));

/* read / write */
struct snd_ctl_elem_value32 {
	struct snd_ctl_elem_id id;
	unsigned int indirect;	/* bit-field causes misalignment */
        union {
		s32 integer[128];
		unsigned char data[512];
#ifndef CONFIG_X86_64
		s64 integer64[64];
#endif
        } value;
        unsigned char reserved[128];
};

enum {
	SNDRV_PCM_IOCTL_HW_REFINE32 = _IOWR('A', 0x10, struct snd_pcm_hw_params32),
	SNDRV_PCM_IOCTL_HW_PARAMS32 = _IOWR('A', 0x11, struct snd_pcm_hw_params32),
	SNDRV_PCM_IOCTL_SW_PARAMS32 = _IOWR('A', 0x13, struct snd_pcm_sw_params32),
	SNDRV_PCM_IOCTL_STATUS32 = _IOR('A', 0x20, struct snd_pcm_status32),
	SNDRV_PCM_IOCTL_DELAY32 = _IOR('A', 0x21, s32),
	SNDRV_PCM_IOCTL_CHANNEL_INFO32 = _IOR('A', 0x32, struct snd_pcm_channel_info32),
	SNDRV_PCM_IOCTL_REWIND32 = _IOW('A', 0x46, u32),
	SNDRV_PCM_IOCTL_FORWARD32 = _IOW('A', 0x49, u32),
	SNDRV_PCM_IOCTL_WRITEI_FRAMES32 = _IOW('A', 0x50, struct snd_xferi32),
	SNDRV_PCM_IOCTL_READI_FRAMES32 = _IOR('A', 0x51, struct snd_xferi32),
	SNDRV_PCM_IOCTL_WRITEN_FRAMES32 = _IOW('A', 0x52, struct snd_xfern32),
	SNDRV_PCM_IOCTL_READN_FRAMES32 = _IOR('A', 0x53, struct snd_xfern32),
	SNDRV_PCM_IOCTL_SYNC_PTR32 = _IOWR('A', 0x23, struct snd_pcm_sync_ptr32),
};

enum {
	SNDRV_CTL_IOCTL_ELEM_LIST32 = _IOWR('U', 0x10, struct snd_ctl_elem_list32),
	SNDRV_CTL_IOCTL_ELEM_INFO32 = _IOWR('U', 0x11, struct snd_ctl_elem_info32),
	SNDRV_CTL_IOCTL_ELEM_READ32 = _IOWR('U', 0x12, struct snd_ctl_elem_value32),
	SNDRV_CTL_IOCTL_ELEM_WRITE32 = _IOWR('U', 0x13, struct snd_ctl_elem_value32),
	SNDRV_CTL_IOCTL_ELEM_ADD32 = _IOWR('U', 0x17, struct snd_ctl_elem_info32),
	SNDRV_CTL_IOCTL_ELEM_REPLACE32 = _IOWR('U', 0x18, struct snd_ctl_elem_info32),
	SNDRV_CTL_IOCTL_ELEM_READ_X32 = _IOWR('U', 0x12, struct snd_ctl_elem_value_x32),
	SNDRV_CTL_IOCTL_ELEM_WRITE_X32 = _IOWR('U', 0x13, struct snd_ctl_elem_value_x32),
};


main()
{
	PRINT_MACRO(SNDRV_PCM_IOCTL_HW_REFINE32);
	PRINT_MACRO(SNDRV_PCM_IOCTL_HW_PARAMS32);
	PRINT_MACRO(SNDRV_PCM_IOCTL_SW_PARAMS32);
	PRINT_MACRO(SNDRV_PCM_IOCTL_STATUS32);
	PRINT_MACRO(SNDRV_PCM_IOCTL_DELAY32);
	PRINT_MACRO(SNDRV_PCM_IOCTL_CHANNEL_INFO32);
	PRINT_MACRO(SNDRV_PCM_IOCTL_REWIND32);
	PRINT_MACRO(SNDRV_PCM_IOCTL_FORWARD32);
	PRINT_MACRO(SNDRV_PCM_IOCTL_WRITEI_FRAMES32);
	PRINT_MACRO(SNDRV_PCM_IOCTL_READI_FRAMES32);
	PRINT_MACRO(SNDRV_PCM_IOCTL_WRITEN_FRAMES32);
	PRINT_MACRO(SNDRV_PCM_IOCTL_READN_FRAMES32);
	PRINT_MACRO(SNDRV_PCM_IOCTL_SYNC_PTR32);
	PRINT_MACRO(SNDRV_PCM_IOCTL_WRITEI_FRAMES);
	PRINT_MACRO(SNDRV_PCM_IOCTL_PVERSION);
	PRINT_MACRO(SNDRV_PCM_IOCTL_INFO);
	PRINT_MACRO(SNDRV_PCM_IOCTL_TSTAMP);
	PRINT_MACRO(SNDRV_PCM_IOCTL_TTSTAMP);
	PRINT_MACRO(SNDRV_PCM_IOCTL_HWSYNC);
	PRINT_MACRO(SNDRV_PCM_IOCTL_PREPARE);
	PRINT_MACRO(SNDRV_PCM_IOCTL_RESET);
	PRINT_MACRO(SNDRV_PCM_IOCTL_START);
	PRINT_MACRO(SNDRV_PCM_IOCTL_DROP);
	PRINT_MACRO(SNDRV_PCM_IOCTL_DRAIN);
	PRINT_MACRO(SNDRV_PCM_IOCTL_PAUSE);
	PRINT_MACRO(SNDRV_PCM_IOCTL_HW_FREE);
	PRINT_MACRO(SNDRV_PCM_IOCTL_RESUME);
	PRINT_MACRO(SNDRV_PCM_IOCTL_XRUN);
	PRINT_MACRO(SNDRV_PCM_IOCTL_LINK);
	PRINT_MACRO(SNDRV_PCM_IOCTL_UNLINK);
	printf("##############################\n");
	PRINT_MACRO(SNDRV_CTL_IOCTL_PVERSION);
	PRINT_MACRO(SNDRV_CTL_IOCTL_CARD_INFO);
	PRINT_MACRO(SNDRV_CTL_IOCTL_ELEM_LIST);
	PRINT_MACRO(SNDRV_CTL_IOCTL_ELEM_INFO);
	PRINT_MACRO(SNDRV_CTL_IOCTL_ELEM_READ);
	PRINT_MACRO(SNDRV_CTL_IOCTL_ELEM_WRITE);	
	PRINT_MACRO(SNDRV_CTL_IOCTL_ELEM_LOCK);
	PRINT_MACRO(SNDRV_CTL_IOCTL_ELEM_UNLOCK);
	PRINT_MACRO(SNDRV_CTL_IOCTL_SUBSCRIBE_EVENTS);
	PRINT_MACRO(SNDRV_CTL_IOCTL_ELEM_ADD);
	PRINT_MACRO(SNDRV_CTL_IOCTL_ELEM_REPLACE);
	PRINT_MACRO(SNDRV_CTL_IOCTL_ELEM_REMOVE);
	PRINT_MACRO(SNDRV_CTL_IOCTL_TLV_READ);
	PRINT_MACRO(SNDRV_CTL_IOCTL_TLV_WRITE);
	PRINT_MACRO(SNDRV_CTL_IOCTL_TLV_COMMAND);
	PRINT_MACRO(SNDRV_CTL_IOCTL_HWDEP_NEXT_DEVICE);
	PRINT_MACRO(SNDRV_CTL_IOCTL_HWDEP_INFO);
	PRINT_MACRO(SNDRV_CTL_IOCTL_PCM_NEXT_DEVICE);
	PRINT_MACRO(SNDRV_CTL_IOCTL_PCM_INFO);
	PRINT_MACRO(SNDRV_CTL_IOCTL_PCM_PREFER_SUBDEVICE);
	PRINT_MACRO(SNDRV_CTL_IOCTL_RAWMIDI_NEXT_DEVICE);
	PRINT_MACRO(SNDRV_CTL_IOCTL_RAWMIDI_INFO);
	PRINT_MACRO(SNDRV_CTL_IOCTL_RAWMIDI_PREFER_SUBDEVICE);
	PRINT_MACRO(SNDRV_CTL_IOCTL_POWER);
	PRINT_MACRO(SNDRV_CTL_IOCTL_POWER_STATE);
	PRINT_MACRO(SNDRV_CTL_IOCTL_ELEM_LIST32);
	PRINT_MACRO(SNDRV_CTL_IOCTL_ELEM_INFO32);
	PRINT_MACRO(SNDRV_CTL_IOCTL_ELEM_READ32);
	PRINT_MACRO(SNDRV_CTL_IOCTL_ELEM_WRITE32);
	PRINT_MACRO(SNDRV_CTL_IOCTL_ELEM_ADD32);
	PRINT_MACRO(SNDRV_CTL_IOCTL_ELEM_REPLACE32);
	PRINT_MACRO(SNDRV_CTL_IOCTL_ELEM_READ_X32);
	PRINT_MACRO(SNDRV_CTL_IOCTL_ELEM_WRITE_X32);
}
