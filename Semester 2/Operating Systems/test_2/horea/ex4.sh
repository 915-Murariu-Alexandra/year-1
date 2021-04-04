#!/bin/bash

# 4. Write a bash script that sorts all files given as command line arguments descending by size.(first check if 
# an argument is a file)

N=0
for file_name in $*
do
	if [ -f "$file_name" ]; then 
		a[$N]=`ls -l $file_name | awk '{print $5}'`
		files[$N]=$file_name
		N=$((N+1))
	fi
done
for i in $(seq 0 $((N-1))); do
	for j in $(seq $((i+1)) $((N-1))); do
		echo i is $i ${a[$i]}
		echo j is $j ${a[$j]}
		if [[ ${a[$i]} -lt ${a[$j]} ]]; then
			aux=${a[$i]}
			a[$i]=${a[$j]}
			a[$j]=$aux
			aux=${files[$i]}
			files[$i]=${files[$j]}
			files[$j]=$aux
		fi
	done
done

for i in $(seq 0 $((N-1))); do
	echo ${files[$i]} has size ${a[$i]}
done

