n = int(input())
a = list(map(int, input().split()))
b = [0] * (n + 1)
for i in range(n - 1, -1, -1):
    b[i] = max(a[i], b[i + 1])

st = []
for i in range(n):
    st.append(a[i])
    while st and st[-1] > b[i + 1]:
        print(st.pop(), end=" ")
print()
