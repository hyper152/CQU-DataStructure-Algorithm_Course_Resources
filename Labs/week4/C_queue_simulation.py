from collections import deque

n = int(input())
q = deque()
for _ in range(n):
    parts = input().strip().split()
    op = parts[0]
    if op == "push":
        q.append(int(parts[1]))
    elif op == "query":
        print(q[0])
    elif op == "empty":
        print("YES" if not q else "NO")
    elif op == "pop":
        q.popleft()
