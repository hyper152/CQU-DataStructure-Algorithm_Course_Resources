def merge(arr, l, m, r):
    """Merge two sorted subarrays and count the number of inversions."""
    count = 0
    i, j = l, m + 1
    temp = []

    while i <= m and j <= r:
        if arr[i] <= arr[j]:
            temp.append(arr[i])
            i += 1
        else:
            temp.append(arr[j])
            j += 1
            count += (m + 1 - i)

    while i <= m:
        temp.append(arr[i])
        i += 1
    while j <= r:
        temp.append(arr[j])
        j += 1

    for k in range(len(temp)):
        arr[l + k] = temp[k]

    return count


def merge_sort(arr, l, r):
    """Perform merge sort and count inversions."""
    if l < r:
        m = (l + r) // 2
        count = merge_sort(arr, l, m) + merge_sort(arr, m + 1, r)
        count += merge(arr, l, m, r)
        return count
    return 0


def main():
    t = int(input().strip())
    results = []

    for _ in range(t):
        n = int(input().strip())
        arr = list(map(int, input().strip().split()))
        results.append(merge_sort(arr, 0, n - 1))

    for i, res in enumerate(results):
        print(f"Scenario #{i + 1}:")
        print(res)
        print()


if __name__ == "__main__":
    main()
