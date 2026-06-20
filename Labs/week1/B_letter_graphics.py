n, m = map(int, input().split())
for i in range(n):
    print(''.join(chr(ord('A') + abs(i - j)) for j in range(m)))
