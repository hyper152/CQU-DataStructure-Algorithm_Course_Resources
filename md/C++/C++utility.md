`<utility>` 是 C++ 标准库中的一个核心头文件，提供了许多**基础工具和通用组件**。虽然你在很多程序中可能没有显式包含它，但它包含的功能非常实用。

## 主要功能组件

### 1. **`pair` 和 `make_pair`**
最常用的功能，用于将两个值组合成一个单元。

```cpp
#include <utility>
#include <string>
#include <iostream>
using namespace std;

int main() {
    // 创建 pair
    pair<string, int> p1("Alice", 25);
    auto p2 = make_pair("Bob", 30);
    
    // 访问
    cout << p1.first << ": " << p1.second << endl;
    
    return 0;
}
```

### 2. **`swap` 函数**
高效交换两个对象的值（C++11 起支持移动语义）。

```cpp
#include <utility>
#include <vector>
#include <iostream>

int main() {
    // 交换基本类型
    int a = 10, b = 20;
    swap(a, b);
    cout << a << " " << b << endl;  // 20 10
    
    // 交换容器（高效，只交换内部指针）
    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {4, 5, 6, 7};
    swap(v1, v2);
    
    cout << "v1 size: " << v1.size() << endl;  // 4
    cout << "v2 size: " << v2.size() << endl;  // 3
    
    return 0;
}
```

### 3. **`move` 和 `forward`**
C++11 引入的关键函数，用于实现移动语义和完美转发。

```cpp
#include <utility>
#include <string>
#include <iostream>
#include <vector>

int main() {
    string s1 = "Hello";
    
    // move：将左值转换为右值引用，启用移动语义
    string s2 = move(s1);  // s1 的内容被"移动"到 s2，s1 变为空
    
    cout << "s1: '" << s1 << "'" << endl;  // s1: ''
    cout << "s2: '" << s2 << "'" << endl;  // s2: 'Hello'
    
    // 移动容器效率更高
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 = move(v1);  // O(1) 时间，只交换内部指针
    
    cout << "v1 size: " << v1.size() << endl;  // 0
    
    return 0;
}
```

### 4. **`exchange` 函数** (C++14)
替换旧值并返回旧值。

```cpp
#include <utility>
#include <iostream>

int main() {
    int value = 10;
    
    // 将 value 设置为 20，并返回旧值 10
    int old = exchange(value, 20);
    
    cout << "old: " << old << endl;      // 10
    cout << "value: " << value << endl;  // 20
    
    // 实际应用：在链表中更新头节点
    // old_head = exchange(head, new_node);
    
    return 0;
}
```

### 5. **`integer_sequence` 和相关工具** (C++14)
编译期整数序列，常用于模板元编程。

```cpp
#include <utility>
#include <iostream>
#include <tuple>

// 打印 tuple 的辅助函数
template<typename Tuple, size_t... Is>
void printTupleImpl(const Tuple& t, index_sequence<Is...>) {
    ((cout << get<Is>(t) << " "), ...);  // C++17 折叠表达式
}

template<typename... Args>
void printTuple(const tuple<Args...>& t) {
    printTupleImpl(t, index_sequence_for<Args...>{});
}

int main() {
    auto t = make_tuple(1, "hello", 3.14);
    printTuple(t);  // 输出: 1 hello 3.14
    
    return 0;
}
```

### 6. **`declval` 函数** (C++11)
在未求值上下文中获取类型的引用，用于模板元编程。

```cpp
#include <utility>
#include <iostream>

// 检测一个类型是否有 size() 成员函数
template<typename T>
class HasSize {
private:
    template<typename U>
    static auto test(int) -> decltype(declval<U>().size(), true_type());
    
    template<typename>
    static false_type test(...);
    
public:
    static constexpr bool value = decltype(test<T>(0))::value;
};

int main() {
    cout << HasSize<vector<int>>::value << endl;  // 1 (true)
    cout << HasSize<int>::value << endl;          // 0 (false)
    
    return 0;
}
```

### 7. **关系运算符的通用定义**
`<utility>` 为自定义类型提供了默认的比较运算符支持。

```cpp
#include <utility>
#include <iostream>

struct Point {
    int x, y;
    
    // C++20 之前需要手动定义所有运算符
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
    
    // 使用 std::rel_ops 自动生成其他运算符（已废弃，不推荐）
};

int main() {
    Point p1{1, 2};
    Point p2{1, 2};
    Point p3{3, 4};
    
    cout << (p1 == p2) << endl;  // 1
    
    return 0;
}
```

### 8. **`piecewise_construct` 等标签**
用于 `pair` 和 `map` 的原地构造。

```cpp
#include <utility>
#include <map>
#include <string>
#include <iostream>

int main() {
    map<string, pair<int, string>> m;
    
    // 使用 piecewise_construct 分段构造，避免临时对象
    m.emplace(
        piecewise_construct,
        forward_as_tuple("key"),
        forward_as_tuple(42, "value")
    );
    
    // 等价于，但更高效
    // m["key"] = {42, "value"};
    
    return 0;
}
```

### 9. **`as_const` 函数** (C++17)
返回对象的常量引用。

```cpp
#include <utility>
#include <vector>
#include <iostream>

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    
    // 确保使用 const 版本的 begin()
    for (auto it = as_const(v).begin(); it != as_const(v).end(); ++it) {
        cout << *it << " ";
        // *it = 10;  // 错误！const 迭代器不能修改
    }
    
    return 0;
}
```

## 为什么很多程序不显式包含 `<utility>`？

```cpp
#include <iostream>
#include <vector>
#include <map>
// 没有 #include <utility>，但仍能使用 pair, move 等
```

**原因**：许多其他标准库头文件内部已经包含了 `<utility>`：
- `<map>` → 使用 `pair`
- `<vector>` → 内部实现可能包含
- `<string>` → 可能包含用于移动语义
- `<algorithm>` → 使用 `swap`

## 最佳实践

尽管其他头文件可能间接包含 `<utility>`，**建议显式包含**：

```cpp
#include <utility>  // 👍 明确表达依赖

// 特别是在以下情况：
// 1. 直接使用 pair
// 2. 使用 move/forward
// 3. 使用 swap
// 4. 使用 exchange
```

这样代码的依赖关系更清晰，也避免某些编译器/标准库实现可能的不包含情况。

## 总结

`<utility>` 是一个轻量但强大的头文件，提供了：
- ✅ 基础工具：`pair`, `swap`
- ✅ 移动语义：`move`, `forward`
- ✅ 实用函数：`exchange`, `as_const`
- ✅ 模板元编程工具：`declval`, `integer_sequence`

虽然常常被间接包含，但显式包含它是良好的编程习惯。