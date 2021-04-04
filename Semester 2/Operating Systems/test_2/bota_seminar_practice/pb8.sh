#!/bin/bash

# 8. Sa se scrie un fisier de comenzi care va afisa toate numele de fisiere dintr-un director dat ca parametru
# si din subdirectoarele sale, care au numele mai scurte de 8 caractere.
# Pentru acestea, daca sunt fisiere text, li se vor afisa primele 10 linii.

D=$1

find $D | while read F
do
	if [ -f $F ]; then
		
		N=`echo $F | sed 's@.*/@@' | sed 's@\..*@@' | wc -c | awk '{print $1}'`
		
		if [ $N -le 8 ]; then
			echo $F
			if file $F | grep -q ": ASCII text$"; then
				head -n 10 $F
			fi
		fi
	fi
done
