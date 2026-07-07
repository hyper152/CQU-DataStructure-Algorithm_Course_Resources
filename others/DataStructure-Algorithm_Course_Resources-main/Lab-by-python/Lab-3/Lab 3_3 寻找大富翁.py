import heapq


def print_arr(arr):
    """Print array elements separated by spaces."""
    print(" ".join(str(x) for x in arr))


def main():
    n, m = map(int, input().strip().split())
    nums = list(map(int, input().strip().split()))

    # Use max heap (Python heap is min heap, so negate values)
    max_heap = [-num for num in nums]
    heapq.heapify(max_heap)

    arr = []
    for _ in range(m):
        if max_heap:
            arr.append(-heapq.heappop(max_heap))

    print_arr(arr)


if __name__ == "__main__":
    main()
