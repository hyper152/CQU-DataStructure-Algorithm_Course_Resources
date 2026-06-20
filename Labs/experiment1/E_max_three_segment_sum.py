def solve():
    n = int(input())
    a = [0] + list(map(int, input().split()))
    presum = [0] * (n + 2)
    mipresum = [0] * (n + 2)
    resl = [int(-1e18)] * (n + 2)
    sufsum = [0] * (n + 2)
    misufsum = [0] * (n + 2)
    resr = [int(-1e18)] * (n + 2)

    for i in range(1, n + 1):
        presum[i] = presum[i - 1] + a[i]
    for i in range(1, n + 1):
        mipresum[i] = min(mipresum[i - 1], presum[i])
    for i in range(1, n + 1):
        resl[i] = max(resl[i - 1], presum[i] - mipresum[i - 1])

    for i in range(n, 0, -1):
        sufsum[i] = sufsum[i + 1] + a[i]
    for i in range(n, 0, -1):
        misufsum[i] = min(misufsum[i + 1], sufsum[i])
    for i in range(n, 0, -1):
        resr[i] = max(resr[i + 1], sufsum[i] - misufsum[i + 1])

    ans = int(-1e18)
    for i in range(1, n + 1):
        if i - 2 < 1 or i + 2 > n:
            continue
        ans = max(ans, a[i] + resl[i - 2] + resr[i + 2])
    print(ans)

solve()
