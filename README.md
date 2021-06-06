# XML to HTML
A simple C++ XML conversion code

This code was written to run on linux machines, and to compile with C++11 and older versions of C++.

We use 3rd party library Tinyxml2, which is a lightweight XML parser library. The file include Tinyxml2.h and Tinyxml2.cpp.

This project contains a test XML file cd_catalog.xml, but you can choose to convert your own XML file as well.

The output will be HTML table format file.


### Compilation
1. Creat build/ folder under your directory by using "mkdir build" under your project directory.
2. Use "cd build/" to enter the folder.
3. Use "cmake ../" to build files.
4. Use "make all" to compile and build the target "xmltohtml".
5. Run the excutable file "xmltohtml" in the build/ folder. You can click to run the executable program in your folder or run the instance manually.
