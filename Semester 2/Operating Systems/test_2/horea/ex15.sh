#!/bin/bash

# 15. Write a shell script that, for all the users in /etc/passwd, creates a file with the same name as the 
# username and writes in it all the ip addresses from which that user has logged in. (hint: use the last command 
# to find the ip addresses)

awk -F: '{print $1}' passwd.fake >> users_passwd.txt 
while read -r line
do
	touch $line.txt
	grep "$line" passwd.fake | awk -F: '{print $6}' > $line.txt
done < users_passwd.txt


