#!/bin/bash

# 2. Să se scrie un script bash care primeşte ca argument un nume de director şi afişează primele 3 linii ale 
# fiecărui fişier de tip text din acel director.

D=$1

find $D -type f -name "*.txt" | while read F
do
	echo $F
	head -n 3 $F
done

