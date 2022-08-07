#!/bin/sh

i="usr/bin/acpi usr/bin/base64 usr/bin/basename bin/blkid usr/bin/blockdev \
usr/bin/bzcat usr/bin/cal bin/cat bin/chattr bin/chgrp bin/chmod bin/chown \
usr/sbin/chroot usr/sbin/chvt bin/cksum usr/bin/clear usr/bin/cmp \
usr/bin/comm usr/bin/count bin/cp bin/cpio bin/cut bin/date usr/sbin/df \
usr/bin/dirname bin/dmesg bin/dos2unix usr/bin/du bin/echo bin/egrep \
usr/bin/eject usr/bin/env usr/bin/expand usr/bin/factor bin/false \
bin/fgrep usr/bin/find usr/bin/free sbin/freeramdisk usr/sbin/fsfreeze \
bin/fstype bin/grep usr/bin/groups bin/halt bin/head bin/help bin/hostname \
bin/id bin/ifconfig usr/bin/inotifyd bin/insmod usr/bin/install bin/kill \
usr/bin/killall sbin/killall5 usr/bin/link bin/ln bin/login bin/logname \
sbin/losetup bin/ls bin/lsattr bin/lsmod usr/bin/lspci usr/bin/lsusb \
usr/bin/makedevs usr/bin/md5sum usr/bin/mix bin/mkdir bin/mkfifo bin/mknod \
usr/bin/mkpasswd sbin/mkswap bin/mktemp bin/modinfo usr/bin/mount \
bin/mountpoint bin/mv usr/bin/nbd-client bin/nc bin/netcat usr/bin/nice \
bin/nl usr/bin/nohup usr/bin/od sbin/oneit sbin/partprobe usr/bin/passwd \
bin/paste usr/bin/patch usr/bin/pidof usr/bin/pivot_root bin/pmap \
bin/poweroff usr/bin/printenv usr/bin/printf bin/pwd usr/bin/pwdx \
bin/readahead bin/readlink usr/bin/realpath bin/reboot bin/renice \
usr/bin/rev sbin/rfkill bin/rm bin/rmdir bin/rmmod usr/bin/sed usr/bin/seq \
usr/bin/setsid usr/bin/sha1sum bin/sleep usr/bin/sort usr/bin/split \
bin/stat usr/bin/strings bin/su bin/swapoff bin/swapon sbin/switch_root \
bin/sync usr/bin/sysctl usr/bin/tac bin/tail bin/taskset bin/tee usr/bin/time \
bin/timeout bin/touch bin/true bin/truncate usr/bin/tty bin/umount \
bin/uname bin/uniq bin/unix2dos usr/bin/unlink usr/bin/unshare usr/bin/uptime \
bin/usleep usr/bin/uudecode usr/bin/uuencode sbin/vconfig bin/vmstat \
usr/bin/w usr/bin/wc usr/bin/which bin/who bin/whoami usr/bin/xargs \
usr/bin/yes"

for name in $i;
do
	lnk_name=`basename $name`
	echo "ln -sf /system/xbin/toybox $lnk_name" >> target.sh
done
