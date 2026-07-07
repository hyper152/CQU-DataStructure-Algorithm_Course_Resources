def can_exit(entry_sequence, exit_sequence):
    """Determine if the cars can exit in the given order."""
    stack = []
    entry_index = 0

    for car in exit_sequence:
        while not stack or stack[-1] != car:
            if entry_index >= len(entry_sequence):
                return "No"
            stack.append(entry_sequence[entry_index])
            entry_index += 1
        stack.pop()

    return "Yes"


def main():
    T = int(input().strip())
    results = []

    for _ in range(T):
        n = int(input().strip())
        cars = list(map(int, input().strip().split()))

        entry_sequence = cars[:n]
        exit_sequence = cars[n:]

        results.append(can_exit(entry_sequence, exit_sequence))

    for res in results:
        print(res)


if __name__ == "__main__":
    main()
