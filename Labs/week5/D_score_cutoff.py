import math

n, m = map(int, input().split())
students = []
for _ in range(n):
    sid, score = map(int, input().split())
    students.append((sid, score))

students.sort(key=lambda x: (-x[1], x[0]))

ans = math.floor(m * 1.5)
line_score = students[ans - 1][1]
while ans < n and students[ans][1] == line_score:
    ans += 1

print(line_score, ans)
for i in range(ans):
    print(students[i][0], students[i][1])
