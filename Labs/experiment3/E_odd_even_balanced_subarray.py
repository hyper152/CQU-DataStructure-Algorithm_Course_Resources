import sys

def solve() -> None:
    data = sys.stdin.buffer.read().split()
    if not data:
        return
    it = iter(data)
    T = int(next(it))
    out_lines = []

    for _ in range(T):
        n = int(next(it))
        first_occ: dict[int, int] = {0: 0}
        pre = 0
        ans = -1
        for i in range(1, n + 1):
            x = int(next(it))
            if x & 1:
                pre += 1
            else:
                pre -= 1
            if pre in first_occ:
                ans = max(ans, i - first_occ[pre])
            else:
                first_occ[pre] = i
        out_lines.append(str(ans))

    sys.stdout.write("\n".join(out_lines))


if __name__ == "__main__":
    solve()
