n = int(input())
lst = [0] + list(map(int, input().split()))
vis = [False] * (n + 1)
cir = [0] * (n + 1)

for i in range(1, n + 1):
    if lst[i] == i or vis[i]:
        continue
    res = 0
    tmp = i
    while not vis[tmp]:
        res += 1
        vis[tmp] = True
        tmp = lst[tmp]
    cir[res] += 1

ans = 0
for i in range(5, n + 1):
    ans += i * cir[i] // 3
    if i % 3 == 2:
        cir[2] += cir[i]
ans += (cir[2] + 1) // 2 + cir[3] + cir[4]
print(ans)
