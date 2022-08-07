#!/bin/sh

fg_cap_val=`cat capacity`
batt_status=`cat status`

if [ "$batt_status" = "Full" -o "$batt_status" = "full" ]; then
	echo 0 > charge_enable
fi

if [ $fg_cap_val = 1 ]; then
	echo 4 > charge_enable
fi
