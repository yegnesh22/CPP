#!/bin/bash

#n=`peeknpoke n r 4 b1`
#tjmax=`cat /sys/bus/platform/devices/coretemp.0/temp1_crit`
read val
tjmax=90000

#n=`echo $n | cut -d x -f 2`
#val=`echo $((16#$n))`
let "tjmax = tjmax / 1000"
let "val = val & 0xFFFF"
let "v1 = val >> 8"
let "v2 = val & 0xFF"
#$(v2=($val & $mask))
let "dts1 = 127 + tjmax - v1"
let "dts2 = 127 + tjmax - v2"
echo $val $v1 $v2 $dts1 $dts2
