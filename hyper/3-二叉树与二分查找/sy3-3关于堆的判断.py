def build_min_heap(values):
    """构建最小堆，返回堆数组和值到索引的映射"""
    heap = []
    for val in values:
        heap.append(val)
        # 上浮调整
        idx = len(heap) - 1
        while idx > 0:
            parent = (idx - 1) // 2
            if heap[idx] < heap[parent]:
                heap[idx], heap[parent] = heap[parent], heap[idx]
                idx = parent
            else:
                break
    
    # 建立值到索引的映射
    pos = {}
    for i, val in enumerate(heap):
        pos[val] = i
    
    return heap, pos


def main():
    # 读取输入
    n, m = map(int, input().split())
    values = list(map(int, input().split()))
    
    # 构建最小堆
    heap, pos = build_min_heap(values)
    
    # 处理每个命题
    for _ in range(m):
        line = input().strip()
        
        if "is the root" in line:
            # x is the root
            x = int(line.split()[0])
            if pos[x] == 0:
                print("T")
            else:
                print("F")
                
        elif "and" in line and "siblings" in line:
            # x and y are siblings
            parts = line.split()
            x = int(parts[0])
            y = int(parts[2])
            # 兄弟节点：父节点相同
            if (pos[x] - 1) // 2 == (pos[y] - 1) // 2:
                print("T")
            else:
                print("F")
                
        elif "is the parent of" in line:
            # x is the parent of y
            parts = line.split()
            x = int(parts[0])
            y = int(parts[5])
            # x是y的父 ⇔ x的索引 == y的父索引
            if pos[x] == (pos[y] - 1) // 2:
                print("T")
            else:
                print("F")
                
        elif "is a child of" in line:
            # x is a child of y
            parts = line.split()
            x = int(parts[0])
            y = int(parts[5])
            # x是y的子 ⇔ y的索引 == x的父索引
            if (pos[x] - 1) // 2 == pos[y]:
                print("T")
            else:
                print("F")


if __name__ == "__main__":
    main()