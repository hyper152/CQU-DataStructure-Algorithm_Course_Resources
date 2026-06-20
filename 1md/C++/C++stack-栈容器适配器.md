这是 C++ 中的**栈容器适配器**，用于实现**后进先出（LIFO）**的数据结构，只允许在一端（栈顶）插入/删除。

### ✨ 核心用法
- **头文件**：`#include <stack>`
- **定义**：`stack<T> st;`（T 为数据类型）
- **常用操作**：
  - `push(x)`：入栈，将 x 压入栈顶
  - `pop()`：出栈，删除栈顶元素（无返回值）
  - `top()`：获取栈顶元素（不删除）
  - `empty()`：判断是否为空（空返回 true）
  - `size()`：返回栈中元素个数

### 📌 示例代码
```cpp
#include <stack>
using namespace std;

int main() {
    stack<int> st;
    st.push(1); st.push(2); st.push(3); // 栈：[1,2,3]（3 为栈顶）
    st.top(); // 输出 3 
    st.pop(); // 栈变为 [1,2]
    return 0;
}
```

### 🔍 补充说明
- 栈是**容器适配器**，底层默认用 deque 实现，也可指定 vector/list 作为底层容器（如 `stack<int, vector<int>>`）。
- 不支持遍历，没有迭代器，适合**括号匹配、函数调用栈、逆序输出**等场景。