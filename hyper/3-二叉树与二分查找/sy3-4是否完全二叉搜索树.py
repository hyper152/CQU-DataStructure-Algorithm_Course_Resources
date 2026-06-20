from collections import deque

class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None


def insert(root, val):
    """按题目规则插入：左子树键值大，右子树键值小"""
    if not root:
        return TreeNode(val)
    
    if val > root.val:
        root.left = insert(root.left, val)
    else:
        root.right = insert(root.right, val)
    
    return root


def level_order(root):
    """层序遍历，返回结果列表"""
    # 1️⃣ 空树判断
    if not root:
        return []           # 树为空，返回空列表
    
    # 2️⃣ 初始化队列，根节点入队
    q = deque([root])       # 创建双端队列，初始包含根节点
    result = []             # 存储遍历结果的列表
    
    # 3️⃣ 循环处理，直到队列为空
    while q:
        # 4️⃣ 弹出队首节点（先进先出）
        node = q.popleft()
        
        # 5️⃣ 访问当前节点，记录其值
        result.append(node.val)
        
        # 6️⃣ 将左子节点入队（如果存在）
        if node.left:
            q.append(node.left)
        
        # 7️⃣ 将右子节点入队（如果存在）
        if node.right:
            q.append(node.right)
    
    # 8️⃣ 返回遍历结果
    return result


def is_complete(root, n):
    """
    判断是否完全二叉树
    方法：给每个节点按层序编号（从1开始），
    如果遇到空节点之后还有非空节点，则不是完全二叉树
    """
    if not root:
        return True
    
    q = deque([(root, 1)])  # (节点, 编号)
    nodes = []  # 记录所有节点的编号
    
    while q:
        node, idx = q.popleft()
        nodes.append(idx)
        
        if node.left:
            q.append((node.left, 2 * idx))
        if node.right:
            q.append((node.right, 2 * idx + 1))
    
    # 完全二叉树：最后一个节点的编号 == 节点总数
    return len(nodes) == n and nodes[-1] == n


def main():
    n = int(input())
    values = list(map(int, input().split()))
    
    # 构建二叉搜索树（左大右小）
    root = None
    for val in values:
        root = insert(root, val)
    
    # 层序遍历
    order = level_order(root)
    print(' '.join(map(str, order)))
    
    # 判断是否完全二叉树
    if is_complete(root, n):
        print("YES")
    else:
        print("NO")


if __name__ == "__main__":
    main()