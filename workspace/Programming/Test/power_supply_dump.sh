#!/system/bin/sh

BATTERY_PATH=/sys/class/power_supply/dollar_cove_battery
CHARGER_PATH=/sys/class/power_supply/dollar_cove_charger
LOGFILE=$HOME/pslog.txt

echo "Logging to $LOGFILE....."

echo "uptime;capacity;status;temp;current now;charge now;charge full;voltage now;voltage ocv;battery health;charger type;charge current;charge control limit; charger health;inlimit;enable charger;enable charging" > $LOGFILE 

while [ 1 ]; do
	utime=`uptime`
	capacity=`cat $BATTERY_PATH/capacity`
	status=`cat $BATTERY_PATH/status`
	temp=`cat $BATTERY_PATH/temp`
	cnow=`cat $BATTERY_PATH/current_now`
	chg_now=`cat $BATTERY_PATH/charge_now`
	chg_full=`cat $BATTERY_PATH/charge_full`
	vnow=`cat $BATTERY_PATH/voltage_now`
	vocv=`cat $BATTERY_PATH/voltage_ocv`
	bhealth=`cat $BATTERY_PATH/health`
	type=`cat $CHARGER_PATH/type`
	cc=`cat $CHARGER_PATH/charge_current`
	control_limit=`cat $CHARGER_PATH/charge_control_limit`
	chealth=`cat $CHARGER_PATH/health`
	inlimit=`cat $CHARGER_PATH/input_cur_limit`
	enable_charger=`cat $CHARGER_PATH/enable_charger`
	enable_charging=`cat $CHARGER_PATH/enable_charging`
	echo "$utime;$capacity;$status;$temp;$cnow;$chg_now;$chg_full;$vnow;$vocv;$bhealth;$type;$cc;$control_limit;$chealth;$inlimit;$enable_charger;$enable_charging" >> $LOGFILE
	sleep 1
done

