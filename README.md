# parsers

**English** | [中文](README_CN.md)

`parsers` converts command-line argument text into integers, decimals or booleans, and raises an error when the format is wrong or the value is out of range. The repository provides a C++ version and a Python version that follow the same rules.

## Functions

| Function | Returns | Accepts | Rejects |
|---|---|---|---|
| `parse_uint64` | An integer from 0 to 2^64-1 | `0`, `42` | `+42`, `-1`, `007`, `1.0`, `1e3` |
| `parse_uint32` | An integer from 0 to 2^32-1 | Same as above | Same as above |
| `parse_positive_uint32` | An integer from 1 to 2^32-1 | `1`, `42` | `0` and the forms rejected above |
| `parse_positive_double` | A finite positive number within the double range | `1`, `1.5`, `.5`, `1.`, `1e-3`, `1e+3` | `+1.5`, `0`, `-1`, `inf`, `nan`, `1e400` |
| `parse_positive_float` | A finite positive number within the float range, rounded to float precision | Same as above | `+1.5`, `0`, `-1`, `inf`, `nan`, `1e39` |
| `parse_bool` | true or false | `true`, `false` | `True`, `1`, `yes` |

No function accepts leading or trailing spaces.

Each function takes two arguments: the text to parse and the argument name. The name appears in the error message. For example, `parse_positive_float("abc","-M error bound")` reports `-M error bound必须是正数：abc`. The name can be omitted, in which case `parse_positive_float("abc")` reports `必须是正数：abc`. The C++ version throws `std::runtime_error`, and the Python version raises `ValueError`.

## C++

Requires C++17 or later. Add the directory as a CMake subdirectory and link the target:

```cmake
add_subdirectory(third_party/parsers/c_codes ${CMAKE_BINARY_DIR}/parsers_build)
target_link_libraries(my_target PRIVATE parsers)
```

```cpp
#include <parsers.hpp>

uint32_t thread_num=parse_positive_uint32(argv[2],"-t");
float error_bound=parse_positive_float(argv[4],"-M error bound");
```

## Python

When the repository is a submodule at `third_party/parsers`:

```python
from third_party.parsers.py_codes.parse_positive_uint32 import parse_positive_uint32
from third_party.parsers.py_codes.parse_positive_float import parse_positive_float

thread_num=parse_positive_uint32("8","-t")
error_bound=parse_positive_float("1e-3","-M error bound")
```
