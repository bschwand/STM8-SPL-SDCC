STM8S SPL, patched for use with SDCC
=================

This version of the STM8S Standard Peripheral library has the following changes:
- original files from [STSW-STM8069](http://www.st.com/en/embedded-software/stsw-stm8069.html)
- patched with [STM8-SPL_SDCC_patch](https://github.com/gicking/STM8-SPL_SDCC_patch)
- all C files were split into one function per file, so as to allow SDCC linker to do dead code elimination
- a makefile for an spl library was introduced
- the makefile for STM8S_StdPeriph_Template and STM8S_StdPeriph_test illustrate how to create a simple application with the SPL and SDCC
- just type make in Project/STM8S_StdPeriph_test/SDCC to build the example and spl.lib

NB: the examples in STM8S_StdPeriph_Examples have NOT been updated, this is a work in progress.

LICENSE
=================

The original licenses remain, these sources are useable under the terms of [SLA044](http://www.st.com/SLA0044).

Toolchain Installation for SDCC
=================

  - if required, download and install [SDCC](http://sdcc.sourceforge.net/) and Gnu-Make. Add binaries to $(PATH)
  - for STM8 programming via SWIM debug interface
    - install libusb-dev (e.g. `sudo apt-get install libusb-1.0-0-dev`)
    - download and make [stm8flash](https://github.com/vdudouyt/stm8flash) source code
    - on Linux grant write access to ST-Link debugger by creating a file `/etc/udev/rules.d/99-stlinkv2.rules` with content  
    `SUBSYSTEM=="usb", ATTRS{idVendor}=="0483", ATTRS{idProduct}=="3744", MODE="0666"`  
    Note: since several versions of ST-Link exist, check the idProduct of your device via command `usb-devices`
  - for STM8 programming via serial bootloader
    - download and make [stm8gal](https://github.com/gicking/stm8gal) source code
  - if necessary, set execute permission for build scripts in project folders

### Notes

  - the SPL projects are also compatible with other compilers and IDEs, e.g. [Cosmic](http://www.cosmic-software.com/) and [STVisualDevelop](http://www.st.com). These are not tested or supported by the build scripts, but allow graphical debugging which is not yet supported by SDCC 
  - on Windows
    - SWIM upload can also be performed via [STVisualProgrammer](http://www.st.com). Please adapt build scripts accordingly
    - bootloader upload can also be performed via [Flash Loader Demonstrator](http://www.st.com). However, this is not supported by the automatic build
