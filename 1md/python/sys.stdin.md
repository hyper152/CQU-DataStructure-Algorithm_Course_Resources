`sys.stdin` 是 Python 中处理**标准输入**的一个文件对象，常用来读取多行输入，特别适合处理“数据有多组，处理到文件尾”这类题目。

---

## 1. 基本用法

```python
import sys

for line in sys.stdin:
    line = line.strip()  # 去掉行末的换行符和首尾空白
    if not line:
        continue         # 跳过空行
    # 处理这一行数据
    print(line)
```

- `sys.stdin` 是一个可迭代对象，每次迭代读取一行
- 按 `Ctrl+D`（Linux/Mac）或 `Ctrl+Z`（Windows）表示输入结束（EOF）

---

## 2. 与 `input()` 的区别

| 特性 | `sys.stdin` | `input()` |
|------|-------------|-----------|
| 读取方式 | 逐行迭代，或调用 `.read()` 全部读取 | 每次读一行 |
| 遇到 EOF | 自动结束循环 | 抛出 `EOFError` 异常 |
| 适用场景 | 处理大量输入，效率更高 | 交互式输入 |

---

## 3. 常见用法示例

### 逐行处理
```python
import sys

for line in sys.stdin:
    data = line.strip()
    # 处理 data
```

### 一次性读取所有内容
```python
import sys

content = sys.stdin.read()  # 读取全部输入
lines = content.splitlines()  # 按行分割
```

### 读取所有行到列表
```python
import sys

lines = sys.stdin.readlines()  # 每行作为一个元素存入列表
```

---

## 4. 在你的题目中的应用

题目要求“测试数据有多组，处理到文件尾”，所以用：

```python
import sys

for line in sys.stdin:
    pre_str = line.strip()
    if not pre_str:
        continue
    # 处理这一组数据
    root, _ = build_tree(pre_str, 0)
    if is_bst(root):
        print("YES")
    else:
        print("NO")
```

这样无论输入多少组数据，都能自动逐组处理，直到 EOF