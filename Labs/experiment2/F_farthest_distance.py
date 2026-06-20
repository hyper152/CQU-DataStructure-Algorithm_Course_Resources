n = int(input())
a = [0] + list(map(int, input().split()))
f = [a[i] * a[i] + i * i for i in range(1, n + 1)]
b = [a[i] * a[i] - i * i for i in range(1, n + 1)]
f.sort()
b.sort()
print(max(abs(f[0] - f[-1]), abs(b[0] - b[-1])))
