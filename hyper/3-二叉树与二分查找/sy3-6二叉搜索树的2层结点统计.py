class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def insert(root, val):
    """将值插入二叉搜索树（左子树 <= 根 < 右子树），迭代方式避免递归过深"""
    if root is None:
        return TreeNode(val)
    cur = root
    while True:
        if val <= cur.val:
            if cur.left is None:
                cur.left = TreeNode(val)
                break
            cur = cur.left
        else:
            if cur.right is None:
                cur.right = TreeNode(val)
                break
            cur = cur.right
    return root

def get_level_counts(root):
    """层序遍历，返回每层结点数的列表"""
    if root is None:
        return []
    
    level_counts = []
    queue = [root]
    
    while queue:
        level_counts.append(len(queue))  # 当前层的结点数
        next_level = []
        for node in queue:
            if node.left:
                next_level.append(node.left)
            if node.right:
                next_level.append(node.right)
        queue = next_level
    
    return level_counts

def main():
    n = int(input())
    nums = list(map(int, input().split()))
    
    # 构建二叉搜索树
    root = None
    for num in nums:
        root = insert(root, num)
    
    # 统计每层结点数
    level_counts = get_level_counts(root)
    
    # 最下面两层的结点总数
    if len(level_counts) <= 1:
        result = level_counts[0] if level_counts else 0  # 0层或1层
    else:
        result = level_counts[-1] + level_counts[-2]  # 最后两层
    
    print(result)

if __name__ == "__main__":
    main() 