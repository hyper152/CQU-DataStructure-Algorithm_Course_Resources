n = int(input())
lst = list(map(int, input().split()))
mx = -1
ans = 0
for i, v in enumerate(lst, 1):
    mx = max(mx, v)
    if mx == i:
        ans += 1
print(ans)
