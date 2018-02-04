REM just for output
echo off
cls

REM set serial upload tool and serial port (stm8gal from https://github.com/gicking/stm8gal)
set LOADER="C:\Programme\stm8gal\stm8gal.exe"
set PORT=7

REM name of target hexfile
set TARGET=Debug\stm8af52ax.s19

REM ask user to put STM8 to bootloader mode
echo.
echo.
echo reset STM8 and press return
echo.
PAUSE 

REM upload using STM8 serial bootloader (stm8gal from https://github.com/gicking/stm8gal)
%LOADER% -p COM%PORT% -w %TARGET% -v

REM clean up
:END
PAUSE
echo on

