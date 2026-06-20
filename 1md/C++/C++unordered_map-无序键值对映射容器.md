`unordered_map` 是 C++ 标准库中的**无序键值对映射容器**，基于哈希表实现，提供平均 O(1) 的查找、插入、删除效率。

## 基本概念

```cpp
unordered_map<KeyType, ValueType> mapName;
// KeyType: 键的类型（必须可哈希）
// ValueType: 值的类型
```

每个元素是一个 `pair<const Key, Value>`，键唯一，值可重复。

## 常用操作示例

```cpp
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    // 1. 创建
    unordered_map<string, int> scoreMap;
    
    // 2. 插入 - 多种方式
    scoreMap["Alice"] = 95;           // 最常用
    scoreMap.insert({"Bob", 87});      // C++11
    scoreMap.insert(make_pair("Cathy", 92));
    scoreMap.emplace("David", 88);     // 原地构造，效率最高
    
    // 3. 访问
    cout << scoreMap["Alice"] << endl;  // 95
    // 注意：如果键不存在，[] 会创建新元素（值为默认值）
    
    // 安全访问
    if (scoreMap.find("Bob") != scoreMap.end()) {
        cout << scoreMap["Bob"] << endl;
    }
    
    // C++17 安全访问
    if (auto it = scoreMap.find("Eva"); it != scoreMap.end()) {
        cout << it->second << endl;
    }
    
    // 4. 修改
    scoreMap["Alice"] = 98;            // 直接赋值
    
    // 5. 删除
    scoreMap.erase("David");
    
    // 6. 遍历
    for (const auto& pair : scoreMap) {
        cout << pair.first << ": " << pair.second << endl;
    }
    
    // 结构化绑定 (C++17)
    for (const auto& [name, score] : scoreMap) {
        cout << name << ": " << score << endl;
    }
    
    // 7. 大小
    cout << "Size: " << scoreMap.size() << endl;
    cout << "Empty: " << scoreMap.empty() << endl;
    
    return 0;
}
```

## 常用成员函数

| 函数 | 说明 | 时间复杂度 |
|------|------|-----------|
| `insert({key, value})` | 插入键值对 | 平均 O(1) |
| `emplace(key, value)` | 原地构造插入 | 平均 O(1) |
| `erase(key)` | 删除指定键 | 平均 O(1) |
| `find(key)` | 查找，返回迭代器 | 平均 O(1) |
| `count(key)` | 返回键的数量（0或1）| 平均 O(1) |
| `contains(key)` | C++20，是否存在 | 平均 O(1) |
| `clear()` | 清空所有元素 | O(n) |
| `size()` | 返回元素个数 | O(1) |
| `empty()` | 是否为空 | O(1) |

## 高级用法示例

### 1. 词频统计（最常用）
```cpp
unordered_map<string, int> wordCount;
vector<string> words = {"apple", "banana", "apple", "orange", "banana", "apple"};

for (const auto& word : words) {
    wordCount[word]++;  // 不存在时自动初始化为0
}

for (const auto& [word, count] : wordCount) {
    cout << word << ": " << count << endl;
}
```

### 2. 缓存/记忆化
```cpp
unordered_map<int, long long> fibCache;

long long fibonacci(int n) {
    if (n <= 1) return n;
    
    // 先查缓存
    if (fibCache.find(n) != fibCache.end()) {
        return fibCache[n];
    }
    
    // 计算并存入缓存
    fibCache[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return fibCache[n];
}
```

### 3. 分组聚合
```cpp
// 按城市分组
struct Person {
    string name;
    string city;
    int age;
};

unordered_map<string, vector<Person>> cityGroups;

for (const auto& person : people) {
    cityGroups[person.city].push_back(person);
}
```

### 4. 值也是容器
```cpp
// 图的邻接表表示
unordered_map<int, vector<int>> graph;

graph[1].push_back(2);  // 节点1连接节点2
graph[1].push_back(3);
graph[2].push_back(4);
```

### 5. 自定义键类型
```cpp
struct Point {
    int x, y;
    
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

struct PointHash {
    size_t operator()(const Point& p) const {
        // 组合哈希
        return hash<int>()(p.x) ^ (hash<int>()(p.y) << 1);
    }
};

unordered_map<Point, string, PointHash> pointNames;
pointNames[{10, 20}] = "Home";
```

## 性能优化技巧

### 1. 预分配空间
```cpp
unordered_map<int, string> map;
map.reserve(10000);  // 预分配10000个桶，避免多次重新哈希
```

### 2. 设置负载因子
```cpp
unordered_map<int, string> map;
map.max_load_factor(0.75);  // 设置最大负载因子
```

### 3. 使用 emplace 代替 insert
```cpp
// 慢：先构造临时对象，再拷贝
map.insert({"key", "value"});

// 快：直接在容器内构造
map.emplace("key", "value");
```

### 4. 使用 try_emplace (C++17)
```cpp
// 仅当键不存在时才插入，避免不必要的构造
map.try_emplace("key", "value");
```

## 与其他容器的比较

| 容器 | 特点 | 适用场景 |
|------|------|---------|
| `unordered_map` | 无序，O(1) 查找 | 快速查找，不关心顺序 |
| `map` | 有序，O(log n) 查找 | 需要按序遍历，范围查询 |
| `vector<pair>` | 连续内存 | 元素少，需要顺序遍历 |

## 常见陷阱

### 1. [] 操作符的副作用
```cpp
unordered_map<string, int> map;
cout << map["Alice"] << endl;  // 创建了新元素 Alice:0！

// 应该用 find
if (map.find("Alice") != map.end()) {
    cout << map["Alice"] << endl;
}
```

### 2. 迭代器失效
```cpp
// 插入可能导致重新哈希，迭代器失效
for (auto it = map.begin(); it != map.end(); ++it) {
    if (someCondition) {
        map.insert(...);  // 危险！迭代器可能失效
    }
}
```

### 3. 键不能修改
```cpp
for (auto& pair : map) {
    pair.first = "newKey";  // 错误！键是const
}
```

## 在"悄悄关注"题中的应用

```cpp
// 可以存储每个用户的点赞数
unordered_map<string, int> likeCount;
likeCount["Magi"] = 50;
likeCount["Pota"] = 30;

// 或者存储关注列表，但本题只需判断存在性，用 set 更合适
unordered_set<string> follows;  // 就够了
```

`unordered_map` 是 C++ 中最常用的容器之一，掌握它可以大大提高代码效率和简洁性。