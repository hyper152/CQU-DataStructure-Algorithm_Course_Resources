mod = 998244353

def gcd(a, b):
    if a < b:
        a, b = b, a
    if a % b == 0:
        return b
    return gcd(b, a % b)

def ksm(a, b):
    a %= mod
    res = 1
    while b:
        if b & 1:
            res = res * a % mod
        a = a * a % mod
        b >>= 1
    return res

def calc(a, b, c, d):
    if d < b:
        b, d = d, b
        a, c = c, a
    g = gcd(a, c)
    if g == 1:
        return 1
    return ksm(g, b) * calc(a // g, b, c, d - b) % mod

def solve():
    a, b, c, d = map(int, input().split())
    print(calc(a, b, c, d))

T = int(input())
for _ in range(T):
    solve()
