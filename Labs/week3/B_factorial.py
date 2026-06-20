def fac(x):
    if x == 0:
        return 1
    return x * fac(x - 1)

n = int(input())
print(fac(n))
