#!/bin/bash

# 9. Sa se scrie un program shell care pentru fiecare fisier cu drepturile 755 dintr-un director (si 
# subdirectoarele sale) dat ca parametru ii schimba drepturile de acces in 744.
# Inainte de a schimba drepturile de acces, pogramul cere confirmare din partea utilizatorului (pentru fiecare 
# fisier in parte). (comenzi: find, chmod, read)

find $D -perm 664 | while read F
do	
	echo $F
	echo "Do you want to change permissions?"
	read n </dev/tty
	
	if [ $n -eq 1 ]; then
		chmod 664 $F
	fi
done
