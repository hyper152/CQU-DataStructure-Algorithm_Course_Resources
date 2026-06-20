def gcd(a, b):
    if a < b:
        a, b = b, a
    if a % b == 0:
        return b
    return gcd(b, a % b)

n, k = map(int, input().split())
lst = [0] + list(map(int, input().split()))
g = 0
flag = False
for i in range(1, n + 1):
    if lst[i] - i == 0:
        continue
    if not flag:
        g = abs(lst[i] - i)
        flag = True
    else:
        g = gcd(g, abs(lst[i] - i))

for _ in range(k):
    tmp = int(input())
    print("YES" if g % tmp == 0 else "NO")
