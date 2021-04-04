#!/bin/bash

# 9. Calculate the average of all process ids in the system per user.

ps -ef | awk '{arr[$1] = arr[$1] + $2; nr_proc[$1]+=1;}END{for (i in arr){print "The user " i " has " arr[i]/nr_proc[i] " average"}}'


