#!/bin/bash 
set -e
ls -l | awk "NR%2==1"
