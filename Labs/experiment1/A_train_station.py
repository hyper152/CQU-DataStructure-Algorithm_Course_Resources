def solve():
    n = int(input())
    a = list(map(int, input().split()))
    st = []
    expected = 1
    count = 0
    for x in a:
        if x == expected:
            count += 1
            expected += 1
        else:
            st.append(x)
        while st and st[-1] == expected:
            st.pop()
            expected += 1
    while st and st[-1] == expected:
        st.pop()
        expected += 1
    if expected == n + 1:
        print("Yes")
        print(count)
    else:
        print("No")

T = int(input())
for _ in range(T):
    solve()
