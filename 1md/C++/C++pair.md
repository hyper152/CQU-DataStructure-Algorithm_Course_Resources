`pair` 是 C++ 中将两个值绑定在一起的简单容器，非常实用。下面详细介绍其用法：

## 一、基本用法

### 1. 创建和初始化
```cpp
#include <utility>  // pair 定义在此
#include <string>
#include <iostream>
using namespace std;

int main() {
    // 方式1：直接构造
    pair<string, int> p1("Alice", 95);
    
    // 方式2：使用 make_pair（最常用，自动推导类型）
    auto p2 = make_pair("Bob", 87);
    
    // 方式3：列表初始化（C++11）
    pair<string, int> p3{"Cathy", 92};
    
    // 方式4：显式指定类型
    pair<string, int> p4 = pair<string, int>("David", 88);
    
    // 访问元素
    cout << p1.first << ": " << p1.second << endl;  // Alice: 95
    
    return 0;
}
```

### 2. 修改元素
```cpp
pair<string, int> p("Alice", 95);

// 修改
p.first = "Alicia";
p.second = 98;

// 使用 get 访问（C++11）
get<0>(p) = "Alex";   // 修改 first
get<1>(p) = 100;      // 修改 second
```

## 二、常用场景

### 1. 函数返回多个值
```cpp
// 返回成绩的最高分和最低分
pair<int, int> getMinMax(const vector<int>& scores) {
    if (scores.empty()) return {0, 0};
    
    int minScore = scores[0];
    int maxScore = scores[0];
    
    for (int score : scores) {
        if (score < minScore) minScore = score;
        if (score > maxScore) maxScore = score;
    }
    
    return {minScore, maxScore};  // 返回 pair
}

int main() {
    vector<int> scores = {85, 92, 78, 95, 88};
    
    auto result = getMinMax(scores);
    cout << "最低分: " << result.first << endl;
    cout << "最高分: " << result.second << endl;
    
    return 0;
}
```

### 2. 存储键值对（map 的元素）
```cpp
#include <map>

map<string, int> studentScores;

// 插入 pair
studentScores.insert(make_pair("Alice", 95));
studentScores.insert({"Bob", 87});  // C++11

// 遍历 map（每个元素都是 pair）
for (const pair<const string, int>& p : studentScores) {
    cout << p.first << ": " << p.second << endl;
}

// C++17 结构化绑定
for (const auto& [name, score] : studentScores) {
    cout << name << ": " << score << endl;
}
```

### 3. 存储二维坐标
```cpp
#include <vector>
#include <cmath>

// 存储多个点
vector<pair<int, int>> points = {
    {0, 0},
    {3, 4},
    {6, 8},
    {1, 1}
};

// 计算两点距离
double distance(pair<int, int> p1, pair<int, int> p2) {
    int dx = p1.first - p2.first;
    int dy = p1.second - p2.second;
    return sqrt(dx * dx + dy * dy);
}

// 使用
double dist = distance(points[0], points[1]);
cout << "距离: " << dist << endl;  // 5
```

### 4. 优先级队列
```cpp
#include <queue>

// 优先队列默认按 first 降序
priority_queue<pair<int, string>> pq;

pq.push({3, "Task C"});  // 优先级 3
pq.push({1, "Task A"});  // 优先级 1（最高）
pq.push({2, "Task B"});  // 优先级 2

while (!pq.empty()) {
    auto [priority, task] = pq.top();
    pq.pop();
    cout << priority << ": " << task << endl;
}
// 输出：1: Task A, 2: Task B, 3: Task C
```

### 5. 存储带权重的数据
```cpp
// 存储物品及其价值
vector<pair<string, double>> items = {
    {"apple", 3.5},
    {"banana", 2.8},
    {"orange", 4.2}
};

// 按价值排序
sort(items.begin(), items.end(), 
     [](const auto& a, const auto& b) {
         return a.second < b.second;  // 按价格升序
     });
```

## 三、高级用法

### 1. 结构化绑定（C++17）
```cpp
pair<string, int> getPerson() {
    return {"Alice", 25};
}

int main() {
    // 传统方式
    auto p = getPerson();
    string name = p.first;
    int age = p.second;
    
    // C++17 结构化绑定
    auto [name2, age2] = getPerson();
    cout << name2 << " is " << age2 << " years old." << endl;
    
    // 在循环中使用
    vector<pair<string, int>> data = {{"A", 1}, {"B", 2}};
    for (const auto& [key, value] : data) {
        cout << key << ": " << value << endl;
    }
    
    return 0;
}
```

### 2. 嵌套 pair
```cpp
// 表示三维坐标
pair<int, pair<int, int>> point3D = {10, {20, 30}};

// 访问
cout << "x: " << point3D.first << endl;           // 10
cout << "y: " << point3D.second.first << endl;    // 20
cout << "z: " << point3D.second.second << endl;   // 30

// 使用结构化绑定解包
auto [x, yz] = point3D;
auto [y, z] = yz;
cout << "Point: (" << x << ", " << y << ", " << z << ")" << endl;
```

### 3. pair 的比较
```cpp
pair<int, string> p1{1, "apple"};
pair<int, string> p2{1, "banana"};
pair<int, string> p3{2, "apple"};

// 先比较 first，相等则比较 second
cout << (p1 < p2) << endl;  // true（1==1，"apple"<"banana"）
cout << (p1 < p3) << endl;  // true（1 < 2）
cout << (p2 == p3) << endl; // false（first 不同）

// 所有比较运算符都支持：==, !=, <, <=, >, >=
```

### 4. 自定义排序
```cpp
vector<pair<string, int>> students = {
    {"Alice", 95},
    {"Bob", 87},
    {"Charlie", 92}
};

// 按分数降序排序
sort(students.begin(), students.end(),
     [](const auto& a, const auto& b) {
         return a.second > b.second;
     });

// 先按分数，分数相同按名字排序
sort(students.begin(), students.end(),
     [](const auto& a, const auto& b) {
         if (a.second != b.second) {
             return a.second > b.second;  // 分数降序
         }
         return a.first < b.first;  // 名字升序
     });
```

### 5. tie 解包（传统方式）
```cpp
pair<int, string> p = {25, "Alice"};

// 使用 tie 解包
int age;
string name;
tie(age, name) = p;

cout << name << " is " << age << " years old." << endl;

// 忽略某些值（使用 ignore）
tie(age, ignore) = p;  // 只要年龄
```

## 四、实际应用示例

### 示例1：统计词频并排序
```cpp
#include <unordered_map>
#include <algorithm>

vector<pair<string, int>> getTopWords(const vector<string>& words, int k) {
    // 统计词频
    unordered_map<string, int> freq;
    for (const auto& word : words) {
        freq[word]++;
    }
    
    // 转为 pair 的 vector
    vector<pair<string, int>> freqVec(freq.begin(), freq.end());
    
    // 按频率降序排序
    sort(freqVec.begin(), freqVec.end(),
         [](const auto& a, const auto& b) {
             return a.second > b.second;
         });
    
    // 返回前 k 个
    if (freqVec.size() > k) {
        freqVec.resize(k);
    }
    
    return freqVec;
}
```

### 示例2：区间合并
```cpp
// 合并重叠区间
vector<pair<int, int>> mergeIntervals(vector<pair<int, int>>& intervals) {
    if (intervals.empty()) return {};
    
    // 按起始位置排序
    sort(intervals.begin(), intervals.end());
    
    vector<pair<int, int>> merged;
    merged.push_back(intervals[0]);
    
    for (int i = 1; i < intervals.size(); i++) {
        auto& last = merged.back();
        auto& curr = intervals[i];
        
        if (curr.first <= last.second) {
            // 有重叠，合并
            last.second = max(last.second, curr.second);
        } else {
            // 无重叠，添加新区间
            merged.push_back(curr);
        }
    }
    
    return merged;
}
```

### 示例3：带索引的排序
```cpp
// 排序后保留原始索引
vector<int> arr = {5, 2, 8, 1, 9};
vector<pair<int, int>> indexed;  // {value, index}

for (int i = 0; i < arr.size(); i++) {
    indexed.push_back({arr[i], i});
}

// 按值排序
sort(indexed.begin(), indexed.end());

// 输出排序后的值和原索引
for (const auto& [value, index] : indexed) {
    cout << "Value: " << value << ", Original Index: " << index << endl;
}
```

## 五、注意事项

### 1. pair 的局限性
```cpp
// pair 只能存两个值，需要三个或以上时考虑：
// - 嵌套 pair（可读性差）
// - 自定义 struct（推荐）
// - tuple（C++11）

// 推荐：定义结构体
struct Student {
    string name;
    int age;
    double score;
};
```

### 2. 性能考虑
```cpp
// 作为参数传递时，考虑使用引用
void process(const pair<string, int>& p) {  // 避免拷贝
    cout << p.first << ": " << p.second << endl;
}

// 返回时可以使用移动语义
pair<vector<int>, int> createData() {
    vector<int> v = {1, 2, 3};
    return {move(v), 42};  // 移动而非拷贝
}
```

### 3. 与 map 的关系
```cpp
// map 的 value_type 是 pair<const Key, T>
map<string, int> m;
m["Alice"] = 95;

// 注意：key 是 const
map<string, int>::value_type p = *m.begin();  // pair<const string, int>
// p.first = "Bob";  // 错误！key 是 const
```

`pair` 虽然简单，但在很多场景下非常实用，特别是需要临时组合两个相关数据时。