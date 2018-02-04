REM just for output
echo off
cls

REM target device (for supported devices see stm8s.h)
REM set DEVICE=STM8AF52Ax
set DEVICE=STM8S105

REM set make tool (if not in PATH, set complete path)
set MAKE=mingw32-make

REM use makefile to delete sdcc output
%MAKE% -f Makefile DEVICE=%DEVICE% clean

echo on

