`unordered_set` 是 C++ 标准库中的一个**无序集合**容器，它是用**哈希表**实现的，主要特点如下：

## 核心特点
- **元素唯一**：不允许重复元素
- **无序存储**：元素没有特定的顺序
- **O(1) 平均时间复杂度**：查找、插入、删除都很快

## 常用操作

```cpp
#include <unordered_set>
#include <iostream>
#include <string>
using namespace std;

int main() {
    // 创建
    unordered_set<string> follows;
    
    // 插入
    follows.insert("Alice");
    follows.insert("Bob");
    
    // 查找 - find() 返回迭代器，找不到返回 end()
    if (follows.find("Alice") != follows.end()) {
        cout << "找到了 Alice" << endl;
    }
    
    // 删除
    follows.erase("Bob");
    
    // 大小
    cout << follows.size() << endl;  // 输出 1
    
    // 遍历（顺序不可预测）
    for (const auto& name : follows) {
        cout << name << endl;
    }
    
    return 0;
}
```

## 与 set 的对比

| 特性 | `unordered_set` | `set` |
|------|-----------------|-------|
| 底层实现 | 哈希表 | 红黑树（平衡二叉树）|
| 元素顺序 | 无序 | 自动排序（升序）|
| 查找速度 | O(1) 平均 | O(log n) |
| 内存占用 | 较大 | 较小 |

## 在题目中的应用

```cpp
unordered_set<string> follows;  // 存储关注列表

// 检查某个用户是否在关注列表中 - O(1) 时间
if (follows.find(userId) == follows.end()) {
    // 不在关注列表中
}
```

**为什么用 `unordered_set` 而不是 `set`？**
- 我们只需要快速判断某个 ID 是否在关注列表中
- 不需要对关注列表进行排序
- O(1) 的查找速度比 O(log n) 更快