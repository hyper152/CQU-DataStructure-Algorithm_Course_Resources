def solve():
    n = int(input())
    s1, s2 = [], []
    for _ in range(n):
        parts = input().strip().split()
        op = parts[0]
        if op == 'I':
            s1.append(int(parts[1]))
        else:
            if not s2:
                if not s1:
                    print("ERROR")
                else:
                    t = 0
                    while s1:
                        s2.append(s1.pop())
                        t += 2
                    t += 1
                    print(s2[-1], t)
                    s2.pop()
            else:
                print(s2[-1], 1)
                s2.pop()

solve()
