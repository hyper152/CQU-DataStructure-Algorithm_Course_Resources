def find(arr, q):
    l = 0
    r = len(arr) - 1
    
    while l < r:
        m = (l + r) // 2
        if arr[m] >= q:
            r = m
        else:
            l = m + 1
    
    if arr[l] == q:
        return l + 1
    else:
        return -1

n, m = map(int, input().split())
arr = list(map(int, input().split()))
ipt = list(map(int, input().split()))

for i in range(m):
    q = ipt[i]
    t = find(arr, q)
    print(t, end=" ")
print()