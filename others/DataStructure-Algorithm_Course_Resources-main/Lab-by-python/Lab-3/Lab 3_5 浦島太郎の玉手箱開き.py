import heapq


def calculate_averages(n, numbers):
    """Calculate running averages based on min, max, and median."""
    max_heap = []  # Max-heap for lower half (store negative values)
    min_heap = []  # Min-heap for upper half

    averages = []

    current_min = numbers[0]
    current_max = numbers[0]

    for number in numbers:
        current_min = min(current_min, number)
        current_max = max(current_max, number)

        if not max_heap or number <= -max_heap[0]:
            heapq.heappush(max_heap, -number)
        else:
            heapq.heappush(min_heap, number)

        # Balance the heaps
        if len(max_heap) > len(min_heap) + 1:
            heapq.heappush(min_heap, -heapq.heappop(max_heap))
        elif len(min_heap) > len(max_heap):
            heapq.heappush(max_heap, -heapq.heappop(min_heap))

        # Calculate the average based on the number of elements
        if len(max_heap) == len(min_heap):
            # Even number of elements
            median1 = -max_heap[0]
            median2 = min_heap[0]
            average = (current_min + current_max + median1 + median2) // 4
        else:
            # Odd number of elements
            median = -max_heap[0]
            average = (current_min + current_max + median) // 3

        averages.append(average)

    return averages


def main():
    n = int(input().strip())
    numbers = list(map(int, input().strip().split()))

    averages = calculate_averages(n, numbers)
    print(" ".join(str(x) for x in averages))


if __name__ == "__main__":
    main()
