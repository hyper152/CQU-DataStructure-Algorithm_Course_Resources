def solve():
    n = int(input())                     # 结点个数
    post = list(map(int, input().split()))  # 后序遍历序列

    tree = [0] * (n + 1)                 # 1-indexed 数组存储完全二叉树
    idx = 0                              # 后序序列指针

    def postorder_fill(i: int):
        """对下标 i 做后序遍历，从后序序列中取值填入 tree[i]"""
        nonlocal idx
        if i > n:
            return
        postorder_fill(2 * i)            # 递归左孩子
        postorder_fill(2 * i + 1)        # 递归右孩子
        tree[i] = post[idx]              # 后序当前位置赋给节点 i
        idx += 1

    postorder_fill(1)                    # 从根节点开始
    print(' '.join(map(str, tree[1:])))  # 按层序（下标顺序）输出

solve()