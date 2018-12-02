# Introduction to VTK basics
This notes intends to show developers some of the basic on VTK programming in simple environment. There are many details lost in the documentation that difficults being productive when biggining using this toolkit.

Feel free to contact me for suggestion or comments. 

[Patricio Palma](mailto:patriciop at gmail)

## Requirements
* At least VTK v6.1 (tested on v8.1)
* C++11 (tested on Clang v6.0)
* Make

## Building
Define installed VTK path in VTKDIR environment variable. For example:
```
export VTKDIR=/usr/local/vtk
```
Then run `make` command to build the examples.
If necessary check the provided Makefile and adjust to your own setup.
