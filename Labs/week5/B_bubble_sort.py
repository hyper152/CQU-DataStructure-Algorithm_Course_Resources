n = int(input())
lst = [0] + list(map(int, input().split()))

for i in range(1, 4):
    for j in range(n, i, -1):
        if lst[j] < lst[j - 1]:
            lst[j], lst[j - 1] = lst[j - 1], lst[j]
    print(' '.join(str(lst[k]) for k in range(1, n + 1)))
