#!/bin/bash

# 3. Afisati primele 5 linii si ultimele 5 linii ale fisierelor de tip text din directorul curent.
# DacÄ un fisier are mai putin de 10 linii, afisati fisierul complet.
# (comenzi: head, tail, find, file, wc)


D=$1

find $D -type f -name "*.txt" | while read F
do
	N=`wc -l $F | awk '{print $1}'`
	if [ $N -le 10 ]; then
		awk '{print $0}' $F
	else
		head -n 5 $F
		tail -n 5 $F
	fi
done

