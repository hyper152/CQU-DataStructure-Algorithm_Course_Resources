def main():
    n = int(input().strip())
    storage = {}
    max_count = 0

    for _ in range(n):
        birth = input().strip()
        storage[birth] = storage.get(birth, 0) + 1
        if max_count < storage[birth]:
            max_count = storage[birth]

    print(max_count)

    max_dates = [date for date, count in storage.items() if count == max_count]
    max_dates.sort()

    for date in max_dates:
        print(date)


if __name__ == "__main__":
    main()
