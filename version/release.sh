#!/bin/bash 

ReleaseTime="YYY/MM/DD-hh:mm:ss CST"

get_release_time_func()
{
	ReleaseTime=`date '+%Y-%m-%d %H:%M:%S %Z'`
	echo ${ReleaseTime}
	sed -i "s/ReleaseTime = .*/ReleaseTime = \"${ReleaseTime}\"/" ./version.txt
}

get_release_time_func

#echo "----- Start release -----"

##cp ./version.txt version_bak.txt
##chmod 444 version_bak.txt
#exe_file=./xDetection
#run_file=./run.sh
#pushd ../work/exe
#if [ -f ${exe_file} ]; then
#  mv ${exe_file} ./xDetection_bak
#fi
#if [ -f ${run_file} ]; then
#  mv ${run_file} ./run_bak.sh
#fi
#popd

#pushd ../src
#make
#cp xDetection ../work/exe
#cp run.sh ../work/exe
#popd

#cp ./version.txt ../work/version/
#chmod 444 ../work/version/version.txt

#echo "----- End release -----"
