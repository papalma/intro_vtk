# Introduction to VTK basics
This notes intends to show developers some of the basic on VTK programming in simple environment. There are many details lost in the documentation that difficults being productive when biggining using this toolkit.

Feel free to contact me for suggestion or comments. 

[Patricio Palma](mailto:patriciop at gmail)

## Requirements
* At least VTK v6.1 (tested on v8.1)
* C++11 (tested on Clang v6.0)
* Make

## Building
Define VTK path in VTKDIR environment variable. If you are using a version of VTK diffent from 8.1 you must define VTKVER variable. For example:
```
export VTKDIR=/usr/local/vtk
export VTKVER=7.0
```
Then run `make` command to build the examples.
Check the provided Makefile and adjust to your own setup.

## Known Issues
On Mac OS 10.14.1 there are still some bugs (comfirmed by Apple) that causes problems displaying and resizing the VTK window. You have to click on the screen to force rendering.