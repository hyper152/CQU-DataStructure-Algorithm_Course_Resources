def is_valid(s: str) -> str:
    """Check if the bracket sequence is valid."""
    stack = []
    mapping = {')': '(', ']': '['}

    for char in s:
        if char in mapping:
            if not stack or stack[-1] != mapping[char]:
                return "Wrong"
            stack.pop()
        else:
            stack.append(char)

    return "OK" if not stack else "Wrong"


def main():
    s = input().strip()
    result = is_valid(s)
    print(result)


if __name__ == "__main__":
    main()
