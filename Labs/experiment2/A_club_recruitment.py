n = int(input())
lst = []
for _ in range(n):
    x, y = map(int, input().split())
    lst.append((x, y))
lst.sort(key=lambda p: p[0] - p[1], reverse=True)
ans = sum(p[0] for p in lst[:n//2]) + sum(p[1] for p in lst[n//2:])
print(ans)
