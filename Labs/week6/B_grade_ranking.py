n = int(input())
students = []
for _ in range(n):
    sid, ch, math = map(int, input().split())
    students.append((sid, ch, math))

students.sort(key=lambda x: (-x[1], -x[2], x[0]))
for s in students:
    print(s[0])
