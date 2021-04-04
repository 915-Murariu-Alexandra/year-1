#!/bin/bash
#7. Sa se afiseze pentru fiecare fisier din linia de comanda linia care apare de cele mai multe ori,
# afisarea facandu-se in ordinea descrescatoare a numarului de aparitii.
# (comenzi: sort, uniq, head)

for A in $@
do
	echo $A
	awk '{a[$0]++} END {for(k in a) print a[k], k}' $A | sort -r -k 1 -n
done
