n = int(input())
lst = [0] + list(map(int, input().split()))

for i in range(2, n + 1):
    p, q = i, i - 1
    while q >= 1 and lst[p] <= lst[q]:
        lst[p], lst[q] = lst[q], lst[p]
        p, q = q, q - 1
    print(' '.join(str(lst[j]) for j in range(1, n + 1)))
