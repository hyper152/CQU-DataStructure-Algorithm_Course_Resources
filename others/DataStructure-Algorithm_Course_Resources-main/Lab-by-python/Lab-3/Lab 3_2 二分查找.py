def print_arr(arr):
    """Print array elements separated by spaces."""
    print(" ".join(str(x) for x in arr))


def binary_search(arr, target):
    """Perform binary search and return 1-indexed position, or 0 if not found."""
    begin = 0
    end = len(arr) - 1
    while begin <= end:
        mid = begin + (end - begin) // 2
        if arr[mid] > target:
            end = mid - 1
        elif arr[mid] < target:
            begin = mid + 1
        else:
            return mid + 1
    return 0


def main():
    try:
        while True:
            n = int(input().strip())
            arr = list(map(int, input().strip().split()))
            arr.sort()
            print_arr(arr)

            m = int(input().strip())
            search_nums = list(map(int, input().strip().split()))
            res = [binary_search(arr, num) for num in search_nums]
            print_arr(res)
    except EOFError:
        pass


if __name__ == "__main__":
    main()
