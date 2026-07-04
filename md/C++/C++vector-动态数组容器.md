# #include &lt;vector&gt; 核心知识点概括
## 一、vector 核心定义
#include &lt;vector&gt; 是 C++ 标准库中最常用的**动态数组容器**，属于序列式容器，支持动态调整大小，元素在内存中连续存储，兼具数组的高效访问和链表的动态扩容特性，是日常开发中替代原生数组的首选。

核心特点：内存连续、支持随机访问、动态扩容、元素默认初始化（基本类型为0，自定义类型调用默认构造函数）。

## 二、核心用法（基础操作）
### 1. 头文件与定义方式
必须包含头文件：`#include<vector>`；
常用定义格式（需结合 namespace std，或显式写 std::vector）：
- 基础定义：`vector<T> vec;`
- 初始化大小：`vector<T> vec(n);`
- 赋值初始化：`vector<T> vec(n, val);`
- 列表初始化：`vector<T> vec = {a1, a2, a3};`
- 拷贝初始化：`vector<T> vec2(vec1);`

### 2. 常用成员函数（高频操作）
| 成员函数       | 功能说明                                   | 示例                  |
|----------------|--------------------------------------------|-----------------------|
| push_back(val) | 在向量末尾插入元素 val，扩容时自动分配新内存 | vec.push_back(10);    |
| pop_back()     | 删除向量末尾元素，需确保向量非空            | vec.pop_back();       |
| size()         | 返回当前向量中元素的实际个数                | int len = vec.size(); |
| capacity()     | 返回当前向量的容量                         | int cap = vec.capacity(); |
| empty()        | 判断向量是否为空，返回 bool 值             | vec.empty();          |
| clear()        | 清空所有元素，size 变为 0，容量不变         | vec.clear();          |
| front()        | 获取第一个元素                             | vec.front();          |
| back()         | 获取最后一个元素                            | vec.back();           |

### 3. 遍历方式
- 下标遍历：`for(int i=0; i<vec.size(); i++) cout << vec[i];`
- 范围for：`for(auto x : vec) cout << x;`

---

## 三、多维 / 二维 vector 用法（重点）
### 1. 二维 vector 定义
```cpp
// 3行4列，初始值为0
vector<vector<int>> vec(3, vector<int>(4));

// 3行4列，全部初始化为5
vector<vector<int>> vec(3, vector<int>(4, 5));

// 直接初始化
vector<vector<int>> vec = {
    {1,2,3},
    {4,5,6},
    {7,8,9}
};
```

### 2. 访问元素（与二维数组一致）
```cpp
vec[i][j]   // 第i行第j列元素
```

### 3. 获取行列大小
```cpp
int row = vec.size();        // 行数
int col = vec[0].size();     // 列数
```

### 4. 二维 vector 遍历
```cpp
for(int i=0; i<vec.size(); i++){
    for(int j=0; j<vec[i].size(); j++){
        cout << vec[i][j] << " ";
    }
    cout << endl;
}
```

### 5. 动态添加行
```cpp
vector<int> row = {10,20,30};
vec.push_back(row);
```

---

## 四、三维 vector（扩展）
```cpp
// 2×3×4 三维数组
vector<vector<vector<int>>> vec(2, vector<vector<int>>(3, vector<int>(4)));
```
访问：`vec[i][j][k]`