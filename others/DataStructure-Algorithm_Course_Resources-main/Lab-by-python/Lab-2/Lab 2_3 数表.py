def main():
    n = int(input().strip())
    arr = list(map(int, input().strip().split()))

    result = []
    for i in range(n):
        for j in range(i + 1, n):
            result.append(arr[i] + arr[j])

    result.sort()
    print(" ".join(str(x) for x in result))


if __name__ == "__main__":
    main()
