#!/bin/bash

# 13. Consider a file containing a username on each line. Generate a comma-separated string with email addresses 
# of the users that exist. The email address will be obtained by appending "@scs.ubbcluj.ro" at the end of each 
# username. Make sure the generated string does NOT end in a comma.

awk '{print $1 "@scs.ubbcluj.ro"}' users.txt | sed -z 's/\n/,/g'
