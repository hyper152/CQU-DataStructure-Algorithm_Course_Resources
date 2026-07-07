from collections import deque


def packaging_machine(n, m, s_max, tracks, operations):
    """Simulate the packaging machine process."""
    basket = []  # stack
    conveyor_belt = []

    for op in operations:
        if op == 0:
            if basket:
                conveyor_belt.append(basket.pop())
        else:
            track_index = op - 1
            if tracks[track_index]:
                if len(basket) < s_max:
                    basket.append(tracks[track_index].popleft())
                else:
                    conveyor_belt.append(basket.pop())
                    basket.append(tracks[track_index].popleft())

    return "".join(conveyor_belt)


def main():
    n, m, s_max = map(int, input().strip().split())

    tracks = [deque() for _ in range(n)]
    for i in range(n):
        line = input().strip()
        for ch in line[:m]:
            tracks[i].append(ch)

    operations = list(map(int, input().strip().split()))
    # Remove -1 sentinel if present
    if operations and operations[-1] == -1:
        operations.pop()

    result = packaging_machine(n, m, s_max, tracks, operations)
    print(result)


if __name__ == "__main__":
    main()
