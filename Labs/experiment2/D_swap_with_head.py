n = int(input())
lst = [0] + list(map(int, input().split()))
vis = [False] * (n + 1)
ans = 0
for i in range(1, n + 1):
    if lst[i] == i or vis[i]:
        continue
    res = -1 if i == 1 else 1
    tmp = i
    while not vis[tmp]:
        res += 1
        vis[tmp] = True
        tmp = lst[tmp]
    ans += res
print(ans)
