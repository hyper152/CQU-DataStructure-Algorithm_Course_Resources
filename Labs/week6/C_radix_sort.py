def get_digit(num, d):
    for _ in range(d):
        num //= 10
    return num % 10

def radix_sort(arr, max_digits):
    for d in range(max_digits):
        cnt = [0] * 10
        for x in arr:
            cnt[get_digit(x, d)] += 1
        for i in range(1, 10):
            cnt[i] += cnt[i - 1]
        tmp = [0] * len(arr)
        for i in range(len(arr) - 1, -1, -1):
            digit = get_digit(arr[i], d)
            cnt[digit] -= 1
            tmp[cnt[digit]] = arr[i]
        arr[:] = tmp
        print(' '.join(map(str, arr)))
        if d == 2:
            break

n = int(input())
arr = list(map(int, input().split()))
max_val = max(arr)
max_digits = len(str(max_val)) if max_val > 0 else 1
radix_sort(arr, max_digits)
