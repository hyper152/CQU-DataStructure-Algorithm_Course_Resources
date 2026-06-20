def solve():
    n = int(input())
    pro = {'<': 0, '(': 1, '[': 2, '{': 3}
    zu = {'>': '<', ')': '(', ']': '[', '}': '{'}
    for _ in range(n):
        f = input().strip()
        s = []
        ok = True
        for ch in f:
            if ch in pro:
                if s and pro[ch] > pro[s[-1]]:
                    ok = False
                    break
                s.append(ch)
            elif ch in zu:
                if not s or zu[ch] != s[-1]:
                    ok = False
                    break
                s.pop()
        print("YES" if ok and not s else "NO")

if __name__ == "__main__":
    solve()
