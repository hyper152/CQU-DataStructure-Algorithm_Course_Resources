def solve():
    # 读取头节点地址和节点总数
    head_addr, n = input().split()
    n = int(n)
    
    # 使用二维数组存储节点 [地址, 键值, 下一地址]
    nodes = []
    addr_to_index = {}  # 地址到数组索引的映射
    
    # 读取所有节点
    for _ in range(n):
        addr, key, next_addr = input().split()
        key = int(key)
        # 将节点添加到二维数组
        index = len(nodes)
        nodes.append([addr, key, next_addr])
        addr_to_index[addr] = index
    
    # 存储去重后的链表和被删除的链表（存储节点在二维数组中的索引）
    kept_indices = []
    removed_indices = []
    seen = set()  # 记录已经出现过的绝对值
    
    # 遍历链表
    curr_addr = head_addr
    while curr_addr != '-1':
        curr_idx = addr_to_index[curr_addr]  # 获取当前节点在二维数组中的索引
        curr_node = nodes[curr_idx]
        abs_key = abs(curr_node[1])  # curr_node[1] 是键值
        
        if abs_key not in seen:
            # 第一次出现，保留
            seen.add(abs_key)
            kept_indices.append(curr_idx)
        else:
            # 重复出现，放入删除链表
            removed_indices.append(curr_idx)
        
        curr_addr = curr_node[2]  # curr_node[2] 是下一地址
    
    # 输出保留的链表
    for i in range(len(kept_indices)):
        node = nodes[kept_indices[i]]
        if i < len(kept_indices) - 1:
            next_node = nodes[kept_indices[i + 1]]
            print(f"{node[0]} {node[1]} {next_node[0]}")
        else:
            print(f"{node[0]} {node[1]} -1")
    
    # 输出被删除的链表
    for i in range(len(removed_indices)):
        node = nodes[removed_indices[i]]
        if i < len(removed_indices) - 1:
            next_node = nodes[removed_indices[i + 1]]
            print(f"{node[0]} {node[1]} {next_node[0]}")
        else:
            print(f"{node[0]} {node[1]} -1")

if __name__ == "__main__":
    solve()