def solve():
    n, m = map(int, input().split())
    pairs = set()
    for _ in range(m):
        a, b = map(int, input().split())
        pairs.add((a, b))
    for i in range(2, n + 1):
        if (i - 1, i) not in pairs:
            print("No")
            return
    print("Yes")

T = int(input())
for _ in range(T):
    solve()
