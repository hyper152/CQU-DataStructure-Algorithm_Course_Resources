# heapq — 堆（优先队列）

`heapq` 基于**最小堆**（min-heap），Python 没有单独的最大堆实现，通过取负模拟。

底层用列表存储，`heap[0]` 始终是最小元素。

## 核心函数

| 函数 | 作用 | 复杂度 |
|------|------|--------|
| `heappush(heap, x)` | 将 x 压入堆 | O(log N) |
| `heappop(heap)` | 弹出并返回最小元素 | O(log N) |
| `heappushpop(heap, x)` | 先 push x 再 pop 最小，等价于 `push`+`pop` 但更高效 | O(log N) |
| `heapreplace(heap, x)` | 先 pop 最小再 push x，比 `pop`+`push` 更高效 | O(log N) |
| `heapify(xs)` | 将普通列表原地转为堆 | O(N) |
| `nlargest(n, iter, key=None)` | 返回前 n 个最大元素 | O(N log N) |
| `nsmallest(n, iter, key=None)` | 返回前 n 个最小元素 | O(N log N) |

### `heappushpop` vs `heapreplace` 的区别

```python
heap = [1, 5, 9]
heappushpop(heap, 2)  # push 2 然后 pop 最小 → 返回 1，堆为 [2, 5, 9]
heapreplace(heap, 2)  # pop 最小然后 push 2 → 返回 1，堆为 [2, 5, 9]

# 区别在于 heap 为空时：
# heapreplace([], 2)  → IndexError
# heappushpop([], 2)  → IndexError（也是，当堆为空时都要先有元素）
# 实际区别：当新元素比堆顶小时：
heap = [3, 5, 9]
heappushpop(heap, 1)  # 1 < 3，返回 1，堆不变 [3, 5, 9]（push 的 1 直接被 pop 了）
heapreplace(heap, 1)  # 1 < 3，返回 3，堆变为 [1, 5, 9]（先 pop 3 再 push 1）
```

核心区别：
- `heapreplace`：**先 pop 再 push**，返回旧的最小值
- `heappushpop`：**先 push 再 pop**，返回 push 后堆中的最小值（即取 push 和原堆顶中较小的那个）

## 常用场景

### 1. 最大堆（取负模拟）

```python
import heapq

max_heap = []
heappush(max_heap, -x)   # 存负值
max_val = -heappop(max_heap)  # 取负还原
```

### 2. Top-K 问题（前 K 个最大/最小元素）

```python
# 前 K 个最小元素 — 维护大小为 K 的最大堆
def top_k_smallest(nums, k):
    heap = []
    for x in nums:
        heappush(heap, -x)   # 最大堆
        if len(heap) > k:
            heappop(heap)    # 弹出最大的，保留最小的 K 个
    return [-x for x in heap]

# 或用 nlargest/nsmallest 一行搞定
nsmallest(k, nums)
nlargest(k, nums)
```

### 3. 合并多个有序序列

```python
def merge_sorted(*iterables):
    heap = []
    for i, it in enumerate(iterables):
        it = iter(it)
        try:
            heappush(heap, (next(it), i, it))
        except StopIteration:
            pass
    while heap:
        val, i, it = heappop(heap)
        yield val
        try:
            heappush(heap, (next(it), i, it))
        except StopIteration:
            pass
```

Python 3.5+ 直接有 `heapq.merge(*iterables)`。

### 4. Dijkstra 最短路径

```python
import heapq

def dijkstra(graph, start):
    dist = {node: float('inf') for node in graph}
    dist[start] = 0
    pq = [(0, start)]

    while pq:
        d, u = heappop(pq)
        if d > dist[u]:
            continue
        for v, w in graph[u]:
            nd = d + w
            if nd < dist[v]:
                dist[v] = nd
                heappush(pq, (nd, v))
    return dist
```

### 5. 动态中位数

```python
class MedianFinder:
    def __init__(self):
        self.left = []   # 最大堆（存较小的一半）
        self.right = []  # 最小堆（存较大的一半）

    def add_num(self, x):
        if not self.left or x <= -self.left[0]:
            heappush(self.left, -x)
        else:
            heappush(self.right, x)
        # 平衡两个堆的大小
        if len(self.left) > len(self.right) + 1:
            heappush(self.right, -heappop(self.left))
        elif len(self.right) > len(self.left):
            heappush(self.left, -heappop(self.right))

    def find_median(self):
        if len(self.left) > len(self.right):
            return -self.left[0]
        return (-self.left[0] + self.right[0]) / 2
```

### 6. 多路归并 + 懒惰删除（Lazy Deletion）

当需要从堆中删除任意元素时，标记删除而非直接移除：

```python
class LazyHeap:
    def __init__(self):
        self.heap = []
        self.deleted = {}  # 元素 -> 待删除次数

    def push(self, x):
        heappush(self.heap, x)

    def remove(self, x):
        self.deleted[x] = self.deleted.get(x, 0) + 1

    def pop(self):
        while self.heap:
            x = heappop(self.heap)
            if x in self.deleted:
                self.deleted[x] -= 1
                if self.deleted[x] == 0:
                    del self.deleted[x]
                continue
            return x
        raise IndexError("heap empty")
```

## 注意事项

- `heapq` **不是稳定排序**，相同优先级的元素顺序不确定
- 元组作为元素时按**字典序**比较：`(priority, value)`，优先级相同再比 value
- 自定义对象的堆需要类实现 `__lt__`，或将 (priority, object) 元组入堆
- **线程不安全**，多线程需加锁

## 复杂度汇总

| 操作 | 复杂度 |
|------|--------|
| `heappush` | O(log N) |
| `heappop` | O(log N) |
| `heapify` | O(N) |
| `nlargest` / `nsmallest` | O(N log N) |
| 朴素 `sorted` 取 Top-K | O(N log N) |

在只需要部分有序（Top-K）的场景，堆比全排序更省时间。
