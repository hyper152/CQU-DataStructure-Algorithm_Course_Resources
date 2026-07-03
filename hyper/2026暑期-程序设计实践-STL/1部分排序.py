tmp = list(map(int, input().split()))
n = tmp[0]
r = tmp[1]
arr = tmp[2:2+n]  # 提取原始数据

if r + r >= n:
    # 无需排序，直接输出原序列
    print(' '.join(map(str, arr)))
else:
    # 提取中间部分进行排序
    mid = arr[r:n-r]
    mid.sort()
    # 重组：前r个 + 排序后的中间 + 后r个
    result = arr[:r] + mid + arr[n-r:]
    print(' '.join(map(str, result)))