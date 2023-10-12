[English](README.md) | **中文版（当前页面）**
# GDExtension Fast Syntax
一个为GDExtension开发者而定制的快速调用常用方法的语言接口集

# 如何使用？
1. 将本repo克隆到你的工程目录文件夹下
2. 在你的工程源文件需要用到的地方中输入以下源代码：
```C++
#include "fast_syntax.hpp"
using namespace gde_fast_syntax;
```
3. 向`SConstruct`按如下格式调整，并加入fast_syntax所在目录:
```Python
fast_syntax = "fast_syntax/" # 这里这个目录路径根据你项目的实际情况进行调整
...
# Rewrite default "env.Append"
env.Append(["src/", fast_syntax])
...
sources += Glob(fast_syntax + "*.cpp")
```
倘若你的工程的文件结构长这样：
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
那么你的SConstruct就这样写（用"..."省去重复部分）:
```Python
fast_syntax = "../fast_syntax/"
...
env.Append(["src/", fast_syntax])
...
sources += Glob(fast_syntax + "*.cpp")
...
```
