import sys
import heapq


def main() -> None:
    data = sys.stdin.buffer.read().split()
    if not data:
        return
    it = iter(data)
    n = int(next(it))
    m = int(next(it))
    k = int(next(it))

    intervals: list[tuple[int, int]] = []
    for _ in range(m):
        l = int(next(it))
        r = int(next(it))
        intervals.append((r, l))  # sort by r first

    intervals.sort()  # sort by r, then l
    intervals.append((n + 1, n + 1))  # sentinel

    ans = 0
    pre = 0
    pq: list[tuple[int, int]] = []  # max-heap via negative values

    i = 0
    while i < m:
        r, l = intervals[i]
        heapq.heappush(pq, (-l, -r))

        # Process all intervals with the same r
        while i + 1 < m and intervals[i + 1][0] == r:
            i += 1
            heapq.heappush(pq, (-intervals[i][1], -intervals[i][0]))

        next_r = intervals[i + 1][0]

        # Remove intervals that are "covered" or exceed limit
        while len(pq) > k or (pq and pre == -pq[0][0]):
            pre = -pq[0][0]
            heapq.heappop(pq)
            if not pq:
                break

        L = r - pre
        R = next_r - pre - 1
        ans += (L + R) * (next_r - r) // 2
        i += 1

    # Add initial segment contribution: 1 + 2 + ... + (a[1].r - 1)
    first_r = intervals[0][0]
    ans += first_r * (first_r - 1) // 2
    sys.stdout.write(str(ans))


if __name__ == "__main__":
    main()
