# ms-strlib
C String library contains the following functions:
- ```ms_strlib_remove_backspaces()```
- ```ms_strlib_strtok()```
- ```ms_strlib_strdelch()```
- ```ms_strlib_toupper()```
- ```ms_strlib_tolower()```


# Build (Windows)
1. install cygwin from [here](https://cygwin.com/install.html) - make sure to install libtool, gcc and gdb
2. setup CLion to use cygwin compiler
3. Clone project
```git clone --recursive git@github.com:Mrunmoy/ms-strlib.git```
4. Open in CLion
    
    4.1 you can use 64-bit or 32-bit cygwin to build cpputest. If you do not wish to [build](https://stackoverflow.com/questions/28744630/how-to-compile-cpputest-in-cygwin) cpputest, it's prebuilt for 64-bit)
5. Select target as `strlib-unit-tests`
6. Build and Run

# Usage
Check [TestStrLib.cpp](https://github.com/Mrunmoy/ms-strlib/blob/master/test/TestStrLib.cpp) for usage examples.


# ToDo
Setup cmake to build on linux as well
