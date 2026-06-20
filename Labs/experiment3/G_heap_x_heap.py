import sys
import heapq


def ksm(a: int, b: int) -> int:
    ans = 1
    while b:
        if b & 1:
            ans *= a
        a *= a
        b >>= 1
    return ans


class Node:
    def __init__(self, a: int, k: int, idx: int, d: int):
        self.a = a
        self.k = k
        self.idx = idx
        self.d = d

    def __lt__(self, other: "Node") -> bool:
        d = self.d
        if self.k >= other.k:
            lhs = self.a * ksm(d, self.k - other.k)
            if lhs == other.a:
                return self.idx > other.idx
            return lhs > other.a
        else:
            rhs = other.a * ksm(d, other.k - self.k)
            if self.a == rhs:
                return self.idx > other.idx
            return self.a > rhs


def main() -> None:
    data = sys.stdin.buffer.read().split()
    if not data:
        return
    it = iter(data)
    n = int(next(it))
    d = int(next(it))
    K = int(next(it))

    cnt = [0] * (n + 1)
    pq: list[Node] = []

    for i in range(1, n + 1):
        x = int(next(it))
        heapq.heappush(pq, Node(x, 0, i, d))

    # Single-step operations
    while K:
        nd = heapq.heappop(pq)
        nd.k += 1
        cnt[nd.idx] += 1
        heapq.heappush(pq, nd)
        K -= 1

    # Distribute remaining operations evenly
    lft = K % n
    base = K // n

    for _ in range(lft):
        nd = heapq.heappop(pq)
        cnt[nd.idx] += base + 1

    while pq:
        nd = heapq.heappop(pq)
        cnt[nd.idx] += base

    out = " ".join(str(cnt[i]) for i in range(1, n + 1))
    sys.stdout.write(out)


if __name__ == "__main__":
    main()
