def print_arr(arr):
    """Print the array elements separated by spaces."""
    print(" ".join(str(x) for x in arr))


def partition(arr, low, high):
    """Partition the array around a pivot."""
    pivot = arr[low]
    i = low + 1

    for j in range(low + 1, high + 1):
        if arr[j] < pivot:
            arr[i], arr[j] = arr[j], arr[i]
            i += 1
    arr[i - 1], arr[low] = arr[low], arr[i - 1]
    return i - 1


def quick_sort(arr, low, high):
    """Perform quick sort and print array after each partition."""
    if low < high:
        pi = partition(arr, low, high)

        print_arr(arr)

        quick_sort(arr, low, pi - 1)
        quick_sort(arr, pi + 1, high)


def main():
    n = int(input().strip())
    arr = list(map(int, input().strip().split()))

    quick_sort(arr, 0, n - 1)


if __name__ == "__main__":
    main()
