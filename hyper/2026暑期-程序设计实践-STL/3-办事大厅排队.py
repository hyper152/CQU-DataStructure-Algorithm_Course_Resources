from collections import deque

def main():
    N = int(input())
    queue = deque()
    
    for _ in range(N):
        command = input().strip()
        
        if command.startswith('in '):
            # in name
            name = command[3:]  # 去掉 "in " 前缀
            queue.append(name)
        elif command == 'out':
            if queue:
                queue.popleft()
        elif command == 'q':
            if queue:
                print(queue[0])
            else:
                print('NULL')

if __name__ == '__main__':
    main()