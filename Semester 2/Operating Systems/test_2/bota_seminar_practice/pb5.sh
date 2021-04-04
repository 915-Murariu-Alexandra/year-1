#!/bin/bash

# 5. Pentru fiecare parametru din linia de comanda: dacÄ e fisier, se vor afisa numele, numarul de caractere
# si de linii din el (in aceasta ordine), iar daca e director, numele si cate fisiere contine (inclusiv in 
# subdirectoare).
# (comenzi: test, wc, awk, find)

for A in $@
do
	if test -f $A
	then
		echo $A
		wc -c $A | awk '{print $1}'
		wc -l $A | awk '{print $1}'
	elif test -d $A
	then
		echo $A
		find $A -type f | wc -l
	else
		echo "This is neither a file, nor a directory"
	fi
done
