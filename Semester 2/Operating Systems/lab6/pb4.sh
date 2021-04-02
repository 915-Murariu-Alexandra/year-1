#!/bin/bash
count=0
read f
while [ f != "exit" ]
do
	array[$count] = `ls -l | awk '{print $5}'`
	count = $((count+1))
	read f
done
echo $array
