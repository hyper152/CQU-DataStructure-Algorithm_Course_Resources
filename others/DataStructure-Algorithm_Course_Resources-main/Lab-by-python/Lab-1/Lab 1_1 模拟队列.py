from collections import deque


def main():
    M = int(input().strip())
    my_queue = deque()

    for _ in range(M):
        command = input().strip().split()
        cmd = command[0]

        if cmd == "push":
            value = command[1]
            my_queue.append(value)
        elif cmd == "pop":
            if my_queue:
                my_queue.popleft()
        elif cmd == "empty":
            print("YES" if not my_queue else "NO")
        elif cmd == "query":
            if my_queue:
                print(my_queue[0])
            else:
                print("Queue is empty, cannot query.")


if __name__ == "__main__":
    main()
