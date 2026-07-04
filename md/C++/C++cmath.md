`#include <cmath>` 是 C++ 标准库头文件，用于提供**数学函数支持**，兼容 C <math.h>`（C++ 中推荐<cmath>`，函数位于 `std` 命名空间），核心用于各类基础数学运算、三角函数、指数对数运算等。

### 一、核心功能分类（高频常用）
1.  基础算术运算
    - `sqrt(double x)`：求平方根（例：`sqrt(4.0)` → 2.0）
    - `cbrt(double x)`：求立方根（例：`cbrt(-8.0)` → -2.0）
    - `pow(double base, double exp)`：求幂（base 的 exp 次方，例：`pow(2, 3)` → 8.0）
    - `fabs(double x)`：求绝对值（适用于浮点数，例：`fabs(-3.14)` → 3.14）

2.  三角函数（参数为**弧度制**，非角度制）
    - `sin(double x)`：正弦函数
    - `cos(double x)`：余弦函数
    - `tan(double x)`：正切函数
    - 辅助：`degrees(double rad)`（弧度转角度）、`radians(double deg)`（角度转弧度）

3.  指数与对数运算
    - `exp(double x)`：求 e 的 x 次方（e≈2.718）
    - `log(double x)`：自然对数（lnx，x>0）
    - `log10(double x)`：常用对数（lgx，x>0）

4.  取整与最值运算
    - `floor(double x)`：向下取整（例：`floor(3.8)` → 3.0）
    - `ceil(double x)`：向上取整（例：`ceil(3.2)` → 4.0）
    - `round(double x)`：四舍五入取整（例：`round(3.5)` → 4.0）
    - `max(double a, double b)`：取两个数的最大值
    - `min(double a, double b)`：取两个数的最小值

### 二、关键使用注意事项
1.  参数与返回值：大部分函数参数和返回值均为 `double` 类型，传入 int 会自动转换。
2.  定义域限制：对数函数（log、log10）要求参数 x>0；tan(x) 在 x=π/2 + kπ 时无定义（会返回无穷大）。
3.  命名空间：函数默认在 `std` 命名空间，需加 `using namespace std;`，或显式写 `std::sqrt(4.0)`。
4.  精度问题：浮点数运算存在精度误差（例：`sqrt(2.0)` 结果接近 1.4142，非精确值）。