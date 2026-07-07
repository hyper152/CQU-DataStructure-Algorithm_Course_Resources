heap = []
position_map = {}


def up(idx):
    """Move element up in the heap to maintain heap property."""
    while idx > 1 and heap[idx] < heap[idx // 2]:
        heap[idx], heap[idx // 2] = heap[idx // 2], heap[idx]
        position_map[heap[idx]] = idx
        position_map[heap[idx // 2]] = idx // 2
        idx //= 2


def is_root(x):
    return position_map[x] == 1


def is_parent_of(x, y):
    return position_map[x] == position_map[y] // 2


def is_child_of(x, y):
    return position_map[y] == position_map[x] // 2


def are_siblings(x, y):
    return position_map[x] // 2 == position_map[y] // 2


def main():
    n, m = map(int, input().strip().split())
    global heap, position_map
    heap = [0] * (n + 1)
    nums = list(map(int, input().strip().split()))

    for i in range(1, n + 1):
        heap[i] = nums[i - 1]
        position_map[heap[i]] = i
        up(i)

    for _ in range(m):
        parts = input().strip().split()
        x = int(parts[0])
        rel = parts[1]

        if rel == "is":
            temp = parts[2]
            if temp == "the":
                temp2 = parts[3]
                if temp2 == "root":
                    print("T" if is_root(x) else "F")
                else:  # parent
                    y = int(parts[4])
                    print("T" if is_parent_of(x, y) else "F")
            else:  # "a" child
                y = int(parts[4])
                print("T" if is_child_of(x, y) else "F")
        else:  # "and"
            y = int(parts[2])
            print("T" if are_siblings(x, y) else "F")


if __name__ == "__main__":
    main()
