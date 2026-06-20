import bisect

def find(n, arr, P):
    total = 0
    for i in range(n):
        a = arr[i]
        # 需要满足 |a - b| < P < a + b
        # 即：P - a < b < P + a 且 b > a - P
        
        # 下界：max(P - a, a - P) + 1，但要保证 b > |a - P|
        low_val=abs(a-P)
        low_val += 0.5  # 严格大于
        
        # 上界：P + a，但要 b < P + a
        high_val = P + a - 0.5  # 严格小于
        
        # 用二分查找找到数组中满足条件的b的范围
        left = bisect.bisect_right(arr, low_val)
        right = bisect.bisect_right(arr, high_val) - 1
        
        # 如果i在范围内，需要排除自己
        if left <= right:
            total += (right - left + 1)
            if left <= i <= right:
                total -= 1
    
    # 每对组合被计算了两次，除以2
    return total // 2

n, P = map(int, input().split())
arr = list(map(int, input().split()))
sorted_arr = sorted(arr)
print(find(n, sorted_arr, P))