n = int(input())
lst = [0] + list(map(int, input().split()))

for i in range(n, n - 3, -1):
    mx = lst[i]
    mxid = i
    for j in range(1, i + 1):
        if lst[j] > mx:
            mx = lst[j]
            mxid = j
    lst[i], lst[mxid] = lst[mxid], lst[i]
    print(' '.join(str(lst[k]) for k in range(1, n + 1)))
