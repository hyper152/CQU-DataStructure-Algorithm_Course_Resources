`<numeric>` 是 C++ 标准库中的一个头文件，提供了一组用于数值计算的算法。除了刚才介绍的 `accumulate`，它还包含其他有用的函数。

## 常用函数一览

### 1. **`accumulate`** - 累加/累乘

```cpp
#include <numeric>
#include <vector>
using namespace std;

vector<int> v = {1, 2, 3, 4, 5};

// 求和
int sum = accumulate(v.begin(), v.end(), 0);  // 15

// 求乘积
int product = accumulate(v.begin(), v.end(), 1, multiplies<int>());  // 120
```

---

### 2. **`partial_sum`** - 部分和（前缀和）

计算序列的前缀和，结果存储到另一个容器。

```cpp
vector<int> v = {1, 2, 3, 4, 5};
vector<int> result(5);

partial_sum(v.begin(), v.end(), result.begin());
// result = {1, 3, 6, 10, 15}

// 也可以自定义运算，比如求部分积
partial_sum(v.begin(), v.end(), result.begin(), multiplies<int>());
// result = {1, 2, 6, 24, 120}
```

---

### 3. **`adjacent_difference`** - 相邻差

计算相邻元素的差值（后一个减前一个）。

```cpp
vector<int> v = {1, 3, 6, 10, 15};
vector<int> diff(5);

adjacent_difference(v.begin(), v.end(), diff.begin());
// diff = {1, 2, 3, 4, 5}
//        第一个元素保持不变
```

---

### 4. **`inner_product`** - 内积（点积）

计算两个序列的内积。

```cpp
vector<int> a = {1, 2, 3};
vector<int> b = {4, 5, 6};

int result = inner_product(a.begin(), a.end(), b.begin(), 0);
// result = 1*4 + 2*5 + 3*6 = 4 + 10 + 18 = 32
```

带自定义运算的版本：

```cpp
// 计算 a[0]*b[0] + a[1]*b[1] + ...
// 但把 + 换成 -，* 换成 +
int result = inner_product(a.begin(), a.end(), b.begin(), 0,
                           minus<int>(),   // 替换加法
                           plus<int>());   // 替换乘法
// result = 0 - (1+4) - (2+5) - (3+6) = -21
```

---

### 5. **`iota`** (C++11) - 递增赋值

用连续递增的值填充容器。

```cpp
vector<int> v(10);
iota(v.begin(), v.end(), 0);   // 从0开始递增
// v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}

vector<char> letters(26);
iota(letters.begin(), letters.end(), 'a');  // 从'a'开始
// letters = {'a', 'b', 'c', ..., 'z'}
```

---

### 6. **`gcd`** 和 **`lcm`** (C++17)

最大公约数和最小公倍数。

```cpp
#include <numeric>

int g = gcd(12, 18);   // 6
int l = lcm(12, 18);   // 36
```

---

### 7. **`midpoint`** (C++20)

计算两个数的中点（防止溢出）。

```cpp
int m = midpoint(10, 20);           // 15
int m2 = midpoint(INT_MAX-1, INT_MAX);  // 安全计算，不会溢出
```

---

### 8. **`reduce`** (C++17) - 并行累加

类似 `accumulate`，但支持并行执行，且不保证计算顺序。

```cpp
#include <execution>  // 需要支持并行的编译器

vector<int> v = {1, 2, 3, 4, 5};
int sum = reduce(execution::par, v.begin(), v.end(), 0);
// 可能利用多核并行计算
```

---

## 实际应用示例

### 计算数组的前缀和（竞赛常用）

```cpp
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    vector<int> arr = {3, 1, 4, 1, 5, 9};
    vector<int> prefix(arr.size());
    
    partial_sum(arr.begin(), arr.end(), prefix.begin());
    
    // 快速求区间 [2, 4] 的和
    int sum_2_4 = prefix[4] - prefix[1];  // 4+1+5 = 10
    
    return 0;
}
```

### 生成测试数据

```cpp
#include <numeric>
#include <vector>

vector<int> test_data(1000000);
iota(test_data.begin(), test_data.end(), 1);  // 1, 2, 3, ..., 1000000
```

---

## 总结

| 函数 | 功能 | C++ 版本 |
|------|------|----------|
| `accumulate` | 累加/累乘 | C++98 |
| `partial_sum` | 前缀和 | C++98 |
| `adjacent_difference` | 相邻差 | C++98 |
| `inner_product` | 内积 | C++98 |
| `iota` | 递增赋值 | C++11 |
| `gcd` / `lcm` | 公约数/公倍数 | C++17 |
| `reduce` | 并行累加 | C++17 |
| `midpoint` | 中点 | C++20 |

`<numeric>` 虽然不如 `<algorithm>` 常用，但在数值计算场景下非常实用。