#!/bin/bash 

# change to current working directory
cd `dirname $0`

# just for output
echo off
clear

# target device (for supported devices see stm8s.h)
DEVICE=STM8AF52Ax
#DEVICE=STM8S105

# set make tool (if not in PATH, set complete path)
MAKE=make

# use Makefiles to delete outputs
$MAKE -f Makefile DEVICE=$DEVICE clean 

echo on

