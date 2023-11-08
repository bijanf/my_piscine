#!/bin/bash 
# A program to show the MAC addresses of 
set -e
#extract the devices' names and MACid:
ifconfig -a | grep ether | awk '{print $2}'


