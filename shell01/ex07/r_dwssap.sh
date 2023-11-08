#!/bin/bash
set -e

FT_LINE1=7
FT_LINE2=15
list=$(cat /etc/passwd | grep -o '^[^:]*' | sed -n -e "${FT_LINE1},${FT_LINE2}p" | rev | sort -r )
echo ${list} | sed 's/ /,/g' | sed '$s/$/./'



