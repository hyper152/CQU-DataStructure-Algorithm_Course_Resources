n = int(input())
items = []
for _ in range(n):
    w, v, c = map(int, input().split())
    items.append((w, v, c))

items.sort(key=lambda x: x[2] * x[0])  # sort by c_i * w_i ascending

suf = [0] * (n + 2)
for i in range(n, 0, -1):
    suf[i] = suf[i + 1] + items[i - 1][0]

ans = 0
for i in range(1, n + 1):
    w, v, c = items[i - 1]
    ans += v - c * suf[i + 1]
print(ans)
