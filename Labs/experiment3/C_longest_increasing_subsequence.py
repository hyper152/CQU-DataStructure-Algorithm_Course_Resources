import sys
import bisect

def main() -> None:
    data = sys.stdin.buffer.read().split()
    if not data:
        return
    n = int(data[0])
    s: list[int] = []
    for i in range(1, n + 1):
        num = int(data[i])
        idx = bisect.bisect_left(s, num)
        if idx < len(s):
            s.pop(idx)
        bisect.insort(s, num)
    sys.stdout.write(str(len(s)))

if __name__ == "__main__":
    main()
