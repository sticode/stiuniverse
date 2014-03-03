stiuniverse
===========

Space Game developed in C++

This project is compiled with i686-w64-mingw32 from CygWin

And oh wait !
You need python-2.7 to do some post build scripting
We strongly recommend to add your python path to the Env_Path.


how to build stiuniverse
========
We currently develop with i686-w64-mingw32-g++ that is available through CygWin. So we suggest that you download this compiler. Because we use c++11 flag, for std::chrono.
We also use python script to build without an IDE. These script are tested with Python-2.7

So to recap;

First, install cygwin and select i686-w64-mingw32-g++ package.

Second, install python-2.7 and add python path to your Environment Path

Third, you need to retrieve SDL2 library, we made a script to do all this, just run retrieve_extern.py

Fourth, you can now build StiUniverse by running build.py -DEBUG or only build.py for the release version. This script is pretending that your compiler is located in c:\cygwin64\bin, if not, your need to specify your compiler path with this flag : -CPATH$YOUR_PATH
