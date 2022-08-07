#!/system/bin/sh
logfile=/data/result.log

echo "time;bptherm;systherm" > $logfile
while [ 1 ]; do
	etime=`uptime`
	btemp=`cat /sys/class/thermal/thermal_zone0/temp`
	stemp=`cat /sys/class/thermal/thermal_zone5/temp`
	echo "$etime;$btemp;$stemp" >> $logfile
	sleep 1
done

