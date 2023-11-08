#!/bin/bash
set -e
# extract all groups where this user belongs to:
id -Gn $FT_USER | tr ' ' ',' | tr -d '\n'



