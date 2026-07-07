def main():
    n, k = map(int, input().strip().split())
    hash_map = {}

    for _ in range(n):
        ID, mile = input().strip().split()
        mile = int(mile)
        if mile < k:
            mile = k
        hash_map[ID] = hash_map.get(ID, 0) + mile

    m = int(input().strip())
    for _ in range(m):
        ID = input().strip()
        if ID in hash_map:
            print(hash_map[ID])
        else:
            print("No Info")


if __name__ == "__main__":
    main()
