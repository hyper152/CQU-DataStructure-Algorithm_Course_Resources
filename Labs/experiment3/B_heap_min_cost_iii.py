import sys

def solve() -> None:
    data = sys.stdin.buffer.read().split()
    if not data:
        return
    it = iter(data)
    T = int(next(it))
    out_lines = []

    for _ in range(T):
        n = int(next(it)); m = int(next(it))

        a = [0] * (n + 2)
        b = [0] * (n + 3)
        for i in range(1, n + 1):
            a[i] = int(next(it))
        for i in range(1, n + 2):
            b[i] = int(next(it))

        a[1:n + 1] = sorted(a[1:n + 1], reverse=True)
        b[1:n + 2] = sorted(b[1:n + 2], reverse=True)

        def check(mid: int) -> bool:
            res = 0
            j = 1
            flag = False
            for i in range(1, n + 2):
                if flag:
                    res += a[j] * b[i]
                    j += 1
                elif mid > a[j]:
                    res += mid * b[i]
                    flag = True
                else:
                    res += a[j] * b[i]
                    j += 1
                if res >= m:
                    return True
            return False

        l, r = 0, 10 ** 9
        while l <= r:
            mid = (l + r) >> 1
            if check(mid):
                r = mid - 1
            else:
                l = mid + 1
        out_lines.append(str(l))

    sys.stdout.write("\n".join(out_lines))

if __name__ == "__main__":
    solve()
