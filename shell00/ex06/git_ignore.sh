#!/bin/bash
set -e
files=$(git ls-files -o)
for f in $files
do

    echo $f
done

