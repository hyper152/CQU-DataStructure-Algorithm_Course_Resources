import sys
import heapq

def solve() -> None:
    data = sys.stdin.buffer.read().split()
    if not data:
        return
    it = iter(data)
    n = int(next(it))
    m = int(next(it))
    Q = int(next(it))

    a = [0] * (n + 1)
    for i in range(1, n + 1):
        a[i] = int(next(it))

    q = [(False, 0)] * (n + 2)
    for _ in range(m):
        r = int(next(it))
        w = int(next(it))
        q[r] = (True, q[r][1] + w)

    pq: list[int] = []
    for i in range(1, n + 1):
        heapq.heappush(pq, a[i])
        if q[i][0]:
            t = heapq.heappop(pq)
            heapq.heappush(pq, t - q[i][1])

    ans = [0] * (n + 1)
    total = 0
    idx = 1
    while pq:
        t = heapq.heappop(pq)
        total += t
        ans[idx] = total
        idx += 1

    out_lines = [str(-ans[int(next(it))]) for _ in range(Q)]
    sys.stdout.write("\n".join(out_lines))

if __name__ == "__main__":
    solve()
