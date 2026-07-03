class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

# 根据带虚结点的先序序列递归建树
def build_tree(pre, index):
    """返回 (子树根节点, 下一个索引)"""
    if index >= len(pre) or pre[index] == '*':
        return None, index + 1
    
    root = TreeNode(pre[index])
    index += 1
    root.left, index = build_tree(pre, index)
    root.right, index = build_tree(pre, index)
    return root, index

# 判断是否为二叉排序树（中序遍历是否为严格递增序列）
def is_bst(root):
    prev = [None]  # 用列表存储前一个值（便于在递归中修改）
    
    def inorder(node):
        if node is None:
            return True
        # 左子树
        if not inorder(node.left):
            return False
        # 当前节点
        if prev[0] is not None and node.val <= prev[0]:
            return False
        prev[0] = node.val
        # 右子树
        return inorder(node.right)
    
    return inorder(root)

# 主程序
import sys

for line in sys.stdin:
    pre_str = line.strip()
    if not pre_str:
        continue
    root, _ = build_tree(pre_str, 0)
    if is_bst(root):
        print("YES")
    else:
        print("NO")