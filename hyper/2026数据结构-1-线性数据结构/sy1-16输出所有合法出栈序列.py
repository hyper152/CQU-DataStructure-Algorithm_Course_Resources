n, k = map(int, input().split())
s = input()

can_del = n - k          # 还能删除的字符数
stack = []

for ch in s:
    # 只要栈顶比当前字符大，且还有删除名额，就弹出
    while stack and stack[-1] > ch and can_del > 0:
        stack.pop()
        can_del -= 1
    stack.append(ch)

# 取前 k 个作为答案
result = ''.join(stack[:k])
print(result)