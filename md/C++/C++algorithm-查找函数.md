##  #include <algorithm>

### 核心函数

| 函数 | 功能 | 示例 (v=[1,3,5,7], x=5) |
|------|------|------------------------|
| **`lower_bound`** | 第一个 **>=** x | 返回指向 5 |
| **`upper_bound`** | 第一个 **>** x | 返回指向 7 |
| **`binary_search`** | 判断是否存在 | 返回 true |
| **`equal_range`** | 返回 [lower, upper) 区间 | 返回 (5, 7) |

### 快速示例
```cpp
vector<int> v = {1, 3, 5, 5, 7};

lower_bound(v.begin(), v.end(), 5);  // 指向第1个5
upper_bound(v.begin(), v.end(), 5);  // 指向7
binary_search(v.begin(), v.end(), 5); // true

auto range = equal_range(v.begin(), v.end(), 5);
// range.first = 第1个5, range.second = 7的位置
```

### 常见用途
- **插入位置**：`lower_bound` 找插入点保持有序
- **统计个数**：`upper_bound - lower_bound`
- **查找元素**：`binary_search`
- **LIS算法**：`lower_bound` 找替换位置

### 要求
- 区间**必须有序**
- 时间复杂度：**O(log n)**