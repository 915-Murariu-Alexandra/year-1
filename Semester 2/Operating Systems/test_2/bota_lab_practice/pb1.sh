#!/bin/bash

#1. Să se scrie un script bash care primeşte ca argument un număr natural N şi generează N fişiere de tip text, 
# astfel:
# - numele fişierelor vor fi de forma: file_X.txt, unde X = {1, 2, ..., N}
# - fiecare fişier generat va conţine doar liniile de la X la X + 5 ale fişierului passwd.fake

N=$1
i=0
n2=0
while [ $i -lt $N ]
do
	touch file_$i.txt
	n2=$((i+6))
	n1=$((i+1))
	cat exercitii.txt | sed -n "$n1,$n2 p" > file_$i.txt
	i=$((i+1))
done
