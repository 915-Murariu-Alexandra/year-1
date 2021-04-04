#!/bin/bash

# 6. Sa se scrie un fisier de comenzi care are ca parametri triplete formate dintr-un nume de fisier, un cuvant si 
# un numar k.
# Pentru fiecare astfel de triplet, se vor afisa toate liniile fisierului care contin cuvantul respectiv exact de 
# k ori.
# (comenzi: shift, awk)
nr_args=`expr $# / 3`
for ((i=0; i<$nr_args;i++))
do
        if test -f $1
        then
		echo $1  
                if echo $3 | grep -q -E "\-?[0-9]*\.?[0-9]+"; then
		
			awk -v word=$2 -v occ=$3 '{nr=0;for(i=1;i<=NF;i++){if($i==word){nr++;}}if(nr==occ){print $0}}' $1;
		fi
        fi
	shift 3
	
done

