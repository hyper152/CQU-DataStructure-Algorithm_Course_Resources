import sys

class Calculator:
    def __init__(self):
        self.opstk = []
        self.numstk = []
        self.pri = {'+': 1, '-': 1, '*': 2, '/': 2}
        self.ans1 = -1
        self.ans2 = -1
        self.opsz = 0
        self.numsz = 0
        self.flag = True
        self.ans = ""

    def cal(self, op):
        num2 = self.numstk.pop()
        num1 = self.numstk.pop()
        if op == '+':
            self.numstk.append(num1 + num2)
        elif op == '-':
            self.numstk.append(num1 - num2)
        elif op == '*':
            self.numstk.append(num1 * num2)
        elif op == '/':
            if num2 == 0:
                print(f"error:{num1}/{num2}")
                self.flag = False
                return
            self.numstk.append(num1 // num2)
        self.numsz -= 1

    def solve(self):
        data = sys.stdin.read()
        i = 0
        while i < len(data):
            c = data[i]
            if c.isspace():
                i += 1
                continue
            if c.isdigit():
                self.ans += c
            else:
                if self.ans:
                    self.numstk.append(int(self.ans))
                    self.numsz += 1
                    self.ans2 = max(self.ans2, self.numsz)
                    self.ans = ""
                if c == '(':
                    self.opstk.append(c)
                    self.opsz += 1
                    self.ans1 = max(self.ans1, self.opsz)
                elif c == ')':
                    while self.opstk[-1] != '(':
                        op = self.opstk.pop()
                        self.opsz -= 1
                        self.cal(op)
                        if not self.flag:
                            return
                    self.opstk.pop()
                    self.opsz -= 1
                else:
                    while (self.opstk and self.opstk[-1] != '('
                           and self.pri[self.opstk[-1]] >= self.pri[c]):
                        op = self.opstk.pop()
                        self.opsz -= 1
                        self.cal(op)
                        if not self.flag:
                            return
                    self.opstk.append(c)
                    self.opsz += 1
                    self.ans1 = max(self.ans1, self.opsz)
            i += 1
        if self.ans:
            self.numstk.append(int(self.ans))
            self.numsz += 1
            self.ans2 = max(self.ans2, self.numsz)
        while self.opstk:
            op = self.opstk.pop()
            self.opsz -= 1
            self.cal(op)
            if not self.flag:
                return

calc = Calculator()
calc.solve()
if calc.flag:
    print(calc.numstk[-1])
    print(calc.ans1, calc.ans2)
