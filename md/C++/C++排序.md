
统一用数组：`arr = [8, 3, 2, 7, 4]` 做演示。

---

# 1. 冒泡排序
```cpp
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}
```

**步骤说明：**
1. 从第一个数开始，**相邻两个数比较**，大的往后挪。
2. 每一轮都会把**当前最大的数“冒”到最后**。
3. 重复直到没有交换发生。

**演示 [8,3,2,7,4]：**
- 第1轮：3 2 7 4 **8**
- 第2轮：2 3 4 **7 8**
- 第3轮：2 3 **4 7 8**
- 第4轮：无交换，结束
结果：`[2,3,4,7,8]`

---

# 2. 选择排序
```cpp
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    }
}
```

**步骤说明：**
1. 每一轮在**未排序区间找最小值**。
2. 把最小值和**未排序区间第一个位置**交换。
3. 缩小未排序区间，重复。

**演示 [8,3,2,7,4]：**
- i=0：找最小 2，交换 → **2**,3,8,7,4
- i=1：找最小 3，不动 → 2,**3**,8,7,4
- i=2：找最小 4，交换 → 2,3,**4**,7,8
- i=3：找最小 7，不动
结果：`[2,3,4,7,8]`

---

# 3. 插入排序
```cpp
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
```

**步骤说明：**
1. 把数组看成**左边已排序，右边未排序**。
2. 取当前数，**向前插入到合适位置**。
3. 比它大的数依次后移。

**演示 [8,3,2,7,4]：**
- i=1(3)：8后移 → [3,8,2,7,4]
- i=2(2)：8、3后移 → [2,3,8,7,4]
- i=3(7)：8后移 → [2,3,7,8,4]
- i=4(4)：8、7后移 → [2,3,4,7,8]

---

# 4. 希尔排序
```cpp
void shellSort(vector<int>& arr) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}
```

**步骤说明：**
1. 按**增量 gap**分组，每组做插入排序。
2. gap 不断减半，直到 gap=1 变成普通插入排序。
3. 宏观调整 + 微调，比直接插入快很多。

**演示 [8,3,2,7,4]：**
- n=5，初始 gap=2
- 分组：(8,2,4)、(3,7)
- 组内排序后：2,3,4,7,8
- gap=1，普通插入排序，结束

---

# 5. 归并排序
```cpp
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i) L[i] = arr[left + i];
    for (int i = 0; i < n2; ++i) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
```

**步骤说明（分治法）：**
1. **拆分**：把数组从中间分成左右两半。
2. **递归排序**左右两半。
3. **合并**：把两个有序数组合成一个有序数组。

**演示 [8,3,2,7,4]：**
拆分：
[8,3,2,7,4] → [8,3] 和 [2,7,4]
→ 继续拆到单个数字
合并：
[3,8] + [2,4,7] → 依次取小的拼接
→ `[2,3,4,7,8]`

---

# 6. 快速排序
```cpp
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
```

**步骤说明：**
1. 选一个**基准数 pivot**（这里选最后一个）。
2. 分区：**小于基准放左边，大于放右边**。
3. 递归排序左右两部分。

**演示 [8,3,2,7,4]：**
- pivot=4
- 小于4的：3,2；大于4的：8,7
- 分区后：[2,3,4,7,8]
- 左右再递归，已有序，结束

---

# 7. 堆排序
```cpp
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
```

**步骤说明：**
1. 把数组建成**大顶堆**（堆顶最大）。
2. 把堆顶和**最后一位交换**，最大值就位。
3. 排除最后一位，重新调整堆，重复。

**演示 [8,3,2,7,4]：**
- 建堆后堆顶是8
- 交换8和4 → [...,8]
- 调整堆顶为7，交换7和倒数第二
- 依次得到：`[2,3,4,7,8]`

---

# 8. 计数排序
```cpp
void countingSort(vector<int>& arr) {
    int maxVal = *max_element(arr.begin(), arr.end());
    int minVal = *min_element(arr.begin(), arr.end());
    int range = maxVal - minVal + 1;
    vector<int> count(range, 0), res(arr.size());

    for (int x : arr) count[x - minVal]++;
    for (int i = 1; i < range; ++i) count[i] += count[i - 1];

    for (int i = arr.size() - 1; i >= 0; --i) {
        res[count[arr[i] - minVal] - 1] = arr[i];
        count[arr[i] - minVal]--;
    }
    arr = res;
}
```

**步骤说明：**
1. 统计每个数字出现次数。
2. 计算前缀和，确定每个数的位置。
3. 反向填充保证稳定。

**演示 [8,3,2,7,4]：**
数范围：2~8
计数：2:1,3:1,4:1,7:1,8:1
按计数直接输出：`[2,3,4,7,8]`

---

# 9. 桶排序
```cpp
void bucketSort(vector<int>& arr) {
    int n = arr.size();
    int maxVal = *max_element(arr.begin(), arr.end());
    int minVal = *min_element(arr.begin(), arr.end());
    int bucketNum = (maxVal - minVal) / n + 1;
    vector<vector<int>> buckets(bucketNum);

    for (int x : arr)
        buckets[(x - minVal) / n].push_back(x);

    int idx = 0;
    for (auto& b : buckets) {
        sort(b.begin(), b.end());
        for (int x : b)
            arr[idx++] = x;
    }
}
```

**步骤说明：**
1. 按数值范围分到若干**桶**里。
2. 每个桶内部排序。
3. 按桶顺序合并。

**演示 [8,3,2,7,4]：**
分到对应桶 → 桶内排序 → 拼接
结果：`[2,3,4,7,8]`

---

# 10. 基数排序
```cpp
void radixCountSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> res(n);
    int count[10] = {0};

    for (int x : arr) count[(x / exp) % 10]++;
    for (int i = 1; i < 10; ++i) count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; --i) {
        res[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    arr = res;
}

void radixSort(vector<int>& arr) {
    int maxVal = *max_element(arr.begin(), arr.end());
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        radixCountSort(arr, exp);
}
```

**步骤说明：**
1. 从**个位 → 十位 → 百位**依次排序。
2. 每一位都用**计数排序**。
3. 多轮后整体有序。

**演示 [8,3,2,7,4]：**
只有个位数，一轮排序就完成：
`[2,3,4,7,8]`

---
