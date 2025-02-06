# Description

This project aims to show an example of custom menuconfig. 
The Kconfig.projbuild file was create with some custom options the will be available in the idf.py menuconfig when executed in the 03_custom_menuconfig folder. 

The result of the options selected in the menuconfig will be available in the header file 03_custom_menuconfig\build\config\sdkconfig.h as #defines.

The file main.c shows some examples of usage of the custom #defines available. 