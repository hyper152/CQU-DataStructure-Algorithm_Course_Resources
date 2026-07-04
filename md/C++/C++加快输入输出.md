## 简要说明

### `ios::sync_with_stdio(false)`
**关闭 C++ 和 C 的输入输出同步**
- 默认：`cin/cout` 和 `scanf/printf` 可以混用，但速度慢
- 设置后：`cin/cout` 速度变快（接近 `scanf/printf`），但**不能混用**
- 作用：提升 I/O 速度

### `cin.tie(nullptr)`
**解绑 `cin` 和 `cout`**
- 默认：`cin` 读取前会自动刷新 `cout` 缓冲区
- 设置后：取消自动刷新，减少不必要的刷新操作
- 作用：进一步提升性能

### 组合使用
```cpp
ios::sync_with_stdio(false);
cin.tie(nullptr);
```
**效果**：最大化 `cin/cout` 的速度，常用于算法竞赛

### 注意事项
- 设置后不能混用 `cin` 和 `scanf`
- 交互式程序可能需要手动刷新 `cout`
- 使用 `'\n'` 代替 `endl`（避免自动刷新）

### 简单记忆
- 有这两行：**快**，但只能用 `cin/cout`
- 没这两行：**慢**，但可以混用 I/O 函数