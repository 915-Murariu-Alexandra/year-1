#!/bin/sh

if gcc -o myprog $1

then ./myprog $*

else echo "Erori de compilare"

fi
