About pinger
======
Very simple multipalatform program to ping one host and status in the system tray.

Compiling
======
Make sure the Qt (>= 4.8) development libraries are installed:

* In Ubuntu/Debian: 'sudo apt-get install libqt4-dev'
* In Fedora:        'yum install qt-devel'
* In Arch Linux:    'pacman -S qt'
* In Windows:        Download and install from http://qt-project.org/downloads#qt-lib

Now you can compile by running:

You can open project in Qt Creator and compiling in it or in *nix systems you can compiling like this:

$ mkdir build

$ cd build

$ qmake ../pinger.pro

$ make

Installing 
======
In Windows should copy Qt dll in the folder with programm (QtGuid4.dll, QtCore4.dll,QtCored4.dll) 

In *nix you can use make install (Dont't use make install! http://habrahabr.ru/post/130868) or checkinstall

$checkinstall 
