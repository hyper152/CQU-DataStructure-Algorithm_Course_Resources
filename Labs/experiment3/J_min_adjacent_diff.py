import sys

def main() -> None:
    data = sys.stdin.buffer.read().split()
    if not data:
        return
    n = int(data[0])
    mx = 0
    total = 0
    for i in range(1, n + 1):
        x = int(data[i])
        total += x
        if x > mx:
            mx = x
    if total - mx <= mx:
        sys.stdout.write(str(mx))
    else:
        sys.stdout.write(str((total + 1) // 2))


if __name__ == "__main__":
    main()
