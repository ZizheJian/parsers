# parsers

[English](README.md) | **中文**

`parsers`把命令行参数的文字转成整数、小数或布尔值，格式不对或超出范围时报错。仓库提供C++版和Python版，两者的规则相同。

## 函数

| 函数 | 返回 | 接受 | 不接受 |
|---|---|---|---|
| `parse_uint64` | 0到2^64-1的整数 | `0`、`42` | `+42`、`-1`、`007`、`1.0`、`1e3` |
| `parse_uint32` | 0到2^32-1的整数 | 同上 | 同上 |
| `parse_positive_uint32` | 1到2^32-1的整数 | `1`、`42` | `0`，以及上面不接受的写法 |
| `parse_positive_double` | double范围内的有限正数 | `1`、`1.5`、`.5`、`1.`、`1e-3`、`1e+3` | `+1.5`、`0`、`-1`、`inf`、`nan`、`1e400` |
| `parse_positive_float` | float范围内的有限正数，舍入到float精度 | 同上 | `+1.5`、`0`、`-1`、`inf`、`nan`、`1e39` |
| `parse_bool` | true或false | `true`、`false` | `True`、`1`、`yes` |

所有函数都不接受前后的空格。

每个函数有两个参数：要解析的文字和参数名。参数名用在报错信息里，例如`parse_positive_float("abc","-M的error bound")`会报`-M的error bound必须是正数：abc`。参数名可以省略，`parse_positive_float("abc")`会报`必须是正数：abc`。C++版抛出`std::runtime_error`，Python版抛出`ValueError`。

## C++

在CMake里把目录加为子目录，再链接目标：

```cmake
add_subdirectory(third_party/parsers/c_codes ${CMAKE_BINARY_DIR}/parsers_build)
target_link_libraries(my_target PRIVATE parsers)
```

```cpp
#include <parsers.hpp>

uint32_t thread_num=parse_positive_uint32(argv[2],"-t");
float error_bound=parse_positive_float(argv[4],"-M的error bound");
```

## Python

仓库以子模块形式放在`third_party/parsers`时：

```python
from third_party.parsers.py_codes.parse_positive_uint32 import parse_positive_uint32
from third_party.parsers.py_codes.parse_positive_float import parse_positive_float

thread_num=parse_positive_uint32("8","-t")
error_bound=parse_positive_float("1e-3","-M的error bound")
```
