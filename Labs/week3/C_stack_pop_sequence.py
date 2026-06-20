in_str, out_str = input().strip().split()
sz = len(in_str)
stk = []
ans = ""
i = j = 0
flag = True

while True:
    if i == sz and j == sz:
        break
    if not stk:
        stk.append(in_str[i])
        ans += 'P'
        i += 1
    elif stk[-1] == out_str[j]:
        stk.pop()
        ans += 'O'
        j += 1
    else:
        if i == sz:
            flag = False
            break
        stk.append(in_str[i])
        ans += 'P'
        i += 1

if flag:
    print("right")
    print(ans)
else:
    print("wrong")
    print(''.join(stk))
