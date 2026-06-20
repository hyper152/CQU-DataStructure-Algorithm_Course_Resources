class Student:
    def __init__(self, name, sid):
        self.name = name
        self.id = sid
        self.scores = {}
        self.total = 0

n, m = map(int, input().split())
students = {}
order = []

for _ in range(n):
    parts = input().strip().split()
    tname = parts[0]
    tid = parts[1]
    tsc = int(parts[2])
    tscore = int(parts[3])
    time_str = parts[4]
    tt1 = int(time_str[:2])
    tt2 = int(time_str[3:])
    if tt1 < 3:
        if tid not in students:
            students[tid] = Student(tname, tid)
            order.append(tid)
        stu = students[tid]
        old = stu.scores.get(tsc, 0)
        if tscore > old:
            stu.total += tscore - old
            stu.scores[tsc] = tscore

result = sorted(students.values(), key=lambda s: (-s.total, s.id))
for i in range(min(m, len(result))):
    print(result[i].name, result[i].id, result[i].total)
