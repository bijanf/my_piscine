#!/bin/bash
set -e

#find all files with .sh at the end and print only the filename
find . -type f -name "*.sh" -printf "%f\n" | sed 's|.sh$||'

