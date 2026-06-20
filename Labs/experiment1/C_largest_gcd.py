def solve():
    n = int(input())
    p = n
    i = 2
    while i * i <= n:
        if n % i == 0:
            if i == 2:
                if n // i == 2:
                    i += 1
                    continue
                p = min(p, n // i)
            else:
                p = min(p, i)
                break
        i += 1
    print(n // p)

T = int(input())
for _ in range(T):
    solve()
