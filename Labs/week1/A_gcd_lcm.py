def gcd(x, y):
    if y == 0:
        return x
    return gcd(y, x % y)

n, m = map(int, input().split())
g = gcd(n, m)
print(g, n // g * m)
