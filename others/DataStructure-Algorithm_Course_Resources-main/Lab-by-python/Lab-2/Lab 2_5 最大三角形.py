def find_biggest_perimeter_triangle(n, arr):
    """Find and print the triangle with the largest perimeter."""
    if n < 3:
        print("小棍的个数不能组成三角形")
    else:
        arr.sort(reverse=True)
        for i in range(n - 2):
            if arr[i] < arr[i + 1] + arr[i + 2]:
                perimeter = arr[i] + arr[i + 1] + arr[i + 2]
                print(f"最大三角形的周长是{perimeter}")
                print(f"组成最大三角形的三条边是{arr[i + 2]},{arr[i + 1]},{arr[i]}")
                return


def main():
    n = int(input().strip())
    arr = list(map(int, input().strip().split()))

    find_biggest_perimeter_triangle(n, arr)


if __name__ == "__main__":
    main()
