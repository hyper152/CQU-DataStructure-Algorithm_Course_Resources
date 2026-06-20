import sys
import heapq

def main() -> None:
    data = sys.stdin.buffer.read().split()
    if not data:
        return
    n = int(data[0])
    pq: list[int] = []
    for i in range(1, n + 1):
        heapq.heappush(pq, int(data[i]))

    wpl = 0
    while len(pq) > 1:
        a = heapq.heappop(pq)
        b = heapq.heappop(pq)
        wpl += a + b
        heapq.heappush(pq, a + b)

    sys.stdout.write(str(wpl))


if __name__ == "__main__":
    main()
