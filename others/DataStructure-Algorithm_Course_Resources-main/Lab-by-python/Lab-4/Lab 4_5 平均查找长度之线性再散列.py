def print_arr(arr):
    """Print array elements separated by spaces."""
    print(" ".join(str(x) for x in arr))


def main():
    n, m, p = map(int, input().strip().split())

    arr = [0] * m
    judge = [True] * m  # True means empty

    total_sum = 0
    for _ in range(n):
        num = int(input().strip())
        count = 1
        index = num % p
        if judge[index]:
            arr[index] = num
            total_sum += count
            judge[index] = False
        else:
            while not judge[index]:
                index = (index + 1) % m
                count += 1
            arr[index] = num
            total_sum += count
            judge[index] = False

    print(f"{total_sum}/{n}")

    sum1 = 0
    for i in range(p):
        count = 1
        j = i
        while not judge[j]:
            count += 1
            j = (j + 1) % m
        sum1 += count

    print(f"{sum1}/{p}")


if __name__ == "__main__":
    main()
