def bubble_sort(arr):
    """Perform bubble sort and print array state after first three passes."""
    n = len(arr)
    for i in range(n):
        for j in range(n - 1, i, -1):
            if arr[j] < arr[j - 1]:
                arr[j], arr[j - 1] = arr[j - 1], arr[j]
        if i < 3:
            print(" ".join(str(x) for x in arr))


def main():
    n = int(input().strip())
    arr = list(map(int, input().strip().split()))

    bubble_sort(arr)


if __name__ == "__main__":
    main()
