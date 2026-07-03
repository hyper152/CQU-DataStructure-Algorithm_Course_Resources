#若一个线性表L采用顺序存储结构存储，其中所有的元素为整数。设计一个算法，求元素值在[x,y]之间的所有元素之和。


n = int(input())
nums = list(map(int, input().split()))
x, y = map(int, input().split())
total = 0
for num in nums:
    if x <= num <= y:
        total += num
print(total)