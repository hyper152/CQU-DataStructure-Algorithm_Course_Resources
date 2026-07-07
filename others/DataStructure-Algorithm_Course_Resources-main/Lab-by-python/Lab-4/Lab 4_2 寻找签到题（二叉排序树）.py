def find_sign_in_problem(n, colors):
    """Find the color that appears most frequently (case-insensitive)."""
    color_count = {}

    for color in colors:
        lower_color = color.lower()
        color_count[lower_color] = color_count.get(lower_color, 0) + 1

    max_count = 0
    sign_in_color = ""
    for color, count in color_count.items():
        if count > max_count or (count == max_count and color < sign_in_color):
            max_count = count
            sign_in_color = color

    return sign_in_color


def main():
    t = int(input().strip())
    for _ in range(t):
        n = int(input().strip())
        colors = [input().strip() for _ in range(n)]
        result = find_sign_in_problem(n, colors)
        print(result)


if __name__ == "__main__":
    main()
