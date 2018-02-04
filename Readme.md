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
