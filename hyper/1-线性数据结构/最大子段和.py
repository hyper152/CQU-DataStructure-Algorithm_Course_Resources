#给定n个整数（可能为负数）组成的序列a[1],a[2],a[3],…,a[n]，求该序列如a[i]+a[i+1]+…+a[j]的子段和的最大值。当所给的整数均为负数时，定义子段和为0。

#要求算法的时间复杂度为O(n)。

n = int(input())
nums = list(map(int, input().split()))
current_sum = 0
max_sum = 0

for num in nums:
    current_sum = max(0, current_sum + num)
    max_sum = max(max_sum, current_sum)

print(max_sum)