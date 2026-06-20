# bisect — 二分查找

`bisect` 模块提供对有序列表的二分查找，时间复杂度 O(log N)。

## 核心函数

| 函数 | 作用 |
|------|------|
| `bisect_left(a, x, lo=0, hi=len(a))` | 返回将 x 插入 a 的**最左**索引（保持有序），若 x 已存在则插到左边 |
| `bisect_right(a, x, lo=0, hi=len(a))` | 返回将 x 插入 a 的**最右**索引（保持有序），若 x 已存在则插到右边 |
| `bisect(a, x, ...)` | `bisect_right` 的别名 |

## 关键区别：`bisect_left` vs `bisect_right`

对于已排序列表 `a = [1, 3, 3, 3, 5]`：

| 操作 | 结果 | 说明 |
|------|------|------|
| `bisect_left(a, 3)` | `1` | 第一个 3 的位置（左边界） |
| `bisect_right(a, 3)` | `4` | 最后一个 3 之后的位置（右边界） |
| `bisect_left(a, 4)` | `4` | 4 不存在，应插入 5 的位置 |
| `bisect_right(a, 4)` | `4` | 同上（不存在时两者结果相同） |

**记忆方式**：`left` 找左边界（第一个 >= x 的索引），`right` 找右边界（第一个 > x 的索引）。

## 常用场景

### 1. 查找区间 [l, r) 内的元素个数

```python
left = bisect_left(a, l)
right = bisect_left(a, r)   # 或 bisect_right(a, l) 视区间开闭而定
count = right - left
```

### 2. 自定义 key（Python 3.10+）

```python
data = [("apple", 3), ("banana", 1), ("cherry", 2)]
data.sort(key=lambda x: x[1])
idx = bisect_left(data, 2, key=lambda x: x[1])
# idx -> 1（对应 ("cherry", 2)）
```

### 3. 检查元素是否存在

```python
def exists(a, x):
    i = bisect_left(a, x)
    return i < len(a) and a[i] == x
```

## 与 `index()` 对比

```python
a = [1, 3, 3, 3, 5]

bisect_left(a, 3)  # 1 — O(log N)
a.index(3)         # 1 — O(N)，找不到抛 ValueError
```

- `index()`：找不到抛异常，O(N)
- `bisect_left()`：找不到返回插入位置（不会抛异常），O(log N)

## 竞赛技巧

- **最长递增子序列 (LIS)**：维护单调数组，对每个 x 用 `bisect_left` 替换第一个 >= x 的元素
- **按分数查排名**：`bisect_right(sorted_scores, score)` 可算排名（比该分数高的人数）
- **前缀和 + 二分**：求累积和数组后用 `bisect_left` 找第一个 >= target 的位置
