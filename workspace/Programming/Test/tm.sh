#!/system/bin/sh

start()
{
	ds=`date +"%Y%m%d-%H%M%S"`
	logfile=$HOME/thermal_log_$ds.csv
	tjmax=`cat /sys/bus/platform/devices/coretemp.0/temp2_crit`
	
	files=`ls /sys/class/thermal/thermal_zone*`
	for file in $files; do
		sensor=`cat $file/type`
		if [ "$sensor" = "STR0" ]; then
			str0path=$file
		elif [ "$sensor" = "STR2" ]; then
			str2path=$file
		elif [ "$sensor" = "STR3" ]; then
			str3path=$file
		fi
	done
	
	files=`ls /sys/class/thermal/cooling_device*`
	for file in $files; do
		cdev=`cat $file/type`
		if [ "$cdev" = "bq24192_charger" ]; then
			cdevpath=$file
		fi
	done
	
	let "tjmax = tjmax / 1000"
	echo "Start logging to $logfile...."
	echo "STR0:$str0path"
	echo "STR2:$str2path"
	echo "STR3:$str3path"
	echo "bq24192_charger:$cdevpath"
	echo "date;systherm0;systherm2;systherm3;dts1;dts2;CC_throttle_state;current_now;voltage_ocv;capacity;status;battery health;charger health" > $logfile
	while [ 1 ]; do
		dat=`date +"%Y-%m-%d %H:%M:%S"`
		str0=`cat $str0path/temp`
		str2=`cat $str2path/temp`
		str3=`cat $str3path/temp`
		cc=`cat $cdevpath/cur_state`
		cnow=`cat /sys/class/power_supply/max170xx_battery/current_now`
		vocv=`cat /sys/class/power_supply/max170xx_battery/voltage_ocv`
		cap=`cat /sys/class/power_supply/max170xx_battery/capacity`
		status=`cat /sys/class/power_supply/max170xx_battery/status`
		bhealth=`cat /sys/class/power_supply/max170xx_battery/health`
		chealth=`cat /sys/class/power_supply/bq24192_charger/health`
		val=`peeknpoke n r 4 b1 | cut -d ' ' -f 7`
		let "val = val & 0xFFFF"
		let "v1 = val >> 8"
		let "v2 = val & 0xFF"
		let "dts1 = 127 + tjmax - v1"
		let "dts1 = dts1 * 1000"
		let "dts2 = 127 + tjmax - v2"
		let "dts2 = dts2 * 1000"
		echo "$dat;$str0;$str2;$str3;$dts1;$dts2;$cc;$cnow;$vocv;$cap;$status;$bhealth;$chealth" >> $logfile
		sleep 1
	done
}

stop()
{
	psname=`basename $0`
	echo "Stopping $psname..."
	killall $psname
}

usage()
{
	echo "Usage:"
	echo "	$0 [start|stop]"
}

case $1 in 
	"start" | "Start")
		start &
		;;
	"stop" | "Stop")
		stop
		;;
	*)
		usage
		;;
esac
