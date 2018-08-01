#!/bin/bash 

for((i=0;i<$2;i++))
do
	echo $i
	s=`expr $i \* 30`
	ffmpeg -i $1 -vcodec copy -acodec copy -ss $s -t 30 shortvideo_30s_$i.avi
done

