**English(Current)** | [中文版](zh_cn.md)
# GDExtension-Fast-Syntax
A lingual extension for GDExtension C++ that provides fast access to common functions

# How to Use?
1. Clone the project to the directory of the projects you are working on:
2. Input this code to the source code where you have made a reference to fast syntax first:
```C++
#include "fast_syntax.hpp"
using namespace gde_fast_syntax;
```
3. In `SConstruct` file, include the path to the fast_syntax, and here it's recommended to rewrite your config as:
```Python
fast_syntax = "fast_syntax/" # Here the path should be modified according to the situation of yours
...
# Rewrite default "env.Append"
env.Append(["src/", fast_syntax])
...
sources += Glob(fast_syntax + "*.cpp")
```
For Example, if your directory tree is like this:
```
Top
  > project
    > src
    > lib
    > bin
    SConstruct
  > fast_syntax
    > ...
    > ...
```
You need to rewrite your SConstruct like this, with "..." replacing the repeated parts
```Python
fast_syntax = "../fast_syntax/"
...
env.Append(["src/", fast_syntax])
...
sources += Glob(fast_syntax + "*.cpp")
...
```
