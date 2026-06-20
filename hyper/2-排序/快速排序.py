def partition(a, l, r):
    """
    序列拆分函数，按轴点划分序列并返回轴点最终位置
    :param a: 待拆分的序列（列表）
    :param l: 序列左端点下标
    :param r: 序列右端点下标
    :return: 轴点在序列中的最终位置
    """
    i = l  # 左指针初始化为左端点
    j = r - 1  # 右指针初始化为右端点前一位
    pivot = a[r]  # 选择序列最后一个元素作为轴点
    print(f"\nPartition: 序列{a[l:r+1]}, 左指针i={i}, 右指针j={j}, 轴点pivot={pivot}")
    
    while True:
        # 左指针右移，找到第一个大于等于轴点的元素
        while a[i] < pivot:
            i += 1
            print(f"i右移至{i} (a[{i}]={a[i]} >= {pivot})")
        # 右指针左移，找到第一个小于等于轴点且j>l的元素
        while a[j] > pivot and j > l:
            j -= 1
            print(f"j左移至{j} (a[{j}]={a[j]} <= {pivot})")
        
        # 指针相遇或交叉，拆分完成
        if i >= j:
            print(f"i={i} >= j={j}，退出循环")
            break
        
        # 交换i和j指向的元素，继续遍历
        a[i], a[j] = a[j], a[i]
        print(f"交换a[{i}]={a[j]}和a[{j}]={a[i]}，序列变为{a}")
        i += 1
        j -= 1
        print(f"i右移至{i}，j左移至{j}")
    
    # 将轴点交换到最终位置
    a[i], a[r] = a[r], a[i]
    print(f"轴点{pivot}归位至位置{i}，拆分后序列{a}")
    return i

def quick_sort(a, l, r):
    """
    快速排序递归函数
    :param a: 待排序序列（列表）
    :param l: 序列左端点下标
    :param r: 序列右端点下标
    """
    if l < r:
        print(f"\nQuickSort: 排序子序列{a[l:r+1]} (l={l}, r={r})")
        # 拆分序列，获取轴点位置
        pivot_pos = partition(a, l, r)
        # 递归排序左子序列
        quick_sort(a, l, pivot_pos - 1)
        # 递归排序右子序列
        quick_sort(a, pivot_pos + 1, r)

# 测试示例
if __name__ == "__main__":
    arr = [5, 3, 8, 6, 2, 9, 1, 7, 4]
    print("初始序列:", arr)
    quick_sort(arr, 0, len(arr) - 1)
    print("\n最终排序结果:", arr)