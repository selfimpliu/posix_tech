#!/bin/bash
set -x

#inotifywait -m    --timefmt '%Y-%m-%d %H:%M:%S' --format '%T,%:e,%w,%f' testdir/file | grep "MODIFY" | awk -F "," '{print $3}'
inotifywait -m    --timefmt '%Y-%m-%d %H:%M:%S' --format '%T,%:e,%w,%f' testdir/file | 
while read file;
do
	filename=`echo $file | grep "MODIFY" | awk -F "," '{print $3}'`
#	echo $filename
#	cat $filename
done
