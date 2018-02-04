REM just for output
echo off
cls

REM target device (for supported devices see stm8s.h)
REM set DEVICE=STM8AF52Ax
set DEVICE=STM8S105

REM set make tool (if not in PATH, set complete path)
set MAKE=mingw32-make

REM set serial upload tool and serial port (stm8gal from https://github.com/gicking/stm8gal)
set BSL_LOADER="C:\Programme\stm8gal\stm8gal.exe"
set BSL_PORT=7

REM set SWIM upload tool and device name (stm8flash from https://github.com/vdudouyt/stm8flash)
REM set SWIM_LOADER=C:\Programme\stm8flash\stm8flash.exe"
REM set SWIM_TOOL=stlink
REM REM set SWIM_DEVICE=stm8af52a?
REM set SWIM_DEVICE=stm8s105?6

REM set SWIM upload tool and device name (STVP-STM8 on http://www.st.com)
set SWIM_LOADER="C:\Programme\STMicroelectronics\st_toolset\stvp\STVP_CmdLine.exe"
REM set SWIM_DEVICE=STM8AF52A
set SWIM_DEVICE=STM8S105x6

REM name of target hexfile
set TARGET=.\%DEVICE%\%DEVICE%.hex

REM compile and link
echo make application
%MAKE% -f Makefile DEVICE=%DEVICE%
IF ERRORLEVEL 1 GOTO END
echo done with application
echo.

REM GOTO END

REM upload using STM8 serial bootloader (stm8gal from https://github.com/gicking/stm8gal)
REM %BSL_LOADER% -p %BSL_PORT% -w %TARGET% -v

REM upload using SWIM debug interface (stm8flash from https://github.com/vdudouyt/stm8flash)
REM %SWIM_LOADER% -c %SWIM_TOOL% -w %TARGET% -p %SWIM_DEVICE%

REM upload using SWIM debug interface (STVP-STM8 on http://www.st.com)
%SWIM_LOADER% -BoardName=ST-LINK -Port=USB -ProgMode=SWIM -Device=%DEVICE_STVP% -readData -readOption -no_progData -no_progOption -no_loop -no_log -FileProg=%TARGET%

REM clean up
:END
PAUSE
echo on

