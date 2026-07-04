这是一个 C 语言风格的 C++ 字符处理头文件，核心功能是**处理字符类型**并提供**简单的字符转换工具**。

### 核心作用
它属于 C 标准库 `<ctype.h>` 在 C++ 中的兼容引入，专门用于**判断字符属性**和**大小写转换**。

### 常用函数与功能
| 函数 | 功能描述 | 示例 (输入 -> 输出) |
| :--- | :--- | :--- |
| **`isalpha(int c)`** | 是否为字母 (a-z, A-Z) | `isalpha('A')` → 非0 |
| **`isdigit(int c)`** | 是否为数字 (0-9) | `isdigit('5')` → 非0 |
| **`isalnum(int c)`** | 是否为字母或数字 | `isalnum('%')` → 0 |
| **`isupper(int c)`** | 是否为大写字母 | `isupper('b')` → 0 |
| **`islower(int c)`** | 是否为小写字母 | `islower('B')` → 0 |
| **`toupper(int c)`** | 转换为大写 | `toupper('a')` → 'A' |
| **`tolower(int c)`** | 转换为小写 | `tolower('A')` → 'a' |

### 使用注意事项
1. **参数类型**：传入参数通常为 `char`，但实际处理时会被提升为 `int`。
2. **边界问题**：**切勿直接传入负数**（如果 `char` 是有符号类型且字符值为负），这会导致未定义行为。
3. **C++ 推荐**：在 C++ 中，更推荐使用 `<cctype>` 而非 `<ctype.h>`，前者将函数放入 `std` 命名空间。

### 简单示例
```cpp
#include <cctype>
#include <iostream>
int main() {
    char c = 'a';
    if (std::isalpha(c)) {
        std::cout << std::toupper(c); // 输出 A
    }
    return 0;
}
```