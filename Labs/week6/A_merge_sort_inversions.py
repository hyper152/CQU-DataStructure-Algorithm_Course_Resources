cnt = 0

def merge_sort(arr, l, r):
    global cnt
    if l >= r:
        return
    mid = (l + r) // 2
    merge_sort(arr, l, mid)
    merge_sort(arr, mid + 1, r)
    temp = []
    i, j = l, mid + 1
    while i <= mid and j <= r:
        if arr[i] <= arr[j]:
            temp.append(arr[i])
            i += 1
        else:
            temp.append(arr[j])
            cnt += mid - i + 1
            j += 1
    while i <= mid:
        temp.append(arr[i])
        i += 1
    while j <= r:
        temp.append(arr[j])
        j += 1
    for k in range(len(temp)):
        arr[l + k] = temp[k]

n = int(input())
arr = list(map(int, input().split()))
merge_sort(arr, 0, n - 1)
print(f"count = {cnt}")
print(' '.join(map(str, arr)))
